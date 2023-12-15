#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

int main()
{
    DIR *dp;
    struct stat sd;
    struct dirent * entry;
    chdir(".");
    dp=opendir(".");
    while((entry=readdir(dp))!=NULL){
        stat(entry->d_name,&sd);
        if(S_ISDIR(sd.st_mode)){
            printf("%s\n",entry->d_name);
        }
        printf(S_IRUSR & sd.st_mode? "r":"-");
        printf(S_IWUSR & sd.st_mode? "w":"-");
        printf(S_IXUSR & sd.st_mode? "x":"-");
        printf(S_IRGRP & sd.st_mode? "r":"-");
        printf(S_IWGRP & sd.st_mode? "w":"-");
        printf(S_IXGRP & sd.st_mode? "x":"-");
        printf(S_IROTH & sd.st_mode? "r":"-");
        printf(S_IWOTH & sd.st_mode? "w":"-");
        printf(S_IXOTH & sd.st_mode? "x":"-");
        }
}