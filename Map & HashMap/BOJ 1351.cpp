// 무한수열, 

#include <iostream>
#include <map>
using namespace std;

long long n,p,q;
map<long long, long long> prevSeq;

long long infSeq(long long n){
    if(n==0)
        return 1;
        
    if(prevSeq[n])
        return prevSeq[n];
    
    else
        return prevSeq[n] = infSeq(n/p) + infSeq(n/q);
}

int main(){
    cin>>n>>p>>q;
    
    cout<<infSeq(n)<<endl;
    
    return 0;
}
