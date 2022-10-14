#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int mid, int r){
    int new[r-l+1];
    int idx = 0, i = l, j = mid+1;
    while( i <= mid && j <= r ) {
        if(arr[i] <= arr[j]){
            new[idx] = arr[i];
            i++;
        } else {
            new[idx] = arr[j];
            j++;
        }
        idx++;
    }
    while( i <= mid ){
        new[idx] = arr[i];
        idx++;
        i++;
    }
    while( j <= r ){
        new[idx] = arr[j];
        idx++;
        j++;
    }
    for(i = l, idx = 0; i <= r; i++, idx++){
        arr[i] = new[idx];
    }
}

void merge_sort(int arr[], int l, int r){
    if( l < r ){
        int mid = l+(r-l)/2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    int x,y; scanf("%d", &x);
    int arr[x];
    for(int i = 0; i < x; i++){
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, x-1);

    printf("Array: \n");
    for(int i = 0; i < x; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
