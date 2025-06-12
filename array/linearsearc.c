#include <stdio.h>

int main(){
    int arr[50], n;
    printf("Enter number of elements for array: ");
    scanf("%d", &n);
    printf("\n");

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    int key;
    int found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);

    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    
    if(found == 0){
        printf("Element not found\n");
    }

    return 0;
}