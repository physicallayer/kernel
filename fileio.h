#pragma once

#include <linux/buffer_head.h>
#include <linux/fs.h>
#include <asm-generic/segment.h>
#include <asm-generic/uaccess.h>

struct file* openFile(const char *path, int flags, int rights);
void closeFile(struct file *fileIn);
loff_t getWholeSize(const char *path);
int readFile(struct file *fileIn, unsigned long long offset, unsigned char *data, unsigned int size);
int writeFile(struct file *fileIn, unsigned long long offset, unsigned char *data, unsigned int size);
