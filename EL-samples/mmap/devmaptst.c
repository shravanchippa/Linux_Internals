/*
 * devmaptst.c - maps the NIC mmeory and reads the MAC addr
 */

# include <stdio.h>
# include <string.h>
# include <sys/mman.h>

int main (int argc, char **argv)
{
    int fd;
    unsigned char *dev_addr;
    int i;

    fd = open ("/dev/mydevice", 0666);
    if (fd <= 0)
    {
	printf("device not found\n");
	exit(1);
    }

    dev_addr = (short*) mmap (
        /* where to map to: don't mind */
        NULL,
        /* how many bytes ? */
        0x100,
        /* want to read and write */
        PROT_READ | PROT_WRITE,
        /* no copy on write */
        MAP_SHARED,
        /* handle to /dev/mem */
        fd,
        /* hopefully the Text-buffer :-)*/
        0xec109000);

    if (dev_addr != NULL)
    {
        for (i = 0; i < 6; i++)
        {
 	     printf("%02x ", dev_addr[i]);
        }
        printf("\n");

        munmap (/*(caddr_t)*/ dev_addr, 0x100);
    }
    close (fd);
    return 0;
}

