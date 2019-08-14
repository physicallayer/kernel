#include "fileio.h"

struct file* openFile(const char *path, int flags, int rights)
{
    struct file *filp = NULL;
    mm_segment_t oldfs;
    int err = 0;

    oldfs = get_fs();
    set_fs(get_ds());
    filp = filp_open(path, flags, rights);
    set_fs(oldfs);
    if (IS_ERR(filp)) {
        err = PTR_ERR(filp);
        return NULL;
    }

    return filp;
}

void closeFile(struct file* fileIn)
{
    filp_close(fileIn, NULL);
}

loff_t getWholeSize(const char *path)
{
    struct kstat stat;

    vfs_stat(path, &stat);

    return stat.size;
}

int readFile(struct file *fileIn, unsigned long long offset, unsigned char *data, unsigned int size)
{
    mm_segment_t oldfs;
    int ret;

    oldfs = get_fs();
    set_fs(get_ds());

    ret = kernel_read(fileIn, data, size, &offset);

    set_fs(oldfs);

    return ret;
}

int writeFile(struct file *fileIn, unsigned long long offset, unsigned char *data, unsigned int size)
{
    mm_segment_t oldfs;
    int ret;

    oldfs = get_fs();
    set_fs(get_ds());

    ret = kernel_write(fileIn, data, size, &offset);

    set_fs(oldfs);

    return ret;
}
