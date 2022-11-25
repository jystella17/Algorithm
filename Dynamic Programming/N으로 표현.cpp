#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> expression[8];
    
    int num = 0;
    for(int i=0; i<8; i++){
        num = 10*num + N;
        expression[i].insert(num); // 55, 555 등 숫자를 나열해서 표현할 수 있는 숫자 저장
    }
    
    for(int n=1; n<8; n++){ // 2~8개의 N으로 표현할 수 있는 숫자 => 개수 지정
        for(int i=0; i<n; i++){ // 1~n-1개의 N => Base case 개수 지정
            for(int x : expression[i]){ // i개의 N으로 표현할 수 있는 숫자에
                for(int y : expression[n-i-1]){ // 사칙연산 variation
                    expression[n].insert(x+y);
                    expression[n].insert(x-y);
                    expression[n].insert(x*y);
                    
                    if(y != 0)
                        expression[n].insert(x/y);
                }              
            }
        }
    }
    
    for(int i=0; i<8; i++){
        if(expression[i].count(number)){
        // i개의 N으로 표현할 수 있는 숫자 목록에 number가 포함되면
            answer = i+1;
            break;
        }
    }
    
    return answer;
}
