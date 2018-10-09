#include<stdio.h>
#include<stdlib.h>
 
void Merge(int *R, int low, int m, int high);
void MergeSort(int R[], int low, int high);
 
int main(void) {
    int arr[110], num, i, j, res = 0;
 
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
 
    // sort the array with Merge Sort.
    MergeSort(arr, 0, num - 1);
 
    for (i = num - 1, j = 0; i >= 0; i--, j++) {
        if ((j + 1)%3 == 0) {
            res += arr[i];
        }
    }
 
    printf("%d\n", res);
    return 0;
}
 
void Merge(int *R, int low, int m, int high) {
    int i = low, j = m + 1, p = 0;
    int *R1;
    R1 = (int *)malloc((high - low + 1)*sizeof(i));
    if (!R1) return;
 
    while (i <= m && j <= high) {
        R1[p++] = (R[i] <= R[j])?R[i++]:R[j++];
    }
 
    while (i <= m) {
        R1[p++] = R[i++];
    }
 
    while (j <= high) {
        R1[p++] = R[j++];
    }
 
    for (p = 0, i = low; i <= high; p++, i++) {
        R[i] = R1[p];
    }
 
    free(R1);
}
 
void MergeSort(int R[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high)/2;
        MergeSort(R, low, mid);
        MergeSort(R, mid + 1, high);
        Merge(R, low, mid, high);
    }
}
