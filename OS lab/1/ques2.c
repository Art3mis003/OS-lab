#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
    char filename[100],filename2[100];
    int i = 0;
    int f1,f2;
    int k=0,p=0;
    char ch1[100],ch2[100];
    char chr;
    printf("Enter the first filename: ");
    scanf("%s",filename);
    printf("Enter the second filename: ");
    scanf("%s",filename2);
    if((f1=open(filename,O_RDONLY))==-1){
        perror("Error opening file");
        exit(1);
    }
    while(read(f1,&chr,1)>0){
        if(chr!='\n'){
            ch1[i]=chr;
            i++;

        }
        else{
            k++;
            p++;
            ch1[i]='\0';
            i=0;
            printf("%s Line %d:\n%s\n",filename,p,ch1);
            if(k==20){
                fgetc(stdin);
                k=0;
            }

        }


    }
    p=0;
    close(f1);
    if((f2=open(filename2,O_RDONLY))==-1){
        perror("Error opening file");
        exit(1);
    }
    while(read(f2,&chr,1)>0){
        if(chr!='\n'){
            ch2[i]=chr;
            i++;

        }
        else{
            k++;
            p++;
            ch2[i]='\0';
            i=0;
            printf("%s Line %d:\n%s\n",filename2,p,ch2);
            if(k==20){
                fgetc(stdin);
                k=0;
            }

        }
}
    close(f2);

    exit(0);
}