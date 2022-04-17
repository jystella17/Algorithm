#include <iostream>
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
#define MAXI 9
using namespace std;

int sorted[MAXI];

int partition(int arr[], int l, int r){
    int tmp;
    int low = l, high = r;
    int pivot = arr[l];
    
    while(low < high){
        while(arr[low] <= pivot)
            low++;
        
        while(arr[high] > pivot)
            high--;
        
        if(low < high)
            SWAP(arr[low], arr[high], tmp);
    }
    SWAP(arr[l], arr[high], tmp);
    
    return high;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int pivot = partition(arr, l, r);
        
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }
}

int main(){
    int arr[10] = {4, 8, 2, 3, 9, 7, 1, 6, 10, 5};
    int size = sizeof(arr)/sizeof(int);
    
    quickSort(arr, 0, size-1);

    for(int i=0; i<size; i++)
        cout<<arr[i]<<endl;
}
