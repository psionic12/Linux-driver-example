#include <linux/init.h>		/*	module_init(init_function);
module_exit(cleanup_function);
__init
__initdata
__exit
__exitdata
*/
#include <linux/kernel.h>	/*	int printk(const char * fmt, ...);	*/
#include <linux/module.h>	/*	MODULE_LICENSE()
THIS_MODULE
*/
#include <linux/types.h>	/*	dev_t
int MAJOR(dev_t dev);
int MINOR(dev_t dev);
dev_t MKDEV(unsigned int major, unsigned int minor);
*/
#include <linux/fs.h>		/*	int alloc_chrdev_region(dev_t *dev, unsigned int firstminor, unsigned int count, char *name);
int unregister_chrdev_region(dev_t, unsigned);
struct file_operations;
struct file;
struct inode;
*/
#include <linux/cdev.h>		/*	struct cdev {
struct kobject kobj;
struct module *owner;
const struct file_operations *ops;
struct list_head list;
dev_t dev;
unsigned int count
};
void cdev_init(struct cdev *dev, struct file_operations *fops);
int cdev_add(struct cdev *dev, dev_t num, unsigned int count);
void cdev_del(struct cdev *dev);
*/
#include <linux/slab.h>		/*	void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
*/
#include <asm/uaccess.h>	/*	unsigned long copy_from_user (void *to, const void *from, unsigned long count);
unsigned long copy_from_user (void *to, const void *from, unsigned long count);
*/
#include <asm/atomic.h>		/*	atomic_t v = ATOMIC_INIT(value);
void atomic_set(atomic_t *v, int i);
int atomic_read(atomic_t *v);
void atomic_add(int i, atomic_t *v);
void atomic_sub(int i, atomic_t *v);
void atomic_inc(atomic_t *v);
void atomic_dec(atomic_t *v);
int atomic_inc_and_test(atomic_t *v);
int atomic_dec_and_test(atomic_t *v);
int atomic_sub_and_test(int i, atomic_t *v);
int atomic_add_negative(int i, atomic_t *v);
int atomic_add_return(int i, atomic_t *v);
int atomic_sub_return(int i, atomic_t *v);
int atomic_inc_return(atomic_t *v);
int atomic_dec_return(atomic_t *v);
*/

#include <linux/spinlock.h>
/*spinlock_t lock = SPIN_LOCK_UNLOCKED;
spin_lock_init(spinlock_t *lock);
void spin_lock(spinlock_t *lock);
void spin_lock_irqsave(spinlock_t *lock, unsigned long flags);
void spin_lock_irq(spinlock_t *lock);
void spin_lock_bh(spinlock_t *lock);
*/

#include <linux/wait.h>
//typedef struct { /* ... */ } wait_queue_head_t;
/*
void init_waitqueue_head(wait_queue_head_t *queue);
DECLARE_WAIT_QUEUE_HEAD(queue);
void wait_event(wait_queue_head_t q, int condition);
int wait_event_interruptible(wait_queue_head_t q, int condition);
int wait_event_timeout(wait_queue_head_t q, int condition, int time);
int wait_event_interruptible_timeout(wait_queue_head_t q, int condition,
int time);
void wake_up(struct wait_queue **q);
void wake_up_interruptible(struct wait_queue **q);
void wake_up_nr(struct wait_queue **q, int nr);
void wake_up_interruptible_nr(struct wait_queue **q, int nr);
void wake_up_all(struct wait_queue **q);
void wake_up_interruptible_all(struct wait_queue **q);
void wake_up_interruptible_sync(struct wait_queue **q);
*/
#include <linux/sched.h>/*
set_current_state(int state);
Sets the execution state of the current process. TASK_RUNNING means it is ready to run, while the sleep states are TASK_INTERRUPTIBLE and TASK_UNINTERRUPTIBLE.
void schedule(void);*/
//typedef struct { /* ... */ } wait_queue_t;
/*init_waitqueue_entry(wait_queue_t *entry, struct task_struct *task);
void prepare_to_wait(wait_queue_head_t *queue, wait_queue_t *wait, int state);
void prepare_to_wait_exclusive(wait_queue_head_t *queue, wait_queue_t *wait,
  int state);
void finish_wait(wait_queue_head_t *queue, wait_queue_t *wait);
void sleep_on(wiat_queue_head_t *queue);
void interruptible_sleep_on(wiat_queue_head_t *queue);*/