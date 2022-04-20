#include <iostream>
#define INF 31313131
using namespace std;

int mat[101][2];

int matrix(int arr[], int i, int j){ // n * m 행렬일 때 n의 크기
    if(i == j)
        return 0;
    
    int cnt;
    int min = INF;
    
    for(int k=i; k<j; k++){
        cnt = matrix(arr, i, k) + matrix(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        
        if(cnt < min)
            min = cnt;
    }
    return min;
}

int main(){
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(int);
    
    cout<<matrix(arr, 1, n-1)<<endl;
    return 0;
}
