// 수들의 합 4

#include <iostream>
#include <map>
using namespace std;

int sum[200001];

int main(){
    int n,k;
    map<int, long long> partial; // 각 sum 값에 대해, 몇 개의 부분합이 존재하는지 저장
    long long ans = 0;
    cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        cin>>sum[i];
        sum[i] += sum[i-1];
        
        if(sum[i] == k)
            ans++;
        
        ans += partial[sum[i] - k];
        // sum[i] > k 인 경우, i보다 같거나 작은 임의의 j에 대해 sum[i] - sum[j-1] = k (j~i 까지의 합), 즉 sum[j-1] = sum[i] - k 이다. 
        partial[sum[i]]++;
    }
    
    cout<<ans<<endl;
    return 0;
}
