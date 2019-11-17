/* 
   Get disk sector size and capacity
   How to Run: ./blkioctl /dev/hda
 */

#include <fcntl.h>
#include <linux/fs.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int SectorSize;
int nSectors;

int main(int argc, char* argv[])
{
  /* open a file descriptor to the device specified on the command line */
  int fd = open(argv[1], O_RDONLY);
  if (fd <= 0)
  {
	  printf("Cannot open the device\n");
          exit(1);
  }
  /* get the sector size */
  ioctl(fd, BLKSSZGET, &SectorSize);
  /* display sector size */
  printf("Sector Size %d\n", SectorSize);

  /* get the no. of sectors */
  ioctl(fd, BLKGETSIZE, &nSectors);
  /* display no. of sectors */
  printf("No. of Sectors %d\n", nSectors);

  /* close the file descriptor */
  close(fd);

  return 0;
}
