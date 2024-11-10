// NCPC 2019 (Nordic Collegiate Programming Contest)
// Problem C (Cocoa Coalition)

#include <iostream>
using namespace std;
 
long long n, m, a, b;
 
bool can_be_in(long long num){
    for(long long i=1; i<=n; i++){
        if(num % i > 0) continue;
        
        long long j = num / i;
        if(j <= m)
            return true;
    }
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m>>a;
    b = (n*m) - a;

    // if a is divisible by n or m, then b is also divisible by same number(n or m)
    // because b = (n*m) - a can be modified to b/n = n(m - a/n) or b/m = m(n - a/m) where a/m or a/n is integer 
    // then b/m or b/n is integer (= b is divisible by n or m)
    // And it directly means that single slice can make area a and b simultaneously.
    if((a % n) == 0 || (a % m) == 0)
        cout<<1<<"\n";

    // If a = x * y (x<=n, y<=m) or b =  x * y (x<=n, y<=m), 2 slices can make area a and b.
    else if(can_be_in(a) || can_be_in(b))
        cout<<2<<"\n";

    // Other cases means that 3 slices are required to make area a and b.
    else
        cout<<3<<"\n";
 
    return 0;
}
