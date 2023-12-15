#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void executeFunc(char* path, int depth)
{
    struct stat sb;
    struct dirent *myfile;
    DIR *mydir=opendir(path);
    stat(myfile->d_name,&sb);
    chdir(path);
    while((myfile=readdir(mydir))!=NULL){
        if(strcmp(myfile->d_name,".")==0 || strcmp(myfile->d_name,"..")==0)
            continue;
        for(int i=0;i<depth;i++){
            printf(" ");
        }
        printf("%s\n",myfile->d_name);
        if(S_ISDIR(sb.st_mode)){
            executeFunc(myfile->d_name,depth+4);
        }

        }

    
    
    chdir("..");
    closedir(mydir);
}


int main()
{
    executeFunc(".", 0);
    return 0;
}