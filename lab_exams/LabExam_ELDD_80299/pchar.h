#ifndef __PCHAR_H
#define __PCHAR_H

#include <linux/ioctl.h>

typedef struct info{
    char type[10];
    int buf_len;
    char device[10];
    struct list_head list;
}info_t;

#define FIFO_GET_INFO _IOR('x', 2, info_t*)


#endif