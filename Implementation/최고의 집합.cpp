// 프로그래머스 LV.3 최고의 집합
// 자연수로 이루어진 집합이므로, 모든 원소의 곱이 최대가 되려면 집합의 모든 원소 값이 최대한 균일하도록 해야 함
// S = 집합에 포함된 원소들의 합, N = 집합의 원소의 개수일 때
// (S - i) / (N - i)

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int left_s = s;
    for(int i=n; i>0; i--){
        int elem = left_s/i;
        if(elem == 0){
            answer.clear();
            answer.push_back(-1);
            break;
        }
        
        answer.push_back(elem);
        left_s -= elem;
    }
 
    return answer;
}
