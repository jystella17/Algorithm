#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[l];
    int low = l;

    for(int i=l; i<=r; i++){
        if(arr[i] <= pivot){
            swap(arr[low], arr[i]);
            low++;
        }
    }
    swap(arr[l], arr[low-1]);

    return low-1;
}

int quickSelect(int arr[], int l, int r, int k){
    if(k>0 && k<=r-l+1){
        int pivot = partition(arr, l, r);
        
        if(pivot - l == k - 1)
            return arr[pivot];
        
        else if(pivot - l > k - 1)
            return quickSelect(arr, l, pivot-1, k);
            
        else
            return quickSelect(arr, pivot+1, r, k + l - pivot - 1);
    }
    
    return -1;
}

int main(){
    int arr[10] = {45, 33, 21, 5, 6, 8, 63, 54, 76, 82};
    int k = 4;
    int size = sizeof(arr)/sizeof(int);
    cout<<quickSelect(arr, 0, size-1, k)<<endl;
}
