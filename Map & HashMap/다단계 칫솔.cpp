// 프로그래머스 LV.3 다단계 칫솔
// Map & 재귀 (Union-Find의 Find 개념 참고)

#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> organization; // 조직도(추천인 관계)
map<string, int> sales; // 각 구성원 별 매출
vector<int> answer;

void distribution(string staff, int money){
    if(staff == "-")
        return;
    
    int share = money*0.1;    
    sales[staff] += money - share;
    
    if(share>0)
        distribution(organization[staff], share);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {   
    for(int i=0; i<enroll.size(); i++){
        // Tree에 초기 입력값 저장
        sales[enroll[i]] = 0; 
        organization[enroll[i]] = referral[i];
    }
    
    for(int i=0; i<seller.size(); i++) // 수익 분배
        distribution(seller[i], amount[i]*100);
    
    for(int i=0; i<sales.size(); i++) // enroll에 이름이 포함된 순서대로
        answer.push_back(sales[enroll[i]]);
    
    return answer;
}
