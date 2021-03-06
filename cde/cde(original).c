#include <linux/init.h>		
#include <linux/kernel.h>	
#include <linux/module.h>	
#include <linux/types.h>	
#include <linux/fs.h>		
#include <linux/cdev.h>		
#include <linux/slab.h>		
#include <asm/uaccess.h>	
#define CDE_SIZE 0x1000		

MODULE_LICENSE("Dual BSD/GPL");

static int major_number = 0;	

struct cde_dev
{
	struct cdev cdev;
	unsigned char mem[CDE_SIZE];
};
struct cde_dev *cdep;


int open(struct inode *inode, struct file *filp)
{
	filp->private_data = cdep;
	printk(KERN_ALERT "opened successly");
	return 0;
}
int release(struct inode *inode, struct file *filp)
{
	return 0;
}
static ssize_t write(struct file *filp, const char __user *buf, size_t size, loff_t *ppos)
{
	unsigned long p = *ppos;
	unsigned int count = size;
	int ret = 0;
	struct cde_dev *cdep = filp->private_data;
	if(p >= CDE_SIZE)
		return count ? -ENXIO: 0;
	if (count > CDE_SIZE - p)	
	{
		count = CDE_SIZE - p;
	}
	if (copy_from_user(cdep->mem +p, buf, count))
		ret = - EFAULT;
	else
	{
		*ppos += count;
		ret = count;
		printk(KERN_ALERT "written %u bytes from %lu\n",count,p);
	}
	return ret;
	
}
static ssize_t read(struct file *filp, char __user *buf,size_t size, loff_t *ppos)
{
	
	unsigned long p = *ppos;
	unsigned int count = size;
	int ret = 0;
	struct cde_dev *cdep = filp->private_data;
	if (p >= CDE_SIZE)
		return count ? - ENXIO: 0;
	if (count > CDE_SIZE -p)
		count = CDE_SIZE -p;
	if (copy_to_user(buf,(void*)(cdep->mem + p), count))
	{
		ret = - EFAULT;
	}
	else 
	{
		*ppos += count;
		ret = count;
		printk (KERN_ALERT "read %u bytes from %lu\n",count,p);
	}
	return ret;
}



static const struct file_operations cde_fops =
{
	.owner = THIS_MODULE,
	.read = read,
	.write = write,
	.open = open,
	.release = release,
};
static void	setup_cdev(struct cde_dev *cdep)
{
	int err,devno = MKDEV(major_number, 0);
	cdev_init(&cdep->cdev, &cde_fops);
	cdep->cdev.owner = THIS_MODULE;
	cdep->cdev.ops = &cde_fops;
	err = cdev_add(&cdep->cdev, devno, 1);
	if (err)
	{
		printk(KERN_ALERT "Error %d adding",err);
	}
	printk(KERN_ALERT "major %d\n",major_number);
}

static int cde_init(void)
{
	int result;
	dev_t devno;
	result = alloc_chrdev_region(&devno, 0, 1, "char driver example");
	major_number = MAJOR(devno);
	if (result < 0)	
	{
		return result;
	}
	cdep = kmalloc(sizeof(struct cde_dev),GFP_KERNEL);
	if (!cdep)
	{
		result =  - ENOMEM;
		goto fail_malloc;
	}
	memset(cdep, 0, sizeof(struct cde_dev));   //strange, memset() is a user space funtion.
	setup_cdev(cdep);
	return 0;

	fail_malloc: unregister_chrdev_region(devno, 1);
	return result;
}

static void cde_exit(void)
{
	cdev_del(&cdep->cdev);
	kfree(cdep);
	unregister_chrdev_region(MKDEV(major_number, 0),1);
	printk(KERN_ALERT "exit");
}
module_init(cde_init);
module_exit(cde_exit);
