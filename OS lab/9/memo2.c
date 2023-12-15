#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *dynamicInt = (int *)malloc(sizeof(int));

    if (dynamicInt == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Assign a value to the allocated memory
    *dynamicInt = 42;

    // Print the value
    printf("Dynamic integer value: %d\n", *dynamicInt);

    // Release the allocated memory
    free(dynamicInt);

    // After freeing, attempting to access the memory is undefined behavior
    // Uncommenting the next line would lead to undefined behavior
    printf("Dynamic integer value after freeing: %d\n", *dynamicInt);

    return 0;
}