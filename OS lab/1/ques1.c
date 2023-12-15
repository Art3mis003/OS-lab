#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    int in;
    if ((in = open(filename, O_RDONLY)) == -1) {
        perror("Error opening file");
        exit(1);
    }

    char c[200];
    int i = 0;

    while (read(in, c + i, 1) > 0) {
        while (*(c + i) != '\n') {
            i++;
            read(in, c + i, 1);
        }
        if (strstr(c, filename) != NULL) {
            write(1, c, i + 1);
        }
        i = 0;
        memset(c, 0, 100);
    }

    close(in);

    return 0;
}
