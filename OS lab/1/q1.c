#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
    char filename[100];
    printf("Enter filename: \n");
    scanf("%s", filename);
    char chr[200],c[10],ch;
    printf("Enter the string to be searched: \n");
    scanf("%s",c);
    int i = 0;
    int in;
    if((in=open(filename, O_RDONLY))==-1){
        perror("Error opening file");
        exit(1);
    }

   while(read(in,&ch,1)>0){
       if(ch!='\n'){
           chr[i]=ch;
           i++;
       }
       else{
           ch='\0';
           i=0;
           if(strstr(chr,"great")!=NULL){
                printf("%s\n",c);
           }
       }
    close(in);
    return 0;
}
}