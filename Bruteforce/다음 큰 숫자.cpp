#include <string>
#include <vector>

using namespace std;

int binary_num(int n){
    int cnt = 0;
    
    for(int i=0; i<31; i++){
        if(n & (1 << i))
            cnt++;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int num_one = binary_num(n);
    
    for(int i=n+1; i<1000001; i++){
        if(num_one == binary_num(i)){
            answer = i;
            break;
        }
    }
    
    return answer;
}
