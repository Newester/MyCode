#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
int main(int argc,char *argv[])
{
    if(2 != argc)
    {
        printf("Usage:%s /dev/devfile\n",argv[0]);
        return -1;
    }

    int fd = open(argv[1],O_RDWR);
    if(0 > fd)
    {
        perror("open");
        return -1;
    }
    getchar();
    int ret = read(fd,0x321,0);
    printf("read:ret = %d.\n",ret);

    getchar();
    ret = write(fd,0x123,0);
    printf("write:ret = %d.\n",ret);

    getchar();
    close(fd);
    
    return 0;
}