#pragma once

#include <linux/types.h>

int getLineCount(unsigned char* data, size_t size);
char* getLine(unsigned char* data);
