#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x5dd2f7b4, "module_layout" },
	{ 0xe53e100b, "cdev_del" },
	{ 0x1b1a880, "per_cpu__current_task" },
	{ 0xa6ddecf6, "kmalloc_caches" },
	{ 0x695858a9, "cdev_init" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x105e2727, "__tracepoint_kmalloc" },
	{ 0x45d11c43, "down_interruptible" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xffc7c184, "__init_waitqueue_head" },
	{ 0xb72397d5, "printk" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0xb4390f9a, "mcount" },
	{ 0x748caf40, "down" },
	{ 0xfda5d96e, "device_create" },
	{ 0xc52e419, "cdev_add" },
	{ 0xc92ef82b, "kmem_cache_alloc" },
	{ 0x4292364c, "schedule" },
	{ 0x642e54ac, "__wake_up" },
	{ 0x37a0cba, "kfree" },
	{ 0x33d92f9a, "prepare_to_wait" },
	{ 0x3f1899f1, "up" },
	{ 0xa8f3ff3d, "class_destroy" },
	{ 0x9ccb2622, "finish_wait" },
	{ 0xdecb46af, "__class_create" },
	{ 0xd6c963c, "copy_from_user" },
	{ 0x29537c9e, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "AFB135D8C4D7B4243BF6FB8");
