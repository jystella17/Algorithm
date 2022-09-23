// LIS 알고리즘

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    stack<int> lis;
    int dp[1001] = {0, };
    int A[1001];
    int n;
    
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>A[i];
        
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    int len_lis = *max_element(dp, dp+n+1);
    cout<<len_lis<<endl;
    
    for(int i=n; i>0; i--){
        if(dp[i] == len_lis){
            lis.push(A[i]);
            len_lis--;
        }
    }
    
    while(!lis.empty()){
        cout<<lis.top()<<endl;
        lis.pop();
    }
    
    return 0;
}
