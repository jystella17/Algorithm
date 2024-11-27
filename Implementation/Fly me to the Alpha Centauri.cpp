// BOJ 1011 Fly me to the Alpha Centauri (G5)
// Mathematics / Implementation 버전
// 장치의 최대 속력이 k가 될 수 있는 두 지점 간 거리의 최소값 = k^2
// 즉, k^2 <= y-x < (k+1)^2 를 만족하는 k가 두 지점 사이를 이동하며 낼 수 있는 최대 속력
// k = root(y-x) => 최대 속력이 k일 때, 가능한 조작 횟수의 범위는 2k-1 ~ 2k+1
// y-x = k^2 일 때 2k-1 | y-x <= k^2 + k 일 때 2k | k^2 + k < y-x < (k+1)^2 일 때 2k+1

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long x, y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int tc; cin>>tc;
    for(int t=0; t<tc; t++){
        cin>>x>>y;
    
        long diff = y - x;
        long k = sqrt(diff);

        if(diff == 1 || diff == 2 || diff == 3) cout<<diff<<"\n";
        else if(diff == k*k) cout<<(2*k - 1)<<"\n";
        else if(diff <= (k*k + k)) cout<<2*k<<"\n";
        else cout<<(2*k + 1)<<"\n";
    }
    
    return 0;
}
