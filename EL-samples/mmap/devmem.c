/*
 * devmem.c - maps the NIC mmeory and reads the MAC addr
 */

# include <stdio.h>
# include <string.h>
# include <sys/mman.h>

int main (int argc, char **argv)
{
    FILE *fh;
    unsigned char *vid_addr;
    int i;

    fh = fopen ("/dev/mem", "r+");
    vid_addr = (short*) mmap (
        /* where to map to: don't mind */
        NULL,
        /* how many bytes ? */
        0x100,
        /* want to read and write */
        PROT_READ | PROT_WRITE,
        /* no copy on write */
        MAP_SHARED,
        /* handle to /dev/mem */
        fileno (fh),
        /* hopefully the Text-buffer :-)*/
        0xec109000);

    for (i = 0; i < 6; i++)
    {
	 printf("%02x ", vid_addr[i]);
    }
    printf("\n");

    munmap (/*(caddr_t)*/ vid_addr, 0x100);
    fclose (fh);
    return 0;
}

