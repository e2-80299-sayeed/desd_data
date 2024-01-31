#ifndef __PCHAR_H
#define __PCHAR_H

#include <linux/ioctl.h>

typedef struct {
    short size;
    short len;
    short avail;
}info_t;

#define FIFO_CLEAR _IO('x', 1)
#define FIFO_GET_INFO _IOR('x', 2, info_t*)
#define FIFO_RESIZE _IOW('x', 3, long)

#endif