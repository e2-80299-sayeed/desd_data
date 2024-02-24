#include<stdio.h>
#include<unistd.h>

// Change directry Demo
int main()
{
    char buff[80];
    getcwd(buff,sizeof(buff));

    printf("Dir : %s \n",buff);

    int ret = chdir("/home/kiran/Desktop/OS-Demo");

    if(ret != 0)
    {
        perror("chdir()  fail");
    }

    getcwd(buff,sizeof(buff));

    printf("Dir : %s \n",buff);



    return 0;
}