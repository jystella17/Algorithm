// 부분합 개념 + 투포인터 알고리즘

#include <iostream>
#define INF 987654321
using namespace std;

int main(){
    int sequence[100000];
    int n, s;
    cin>>n>>s;
    
    for(int i=0; i<n; i++)
        cin>>sequence[i];
        
    int start = 0;
    int end = 0;
    int sum = sequence[0]; // 부분합을 저장할 변수
    int ans = INF;
    
    while(start<=end && end<n){
        if(sum < s){
            end++;
            if(end < n)
                sum += sequence[end];
        }
        
        else{ // sum >= s
            ans = min(ans, end-start+1); // S 이상인 부분합의 최소 길이
            sum -= sequence[start]; // 탐색을 계속해야 하므로 맨 앞의 값 제거
            start++;
        }
    }
    
    if(ans == INF)
        cout<<0<<endl;
    else
        cout<<ans<<endl;

    return 0;
}
