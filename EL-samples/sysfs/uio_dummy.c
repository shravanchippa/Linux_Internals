/*
 * sysfs interface - uio_dummy.c 
 */

#include <linux/platform_device.h>
#include <linux/module.h>

static long freq;

static long uio_dummy_count;

static ssize_t show_count(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	return sprintf(buf, "%ld\n", uio_dummy_count);
}

static ssize_t store_count(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	uio_dummy_count = simple_strtol(buf, NULL, 10);
	return count;
}
static DEVICE_ATTR(count, S_IRUGO|S_IWUSR|S_IWGRP, show_count, store_count);

static ssize_t show_freq(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	return sprintf(buf, "%ld\n", freq);
}

static ssize_t store_freq(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	long tmp = simple_strtol(buf, NULL, 10);
	if (tmp < 1)
		tmp = 1;
	freq = tmp;
	return count;
}

static DEVICE_ATTR(freq, S_IRUGO|S_IWUSR|S_IWGRP, show_freq, store_freq);

static int uio_dummy_probe(struct device *dev)
{
	int ret;

	freq = HZ;

	ret = device_create_file(dev, &dev_attr_count);
	if (ret)
		goto error_register;
	ret = device_create_file(dev, &dev_attr_freq);
	if (ret)
		goto error_file_count;

	return 0;

error_file_count:
	device_remove_file(dev, &dev_attr_count);
error_register:
	return ret;
}

static int uio_dummy_remove(struct device *dev)
{
	device_remove_file(dev, &dev_attr_freq);
	device_remove_file(dev, &dev_attr_count);
	return 0;
}

static void uio_dummy_shutdown(struct device *dev)
{

}

static struct platform_device *uio_dummy_device;

static struct device_driver uio_dummy_driver = {
	.name		= "uio_dummy",
	.bus		= &platform_bus_type,
	.probe		= uio_dummy_probe,
	.remove		= uio_dummy_remove,
	.shutdown	= uio_dummy_shutdown,
};

/*
 * Main initialization/remove routines
 */
static int __init uio_dummy_init(void)
{
	printk("uio_dummy_init( )\n" );
	uio_dummy_device = platform_device_register_simple("uio_dummy", -1,
							   NULL, 0);
//	if (IS_ERR(uio_dummy_device))
//		return PTR_ERR(uio_dummy_device);

	return driver_register(&uio_dummy_driver);
}

static void __exit uio_dummy_exit(void)
{
	platform_device_unregister(uio_dummy_device);
	driver_unregister(&uio_dummy_driver);
}

module_init(uio_dummy_init);
module_exit(uio_dummy_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("B R Sahu");
MODULE_DESCRIPTION("UIO dummy driver");

