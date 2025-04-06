// Algospot QUADTREE
// Divide & Conquer

#include <iostream>
#include <string>
using namespace std;

// 현재 영역을 언제까지 분할할지 알 수 없으므로, 포인터를 전역변수로 관리해야 압축된 문자열에서 4개 영역의 시작점을 알 수 있음
string quad_tree(string::iterator& it){
    char head = *it;
    ++it;

    if(head == 'b' || head == 'w')
        return string(1, head);

    // 좌상단 -> 우상단 -> 좌하단 -> 우하단 순서
    // 기존 그림을 상하로 뒤집은 그림 = 좌하단 -> 우하단 -> 좌상단 -> 우상단 순서
    string lu = quad_tree(it);
    string ru = quad_tree(it);
    string ld = quad_tree(it);
    string rd = quad_tree(it);

    return string("x") + ld + rd + lu + ru;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin>>tc;
    for(int t=0; t<tc; t++){
        string compressed; cin>>compressed;

        string::iterator it = compressed.begin();
        cout<<quad_tree(it)<<"\n";
    }
}
