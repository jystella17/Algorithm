#include <bits/stdc++.h>
#define MAXI 10
using namespace std;

int sorted[MAXI];

void merge(int arr[], int left, int mid, int right){
    int l = left;
    int m = mid+1;
    int k = left;
    
    while(l<=mid && m<=right){
        if(arr[l] <= arr[m])
            sorted[k++] = arr[l++];
        else
            sorted[k++] = arr[m++];
    }
    
    if(l > mid){
        for(int i=m; i<=right; i++)
            sorted[k++] = arr[i];
    }
    
    else{
        for(int i=l; i<=mid; i++)
            sorted[k++] = arr[i];
    }
    
    for(int i=left; i<=right; i++)
        arr[i] = sorted[i];
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int arr[10] = {5, 9, 3, 8, 6, 4, 7, 2, 10, 1};
    int size = sizeof(arr)/sizeof(int);
    
    mergeSort(arr, 0, size-1);
    
    for(int i=0; i<size; i++)
        cout<<arr[i]<<endl;
}
