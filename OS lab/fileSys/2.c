// Write a program to print out the complete stat structure of a file.
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<dirent.h>
#include<string.h>
char* formatdate(char* str, time_t val)
{
 strftime(str, 36, "%d.%m.%Y %H:%M:%S", localtime(&val));
 return str;
}
int main(int argc, char *argv[])
{
 struct stat sb;
 int ret;
 char date[36];
 ret = stat(argv[1], &sb);
 printf("ID of device - %d\n", sb.st_dev);
 printf("INO Number is - %llu\n", sb.st_ino);
 printf("File mode - %hu\n", sb.st_mode);
 printf("Number of hard links - %d\n", sb.st_nlink);
 printf("User ID - %d\n", sb.st_uid);
 printf("Group owner - %d\n", sb.st_gid);
 printf("File size - %lld\n", sb.st_size);
 printf("Blocksize - %d\n", sb.st_blksize);
 printf("Number of Blocks - %lld\n", sb.st_blocks);
 printf("Last access time - %s\n", formatdate(date,sb.st_atime));
 printf("Last modification time - %s\n", formatdate(date,sb.st_mtime));
 printf("Last change time - %s\n", formatdate(date,sb.st_ctime));
 
 printf("Permissions\t");
struct stat statbuf;
stat(argv[1],&statbuf);

 printf( (statbuf.st_mode & S_IRUSR) ? "r" : "-");
 printf( (statbuf.st_mode & S_IWUSR) ? "w" : "-");
 printf( (statbuf.st_mode & S_IXUSR) ? "x" : "-");
 printf( (statbuf.st_mode & S_IRGRP) ? "r" : "-");
 printf( (statbuf.st_mode & S_IWGRP) ? "w" : "-");
 printf( (statbuf.st_mode & S_IXGRP) ? "x" : "-");
 printf( (statbuf.st_mode & S_IROTH) ? "r" : "-");
 printf( (statbuf.st_mode & S_IWOTH) ? "w" : "-");
 printf( (statbuf.st_mode & S_IXOTH) ? "x" : "-");
 printf("\n\n");


 }