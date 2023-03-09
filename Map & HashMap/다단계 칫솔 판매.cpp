// 프로그래머스 LV.3 다단계 칫솔 판매
// Map & 재귀 (Union-Find의 Find 개념 참고)

#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, string> organization; // 조직도
map<string, int> sales; // 구성원 별 매출
vector<int> answer;

void distribution(string staff, int money){
    if(staff == "-")
        return;
    
    int share = money*0.1;
    sales[staff] += (money-share);
    
    if(share > 0)
        distribution(organization[staff], share);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    for(int i=0; i<enroll.size(); i++){
        organization[enroll[i]] = referral[i];
        sales[enroll[i]] = 0; // 각 구성원 별 매출을 0으로 초기화
    }
    
    // sales를 amount(순수 매출)로 초기화해도 어차피 다시 sales를 탐색하며 수익을 재분배해야 함
    // 따라서 각 조직원의 매출을 입력받는 동시에 수익을 분배하여 저장
    for(int i=0; i<seller.size(); i++)
        distribution(seller[i], amount[i]*100);
    
    for(int i=0; i<enroll.size(); i++)
        answer.push_back(sales[enroll[i]]);
    
    return answer;
}
