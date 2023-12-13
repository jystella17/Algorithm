#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    int T; cin>>T;
    
    for(int t=1; t<=T; t++){
        int n; cin>>n;
        int cnt = 1, visited = 1023;
        int lamb = n;
        
        while((1023^visited) != 1023){
            while(lamb > 0){
                int check = lamb % 10;
                lamb /= 10;
                
                int result = visited & (1<<check);
                if(result != 0)
                    visited ^= result;
            }

            cnt++;
            lamb += (n*cnt);
        }
        cout<<"#"<<t<<" "<<n*(cnt-1)<<"\n";
    }
    return 0;
}
