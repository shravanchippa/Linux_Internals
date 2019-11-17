#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define DIRECTORY_NAME  "park"
#define FILE_NAME       "rw_counter"

static struct proc_dir_entry *park_dir, *counter_file;

void myatoi(char *);

int counter=1;

static int proc_read_counter(char *page, char **start, off_t off, int count, int *eof, void *data)
{
        int len;

        if(off > 0) return 0;

        len = sprintf(page, "Counter = %d\n", counter++);

        return len;

}

static int proc_write_counter(struct file *file, const char *buffer, unsigned long count, void *data)
{
        int len;
        char inbuf[10];

        if(count > 8) len = 8;
        else len = count;

        if(copy_from_user(inbuf, buffer, len))
        {
                return -EFAULT;
        }
        inbuf[len] =  '\0' ;

        myatoi(inbuf);

        return len;
}

int init_module(void)
{
        int sts = 0; /* create directory */

        park_dir = proc_mkdir(DIRECTORY_NAME, NULL);
        if(park_dir == NULL)
        {
                printk("ERROR Creating Directory\n");
                sts = -1;
                goto exit_dir;
        }
        park_dir->owner = THIS_MODULE;

        counter_file = create_proc_entry(FILE_NAME, 0644, park_dir);
        if(counter_file == NULL)
        {        sts = -1;
                 goto exit_file;
        }
        counter_file->read_proc = proc_read_counter;
        counter_file->write_proc = proc_write_counter;
        counter_file->owner = THIS_MODULE;

        return 0;

exit_file: remove_proc_entry(DIRECTORY_NAME, NULL);

exit_dir: return sts;

}

void cleanup_module(void)
{
        remove_proc_entry(FILE_NAME, park_dir);
        remove_proc_entry(DIRECTORY_NAME, NULL);
}



void myatoi(char *inbuf)
{
        int i=0, temp=0;

        while(i <= 8)
        {
                if(inbuf[i] == '\0'){
                        counter = temp;
                        return;
                }

                if( (inbuf[i] == ' ') || (inbuf[i] == '\t') || (inbuf[i] == '\n') ){
                        i++;
                        continue;
                }

                if( (inbuf[i] < '0') || (inbuf[i] > '9') ) return;

                temp =  temp*10 + inbuf[i] - '0';
                i++;
        }

}

