#include <stdio.h>

int main(){
    int arr[50], n;
    printf("Enter number of elements for array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    int first = -1;
    int second = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] > first){
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] != first){
            second = arr[i];
        }
    }

    printf("Largest element of array is %d.\n", first);
    printf("Second largest element of array is %d.\n", second);

    return 0;
}