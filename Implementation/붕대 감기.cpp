// PCCP 기출문제 1번 붕대 감기 (Lv.1)

#include <vector>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int seq = 0, t = bandage[0], x = bandage[1], y = bandage[2], i = 0;
    int until = attacks[attacks.size()-1][0];
    
    for(int s=1; s<=until; s++){
        if(s == attacks[i][0]){
            answer -= attacks[i][1];
            seq = 0;
            i++;
        }
        
        else{
            answer = (answer + x) <= health ? (answer + x) : health;
            seq++;
            
            if(seq == t){
                answer = (answer + y) <= health ? (answer + y) : health;
                seq = 0;
            }
        }
        
        if(answer <= 0)
            return -1;
    }
    
    return answer;
}
