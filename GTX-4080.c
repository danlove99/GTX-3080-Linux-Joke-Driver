#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dan Love");
MODULE_DESCRIPTION("A 100% legit Nvidia GTX-4080 driver");
MODULE_VERSION("0.01");


int Aopen(struct inode *pinode, struct file *pfile)
{
	return 0;
}
ssize_t Aread(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "You now get mad FPS");
	return 0;
}
ssize_t Awrite(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "You wrote on the graphics card! :(");
	return length;
}
int Aclose(struct inode *pinode, struct file *pfile)
{
	return 0;
}


struct file_operations Afile_operations  = {
	.owner = THIS_MODULE,
	.open = Aopen,
	.read = Aread,
	.write = Awrite,
	.release = Aclose

};

int Amodule_init(void)
{
	printk(KERN_ALERT " inside the %s function\n", __FUNCTION__);

	/* register with the kernel */
	register_chrdev(240/* Major Number */,
			"GTX 4080"/* name of the driver */,
			&Afile_operations/* file operations */);
	return 0;
}


void Amodule_exit(void)
{
	printk(KERN_ALERT "inside the %s function\n", __FUNCTION__);
/* unregister */
	unregister_chrdev(240, "GTX 4080");
}

module_init(Amodule_init);
module_exit(Amodule_exit);



