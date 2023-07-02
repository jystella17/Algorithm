// 백준 G2 2749번 피보나치 수3
// 피사노 주기

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long n; cin>>n;
    
    int MOD = 1000000;
    long long fibonacci[1500001];
    fibonacci[0] = 0; fibonacci[1] = 1;
    
    for(int i=0; i<1500000; i++)
        fibonacci[i+2] = (fibonacci[i+1] + fibonacci[i]) % MOD;
        
    cout<<fibonacci[n%1500000]<<"\n";
    return 0;
}
