// 수들의 합 4

#include <iostream>
#include <map>
using namespace std;
int sum[200001];

int main(){
    int n, k, num;
    cin >> n >> k;
    map<int, long long> m;

    long long cnt = 0;
    m[0] = 1;

    for (int i=1; i<=n; i++){
        cin>>num;
        sum[i] = sum[i-1] + num;
        cnt += m[sum[i] - k];
        m[sum[i]]++;
    }
    cout<<cnt<<endl;
}
