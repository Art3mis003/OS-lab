#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char c;
    char inputFileName[100];
    char outputFileName[100];
    int in, out;

    printf("Enter the input filename: ");
    scanf("%s", inputFileName);

    printf("Enter the output filename: ");
    scanf("%s", outputFileName);

    in = open(inputFileName, O_RDONLY);
    out = open(outputFileName, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if (in == -1 || out == -1) {
        write(1, "Error\n", 6);
        exit(0);
    }

    while (read(in, &c, 1) == 1)
        write(out, &c, 1);

    write(1, "Copied!\n", 8);
    return 0;
}
