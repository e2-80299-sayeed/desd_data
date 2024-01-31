#ifndef __PCHAR_H
#define __PCHAR_H

#include <linux/ioctl.h>

typedef struct {
    short size;     // kfifo size
    short len;      // kfifo len (filled)
    short avail;    // kfifo avail (empty)
}info_t;

#define FIFO_CLEAR      _IO('x', 1)
#define FIFO_GET_INFO   _IOR('x', 2, info_t*) 

#endif

