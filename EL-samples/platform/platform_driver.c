/*
 * Linux platform driver example
*/

#include <linux/device.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>

#define PLATFORM_DEVICE_NAME    "platform_example"

static int value;
module_param(value, int, S_IRUGO);
MODULE_PARM_DESC(value, "Value to pass as platform data");

struct platform_example_data {
        int value;
};
struct platform_device *pdev;

static int __devinit platform_example_probe(struct platform_device *pdev)
{
	struct platform_example_data *pdata = pdev->dev.platform_data;

	/* Add per-device initialization code here */

	dev_notice(&pdev->dev, "probe() called, value: %d\n",
			pdata ? pdata->value : -1);

	return 0;
}

static int __devexit platform_example_remove(struct platform_device *pdev)
{
	/* Add per-device cleanup code here */

	dev_notice(&pdev->dev, "remove() called\n");

	return 0;
}

#ifdef CONFIG_PM
static int
platform_example_suspend(struct platform_device *pdev, pm_message_t state)
{
	/* Add code to suspend the device here */

	dev_notice(&pdev->dev, "suspend() called\n");

	return 0;
}

static int platform_example_resume(struct platform_device *pdev)
{
	/* Add code to resume the device here */

	dev_notice(&pdev->dev, "resume() called\n");

	return 0;
}
#else
/* No need to do suspend/resume if power management is disabled */
# define platform_example_suspend	NULL
# define platform_example_resume	NULL
#endif

static struct platform_driver platform_example_driver = {
	.probe		= platform_example_probe,
	.remove		= __devexit_p(platform_example_remove),
	.suspend	= platform_example_suspend,
	.resume		= platform_example_resume,
	.driver	= {
		.name	= "platform_example",
	},
};

static int __init platform_example_init(void)
{
	struct platform_example_data data;
	int ret;

        /*
         * Initialize platform data.
        */
        data.value = value;

	pdev = platform_device_alloc(PLATFORM_DEVICE_NAME,
                                                    0);
        if (pdev == NULL)
        {
		return -1;
	}
        /*
         * The data is copied into a new dynamically allocated
         * structure, so it's ok to pass variables defined on
         * the stack here.
        */
        ret = platform_device_add_data(pdev, &data, sizeof(data));
        if (ret)
        {
		platform_device_put(pdev);
		return -1;
	}

	ret = platform_device_add(pdev);
        if (ret)
        {
		platform_device_put(pdev);
		return -1;
	}

	return platform_driver_register(&platform_example_driver);
}
module_init(platform_example_init);

static void __exit platform_example_exit(void)
{
	platform_driver_unregister(&platform_example_driver);
        platform_device_del(pdev);
}
module_exit(platform_example_exit);

/* Information about this module */
MODULE_DESCRIPTION("Platform driver example");
MODULE_AUTHOR("Byas Ram Sahu");
MODULE_LICENSE("GPL");

