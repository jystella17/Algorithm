// BOJ 1011 Fly me to the Alpha Centauri (G5)
// Parametric Search 버전
// 공간 이동 장치를 n번 작동시켜 이동할 수 있는 거리의 최대값 = 1 + 2 + ... + n/2 + ... + 1
// = (1 + 2 + ... + n/2) x 2 = (n x (n+2) / 8) x 2 = n x (n+2) / 4  (n이 짝수인 경우)
// = (1 + 2 + ... + n-1/2) x 2 + (n+1) / 2 = (n^2 - 1) / 4 + (n+1) / 2 = (n+1)^2 / 4  (n이 홀수인 경우)
// 공간 이동 장치를 n번 작동시켰을 때 이동할 수 있는 거리의 최대값이 두 지점 간의 거리(y-x) 이상이면 더 작은 n에 대해 시도 / 미만이면 더 큰 n에 대해 시도 => lower bound

#include <iostream>
#include <algorithm>
using namespace std;

long x, y;

bool can_move(long count){
    long max_velocity = 0;
    
    if((count % 2) == 0) max_velocity = count * (count+2) / 4;
    else max_velocity = (count+1) * (count+1) / 4;
    
    if(max_velocity >= (y-x)) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int tc; cin>>tc;
    for(int t=0; t<tc; t++){
        cin>>x>>y;
    
        long start = 0, end = y-x;
        while(start <= end){
            long mid = (start + end) / 2;
        
            if(can_move(mid))
                end = mid-1;
            else
                start = mid+1;
        }
    
        cout<<start<<"\n";
    }
    
    return 0;
}
