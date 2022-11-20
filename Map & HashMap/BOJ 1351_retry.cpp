// 백준 무한수열 
// map + dp(재귀)

#include <iostream>
#include <map>
using namespace std;

map<long long, long long> sequence;
long long n, p, q;

long long infSeq(long long x){
    if(sequence.count(x)) // key 값이 x인 데이터가 map에 존재하면
        return sequence[x];
    
    else
        return sequence[x] = infSeq(x/p) + infSeq(x/q);
} 

int main(){
    cin>>n>>p>>q;
    
    sequence[0] = 1;
    
    cout<<infSeq(n)<<endl;
    
    return 0;
}
