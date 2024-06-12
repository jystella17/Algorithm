// BOJ 28437 막대 만들기 (G3)
// 약수 구하기 알고리즘으로 최적화 (sqrt) + dp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, q;
int a[100000], l[100000], dp[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int end = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp; cin>>tmp;
        
        a[tmp] = 1; // 각 숫자(=처음 선택할 있는 막대 길이)의 등장 여부 저장
        dp[tmp] = 1;
        
        end = max(end, tmp);
    }

    cin>>q;
    for(int i=0; i<q; i++){
        cin>>l[i];
        end = max(end, l[i]);
    }

    // 1 ~ 등장하는 최대 숫자까지 모든 막대 만들기 방법의 수를 dp 배열에 저장
    for(int i=2; i<=end; i++){
        for(int j=1; j<=sqrt(i); j++){
            if(i % j == 0)
                dp[i] += dp[j];
                
            int divisor = i/j;
            if(i % divisor == 0 && divisor != i && divisor != j) // 완전제곱수에서 중복 카운트 방지
                dp[i] += dp[divisor];
        }
    }

    // 특정 길이의 막대를 만드는 방법의 수 출력 
    for(int i=0; i<q; i++){
        cout<<dp[l[i]]<<" ";
    }
    cout<<"\n";
    return 0;
}
