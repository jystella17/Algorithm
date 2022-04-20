#include <iostream>
#define INF 31313131
using namespace std;

int arr[4][4] = {
    { 0, 5, INF, 8 },
    { 7, 0, 9, INF },
    { 2, INF, 0, 4 },
    { INF, INF, 3, 0 }
};

int main(){
    for(int k=0; k<4; k++) // 거쳐가는 정점
        for(int i=0; i<4; i++) // 출발 정점
            for(int j=0; j<4; j++) // 도착 정점
                if(arr[i][k] + arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
                    
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
