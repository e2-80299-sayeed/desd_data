// 1. Implement fast ﬁle copy program (assume max ﬁle size = 1 GB).
// step 1: open src ﬁle in rdonly mode.
// step 2: get size of src ﬁle (fstat() syscall)
// step 3: map src ﬁle contents to memory using mmap()
// step 4: create dest ﬁle in rdwr mode.
// step 5: make size of dest ﬁle, same as size of src ﬁle using ftruncate()
// step 6: map dest ﬁle contents to memory using mmap() -- MAP_SHARED.
// step 7: copy src ﬁle to dest ﬁle using memcpy()
// step 8: close src and dest ﬁles.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

int main(){

//char *src_file = "/home/sayeed/DESD/EOS/daily_practice/day20/src.txt";
//char *dst_file = "/home/sayeed/DESD/EOS/daily_practice/day20/dest.txt";

int fd1, fd2, i;
struct stat st;
char *ptr1, *ptr2;

char src_path[50];
char dest_path[50];

printf("Enter src file Path : ");
scanf("%s",src_path);

fd1 = open(src_path, O_RDONLY , 0400);
if(fd1 < 0)
{
    perror("open() failed !");
    _exit(1);
}

fstat(fd1, &st);
ptr1 = (char*)mmap(NULL, st.st_size, PROT_READ,MAP_SHARED,fd1,0);
for(i =0 ; i <st.st_size; i++)
    putchar(ptr1[i]);



printf("Enter src file Path : ");
scanf("%s",dest_path);

fd2 = open(dest_path,  O_RDWR |O_CREAT | O_TRUNC , 0777);
if(fd2 < 0)
{
    perror("open() failed !!");
    _exit(2);
}

ftruncate(fd2,st.st_size);

fstat(fd2, &st);
ptr2 = (char*)mmap(NULL, st.st_size, PROT_READ | PROT_WRITE,MAP_SHARED,fd2,0);
//for(i= 0; i < st.st_size; i++);
memcpy(ptr2, ptr1, st.st_size);

close(fd1);
close(fd2);

munmap(ptr1, st.st_size);
munmap(ptr2, st.st_size);
return 0;
}