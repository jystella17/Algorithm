// 프로그래머스 LV.2 마법의 엘리베이터
// 예외 케이스(5) 처리에 주의

#include <string>
#include <vector>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey){
        int cur = storey % 10;
        
        if(cur > 5){
            answer += (10-cur);
            storey += 10;
        }
        
        else if(cur == 5){
            int next = (storey/10)%10;
            if(next >= 5){
                answer += cur;
                storey += 10;
            }
            else // next < 5
                answer += cur;
        }
        
        else // cur < 5
            answer += cur;
        
        storey /= 10;
    }
    
    return answer;
}
