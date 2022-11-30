#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> person;

int is_distant(vector<string> room, int r1, int c1, int r2, int c2){
    int min_r = min(r1, r2);
    int min_c = min(c1, c2);
    int max_r = max(r1, r2);
    int max_c = max(c1, c2);
    
    if(r1 == r2){
        if(room[r1][(c1+c2)/2] == 'X')
            return 1;
    }
    
    else if(c1 == c2){
        if(room[(r1+r2)/2][c1] == 'X')
            return 1;
    }
    
    else if(max_r == r2 && max_c == c2){
        if(room[min_r][max_c] == 'X' && room[max_r][min_c] == 'X')
            return 1;
    }
    
    else if(max_r == r2 && max_c == c1){
        if(room[min_r][min_c] == 'X' && room[max_r][max_c] == 'X')
            return 1;
    }
    
    return 0;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int r=0; r<5; r++){
        person.clear();
        
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(places[r][i][j] == 'P')
                    person.push_back(make_pair(i, j));
            }
        }
        
        int distance = 1;
        for(int i=0; i<person.size(); i++){
            int p1_r = person[i].first;
            int p1_c = person[i].second;
            
            for(int j=i+1; j<person.size(); j++){
                int p2_r = person[j].first;
                int p2_c = person[j].second;
                int manhattan = abs(p1_r - p2_r) + abs(p1_c - p2_c);
                
                if(manhattan <= 2){
                    if(is_distant(places[r], p1_r, p1_c, p2_r, p2_c) == 0){
                        distance = 0;
                        break;
                    }
                }
            }
            if(distance == 0)
                break;
        }
        answer.push_back(distance);
    }
    
    return answer;
}
