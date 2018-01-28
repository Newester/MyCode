#include<linux/init.h>
#include<linux/module.h>

#include<linux/kernel.h>
#include<linux/cdev.h>//有关字符设备
#include<linux/fs.h>//有关文件系统
#include<linux/errno.h>//有关错误
#include<asm/current.h>//有关
#include<linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");

static int major = 0;
static int minor = 0;
const int count = 3;

const char DEVNAME[] =  "FirstCharDev";

static struct cdev *p1stcdev = NULL;

static int this_open(struct inode *inode,struct file *pfile)
{
    //get command and pid
    printk(KERN_INFO"[%s:pid = %d] %s:%s:%d\n",current->comm,current->pid,__FILE__,__func__,__LINE__);
    //get major and minor from inode
    printk(KERN_INFO"[major = %d,minor = %d] %s:%s:%d\n",imajor(inode),iminor(inode),__FILE__,__func__,__LINE__);
    return 0;
}
static int this_release(struct inode *inode,struct file *pfile)
{   
    printk(KERN_INFO"[%s:pid = %d] %s:%s:%d\n",current->comm,current->pid,__FILE__,__func__,__LINE__);
    printk(KERN_INFO"[major = %d,minor = %d] %s:%s:%d\n",imajor(inode),iminor(inode),__FILE__,__func__,__LINE__);
    return 0;
}
static ssize_t this_read(struct file *pfile,char __user *buf,size_t size,loff_t *offset)
{
    struct inode *inode = pfile->f_path.dentry->d_inode;
    printk(KERN_INFO"[%s:pid = %d] %s:%s:%d\n",current->comm,current->pid,__FILE__,__func__,__LINE__);
    printk(KERN_INFO"[major = %d,minor = %d] %s:%s:%d\n",imajor(inode),iminor(inode),__FILE__,__func__,__LINE__);
    return 0;
}

static ssize_t this_write(struct file *pfile,const char __user *buf,size_t size,loff_t *offset)
{
    struct inode *inode = pfile->f_path.dentry->d_inode;
    printk(KERN_INFO"[%s:pid = %d] %s:%s:%d\n",current->comm,current->pid,__FILE__,__func__,__LINE__);
    printk(KERN_INFO"[major = %d,minor = %d] %s:%s:%d\n",imajor(inode),iminor(inode),__FILE__,__func__,__LINE__);
    return 0;
}
static struct file_operations fops = 
{
    .owner = THIS_MODULE,
    .open = this_open,
    .release = this_release,
    .read = this_read,
    .write = this_write,
};

static int __init this_init(void)
{
    dev_t devnum;
    int ret;
    printk(KERN_INFO"[%s:pid = %d] %s:%s:%d\n",current->comm,current->pid,__FILE__,__func__,__LINE__);
    
    //1.alloc cdev obj
    p1stcdev = cdev_alloc();
    if(NULL == p1stcdev)
    {
        return -ENOMEM;
    }

    //2.init cdev obj
    cdev_init(p1stcdev,&fops);
    ret = alloc_chrdev_region(&devnum,minor,count,DEVNAME);
    if(0 != ret)
    {
        goto ERR_STEP0;
    }
    major = MAJOR(devnum);

    //3.register cdev obj
    ret = cdev_add(p1stcdev,devnum,count);
    if(0 != ret)
    {
        goto ERR_STEP1;
    }
    
    //4.tell me ok
    printk(KERN_INFO"## ok ## [%s:pid = %d] %s:%s:%d\n",current->comm,current->pid,__FILE__,__func__,__LINE__);
    return 0;

ERR_STEP1:
    unregister_chrdev_region(devnum,count);

ERR_STEP0:
    cdev_del(p1stcdev);

    printk(KERN_INFO"##fail##[%s:pid = %d] %s:%s:%d\n",current->comm,current ->pid,__FILE__,__func__,__LINE__);

    return ret;

}
static void __exit this_exit(void)
{
    printk(KERN_INFO"[%s:pid = %d] %s:%s:%d\n",current->comm,current ->pid,__FILE__,__func__,__LINE__);
    unregister_chrdev_region(MKDEV(major,minor),count);
    cdev_del(p1stcdev);
}
module_init(this_init);
module_exit(this_exit);

