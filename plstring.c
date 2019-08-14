#include "plstring.h"

int getLineCount(unsigned char* data, size_t size)
{
    int count = 0;

    for(int i = 0; i< (int)size; i++)
    {
        if(data[i] == 0x0A)
        {
            count++;
        }
    }

    return count;
}


char *getLine(unsigned char *data)
{
    for(int i = 0;;i++)
    {
        if(data == 0x0A || data == 0x00) break;
    }
}
