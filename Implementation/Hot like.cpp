// NCPC 2019 (Nordic Collegiate Programming Contest)
// Problem H (Hot Like)
// Can be solved using sliding window either

#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int n; cin>>n;
    int t[51];
    for(int i=1; i<=n; i++)
        cin>>t[i];
 
    int answer = 0, max_temp = 50;
    for(int i=1; i<n-1; i++){
        if(max(t[i], t[i+2]) < max_temp){
            answer = i;
            max_temp = max(t[i], t[i+2]);
        }
    }
 
    cout<<answer<<" "<<max_temp<<"\n";
    return 0;
}
