// BOJ 2841 외계인의 기타 연주 (S1)
// 각 줄(row)에 대해 프렛(fret)을 Stack으로 저장 => 각 줄에서 현재 누르고 있는 fret의 최대값 = stack top
// stack[row].top() == current fret인 경우에 대한 edge case 처리 필요 (continue)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> guitars[7];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int answer = 0;
    int n, p; cin>>n>>p;

    for(int i=0; i<n; i++){
        int row, fret; cin>>row>>fret;

        if(guitars[row].empty() || guitars[row].top() < fret){
            guitars[row].push(fret);
            answer++;
        }

        else if(guitars[row].top() == fret) continue;

        else{
            while(!guitars[row].empty() && guitars[row].top() > fret){
                guitars[row].pop();
                answer++;
            }

            if(!guitars[row].empty() && guitars[row].top() == fret) continue;

            guitars[row].push(fret);
            answer++;
        }
    }
    cout<<answer<<"\n";
}
