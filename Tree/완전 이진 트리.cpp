// BOJ 9934 완전 이진 트리 (S1)
// Inorder 개념 활용

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int k; cin>>k;

    int num_buildings = pow(2, k) - 1;
    int buildings[1024];

    for(int i=0; i<num_buildings; i++){
        cin>>buildings[i];
    }

    // 트리를 Inorder로 방문한 결과를 1차원 배열로 표현했을 때,
    // 배열의 1(2^0) 번째 원소부터 2(=2^1) 간격으로 탐색되는 모든 원소는 leaf node (깊이 k-1)
    // 배열의 2(2^1) 번째 원소부터 4(=2^2) 간격으로 탐색되는 모든 원소는 깊이 k-2
    // 배열의 4(2^2) 번째 원소부터 8(=2^3) 간격으로 탐색되는 모든 원소는 깊이 k-3
    for(int i=k-1; i>=0; i--){
        int idx = pow(2, i) - 1;
        int interval = pow(2, i+1);

        while(idx < num_buildings){
            cout<<buildings[idx]<<" ";
            idx += interval;
        }
        cout<<"\n";
    }

    return 0;
}
