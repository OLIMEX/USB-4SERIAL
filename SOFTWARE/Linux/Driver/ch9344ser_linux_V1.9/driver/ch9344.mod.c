#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
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
__used __section(__versions) = {
	{ 0xb3753869, "module_layout" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x6b7ba003, "usb_deregister" },
	{ 0xc5850110, "printk" },
	{ 0xb15d9545, "put_tty_driver" },
	{ 0xc517b67c, "tty_unregister_driver" },
	{ 0xbf671e22, "usb_register_driver" },
	{ 0x400afb16, "tty_register_driver" },
	{ 0xa58bb6d7, "tty_set_operations" },
	{ 0x67b27ec1, "tty_std_termios" },
	{ 0xd338102d, "__tty_alloc_driver" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0x409873e3, "tty_termios_baud_rate" },
	{ 0x6c257ac0, "tty_termios_hw_change" },
	{ 0xc2ab3f1, "tty_port_register_device" },
	{ 0xb7b60a05, "usb_get_intf" },
	{ 0x7e21ce69, "usb_driver_claim_interface" },
	{ 0xf8b2b7f9, "tty_port_init" },
	{ 0x34ac35f4, "usb_alloc_urb" },
	{ 0xf98013c3, "usb_alloc_coherent" },
	{ 0x977f511b, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xf9ee9a0e, "usb_ifnum_to_if" },
	{ 0xabd515b2, "tty_port_tty_hangup" },
	{ 0xdbf17652, "_raw_spin_lock" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x36e58bcd, "pv_ops" },
	{ 0x47941711, "_raw_spin_lock_irq" },
	{ 0x5f991b71, "tty_port_close" },
	{ 0x1f3cac19, "usb_control_msg" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0xb44ad4b3, "_copy_to_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x14c216dd, "usb_autopm_get_interface" },
	{ 0x6d334118, "__get_user_8" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0xfb578fc5, "memset" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x289dd663, "tty_flip_buffer_push" },
	{ 0xab2675ab, "tty_insert_flip_string_fixed_flag" },
	{ 0x165b145c, "ex_handler_refcount" },
	{ 0xe3cfbafa, "tty_standard_install" },
	{ 0x20978fb9, "idr_find" },
	{ 0x8cf61076, "tty_port_open" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3b63bdd1, "usb_anchor_urb" },
	{ 0x6567c9fa, "usb_autopm_get_interface_async" },
	{ 0x5aabf520, "tty_port_hangup" },
	{ 0x6084951e, "usb_put_intf" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xac44ebde, "tty_port_tty_wakeup" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x9409627e, "_dev_info" },
	{ 0x95ce4544, "usb_driver_release_interface" },
	{ 0xc9d8c16a, "usb_free_urb" },
	{ 0x7d4fc6c0, "tty_unregister_device" },
	{ 0xd0484dee, "tty_kref_put" },
	{ 0x22d5b8cb, "tty_vhangup" },
	{ 0xb30f75b0, "tty_port_tty_get" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x2ab7989d, "mutex_lock" },
	{ 0xdab18fa5, "tty_port_put" },
	{ 0xc141228b, "usb_free_coherent" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xfb40661a, "usb_kill_urb" },
	{ 0x7ea9032d, "usb_get_from_anchor" },
	{ 0xe45d60d, "usb_autopm_put_interface" },
	{ 0x54fc986e, "usb_autopm_get_interface_no_resume" },
	{ 0xff73952a, "usb_autopm_put_interface_async" },
	{ 0x43089b53, "usb_submit_urb" },
	{ 0x37a0cba, "kfree" },
	{ 0xf5cb25c8, "kmem_cache_alloc_trace" },
	{ 0x35216b26, "kmalloc_caches" },
	{ 0xe6257e29, "_dev_err" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x4913dc6e, "usb_bulk_msg" },
	{ 0x3812050a, "_raw_spin_unlock_irqrestore" },
	{ 0x51760917, "_raw_spin_lock_irqsave" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("usb:v1A86pE018d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1A86p55D9d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "A6E2AA72B5EC5A930B399FA");
