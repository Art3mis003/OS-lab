#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    int *dynamic = (int *)malloc(n * sizeof(int));
    if (dynamic == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for(int i=0;i<n;i++){
        printf("enter the value of %d element: ",i);
        scanf("%d",&dynamic[i]);

    }
    for(int i=0;i<n;i++){
        printf("value of element: %d\n",dynamic[i]);
    }
    free(dynamic);
    return 0;
}