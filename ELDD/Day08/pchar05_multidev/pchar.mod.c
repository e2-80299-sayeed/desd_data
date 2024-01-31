#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x43d34239, "cdev_del" },
	{ 0x3e2bc4cf, "device_destroy" },
	{ 0x6a2dd7c, "class_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x30a80826, "__kfifo_from_user" },
	{ 0xa19b956, "__stack_chk_fail" },
	{ 0x4578f528, "__kfifo_to_user" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xeea3c1d8, "__class_create" },
	{ 0x6c333d48, "device_create" },
	{ 0x76cce6d6, "cdev_init" },
	{ 0xff0d65c6, "cdev_add" },
	{ 0x30bfc2c, "param_ops_int" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x453e7dc, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0A5F9F2310B0575D860B4BF");
