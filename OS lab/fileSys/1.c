/*Write a program to find the inode number of an existing file in a directory. Take the input as 
a filename and print the inode number of the file.*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main (int argc, char *argv[])
{
 struct stat sb;
 int ret;
 
 ret = stat (argv[1], &sb);
 
 printf ("Inode number for %s is: %ld ", argv[1], sb.st_ino);
 
 return 0;
}
