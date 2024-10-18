// BOJ 27134 Subset Sums (S1)
// 0-1 Knapsack
// 1~n까지의 숫자를 사용해 n*(n+1)/4를 만드는 경우의 수 찾기 => 
// 1~1, 1~2, 1~3, ... , 1~n까지의 숫자를 사용해 1 <= j <= n*(n+1)/4인 j를 만드는 경우의 수 찾기

#include <iostream>
using namespace std;

// dp[i] = 1~n까지의 숫자를 최대 1번씩 사용해서 sum이 i가 되도록 하는 경우의 수
long dp[400];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int sum = n * (n+1)/2;

    for(int i=0; i<=sum/2; i++){
        dp[i] = 0;
    }

    if(sum % 2 == 0){
        dp[0] = 1;
        // 1, 1~2, 1~3, ..., 1~n 범위의 숫자를 최대 1번씩 사용해서 sum이 j가 되도록 하는 경우의 수 구하기
        for(int i=1; i<=n; i++){
            // 오름차순으로 탐색할 경우, 현재 i에 대해 계산한 값이 포함되므로 역순 탐색
            for(int j=sum/2; j>=i; j--){
                dp[j] += dp[j-i];
            }
        }
    }

    cout<<dp[sum/2]/2<<"\n";
    return 0;
}
