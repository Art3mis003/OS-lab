#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
int main() {
    char filename1[100], filename2[100];
    int i = 0, k = 0, p = 0;
    char ch[100], ch2[100], chr;

    printf("Enter the first filename: ");
    scanf("%s", filename1);

    printf("Enter the second filename: ");
    scanf("%s", filename2);

    int f1, f2;

    if ((f1 = open(filename1, O_RDONLY)) == -1) {
        printf("File not found: %s\n", filename1);
        exit(1);
    }

    while (read(f1, &chr, 1) > 0) {
        if (chr != '\n') {
            ch[i] = chr;
            i++;
        } else {
            k++;
            p++;
            ch[i] = '\0';
            i = 0;
            printf("%s Line %d:\n%s\n", filename1, p, ch);
            if (k == 20) {
                fgetc(stdin);
                k = 0;
            }
        }
    }
    close(f1);

    p = 0;

    if ((f2 = open(filename2, O_RDONLY)) == -1) {
        printf("File not found: %s\n", filename2);
        exit(1);
    }

    while (read(f2, &chr, 1) > 0) {
        if (chr != '\n') {
            ch2[i] = chr;
            i++;
        } else {
            k++;
            p++;
            ch2[i] = '\0';
            i = 0;
            printf("%s Line %d:\n%s\n", filename2, p, ch2);
            if (k == 20) {
                fgetc(stdin);
                k = 0;
            }
        }
    }
    close(f2);

    exit(0);
}
