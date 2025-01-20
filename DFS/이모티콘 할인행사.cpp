// 프로그래머스 Lv.2 이모티콘 할인행사
// 2023 Kakao Blind Recruitment 기출

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> answer = {0, 0};
vector<int> prices, comb;
vector<int> rates = {10, 20, 30, 40};

void permutations(int count, int end, vector<vector<int>> users){
    if(count == end){
        int plus_members = 0;
        int emoticon_sales = 0;
        
        for(int i=0; i<users.size(); i++){
            int discount = users[i][0];
            int emo_plus = users[i][1];
            int sum = 0;
            
            for(int j=0; j<end; j++){
                if(comb[j] >= discount)
                    sum += (prices[j] * (100 - comb[j])) / 100;
            }

            if(sum >= emo_plus) plus_members++;
            else emoticon_sales += sum;
        }

        if(answer[0] < plus_members){
            answer[0] = plus_members;
            answer[1] = emoticon_sales;
        }
        
        else if(answer[0] == plus_members){
            answer[1] = max(answer[1], emoticon_sales);
        }
        
        return;
    }
    
    for(int i=0; i<4; i++){
        comb.push_back(rates[i]);
        permutations(count+1, end, users);
        comb.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    for(int i=0; i<emoticons.size(); i++)
        prices.push_back(emoticons[i]);
    
    permutations(0, emoticons.size(), users);
    return answer;
}
