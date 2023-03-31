// 백준 G4 별자리 찾기
// 이분탐색 응용 & 아이디어 도출 연습

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> zodiac;
vector<pair<int, int>> picture;

int main(){
    int m, n, x_move = 0, y_move = 0;
    cin>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        zodiac.push_back(make_pair(x,y));
    }

    cin>>n;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        picture.push_back(make_pair(x, y));
    }
    
    sort(zodiac.begin(), zodiac.end());
    sort(picture.begin(), picture.end());
    
    // picture에 포함된 별들의 좌표를 각각 탐색하며 
    // zodiac에 포함된 첫번째 별의 좌표를 기준으로 이동량을 구하고
    // 같은 수치로 이동했을 때 zodiac에 포함된 모든 별이 picture에도 포함되는지 판정
    for(int i=0; i<n; i++){
        x_move = picture[i].first - zodiac[0].first;
        y_move = picture[i].second - zodiac[0].second;
        bool is_diff = false;
        
        for(int j=0; j<m; j++){
            int next_x = zodiac[j].first + x_move;
            int next_y = zodiac[j].second + y_move;
            // x좌표 오름차순으로 이미 정렬되었으므로 binary search를 활용해 속도 향상
            if(!binary_search(picture.begin(), picture.end(), make_pair(next_x, next_y))){
                is_diff = true;
                break;
            }
        }
        
        if(!is_diff){
            cout<<x_move<<" "<<y_move<<"\n";
            return 0;
        }
    }
    return 0;
}
