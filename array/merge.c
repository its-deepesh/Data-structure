#include <stdio.h>

int main(){
    int arr1[10], arr2[10], n, n1;

    printf("Enter no of element for array 1st: ");
    scanf("%d", &n);

    printf("Enter array 1st: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
    }

    printf("\n");

    printf("Enter no of element for array 2nd: ");
    scanf("%d", &n1);

    printf("Enter array 2nd: ");
    for(int i = 0; i < n1; i++){
        scanf("%d", &arr2[i]);
    }

    printf("\n");

    printf("Array 1st: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr1[i]);
    }

    printf("\n");

    printf("Array 2nd: ");
    for(int i = 0; i < n1; i++){
        printf("%d ", arr2[i]);
    }

    printf("\n");
    printf("\n");

    int merged[n + n1];

    for(int i = 0; i < n; i++){
        merged[i] = arr1[i];
    }

    for(int i = 0; i < n1; i++){
        merged[n + i] = arr2[i];
    }

    printf("Merged Array: ");
    for(int i = 0; i < n + n1; i++){
        printf("%d ", merged[i]);
    }
 
    printf("\n");
    return 0;
}