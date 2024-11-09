// NCPC 2019 (Nordic Collegiate Programming Contest)
// Problem B (Building Boundaries)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
long long pieces[8][6];
 
int main(){
    int tc; cin>>tc;
    for(int t=0; t<tc; t++) {
        long long a1, b1, a2, b2, a3, b3;
        cin>>a1>>b1>>a2>>b2>>a3>>b3;

        // rotate pieces = 2^3 = 8 cases
        pieces[0][0] = a1; pieces[0][1] = b1; pieces[0][2] = a2;
        pieces[0][3] = b2; pieces[0][4] = a3; pieces[0][5] = b3;
 
        pieces[1][0] = b1; pieces[1][1] = a1; pieces[1][2] = a2;
        pieces[1][3] = b2; pieces[1][4] = a3; pieces[1][5] = b3;
 
        pieces[2][0] = a1; pieces[2][1] = b1; pieces[2][2] = b2;
        pieces[2][3] = a2; pieces[2][4] = a3; pieces[2][5] = b3;
 
        pieces[3][0] = a1; pieces[3][1] = b1; pieces[3][2] = a2;
        pieces[3][3] = b2; pieces[3][4] = b3; pieces[3][5] = a3;
 
        pieces[4][0] = b1; pieces[4][1] = a1; pieces[4][2] = b2;
        pieces[4][3] = a2; pieces[4][4] = a3; pieces[4][5] = b3;
 
        pieces[5][0] = b1; pieces[5][1] = a1; pieces[5][2] = a2;
        pieces[5][3] = b2; pieces[5][4] = b3; pieces[5][5] = a3;
 
        pieces[6][0] = a1; pieces[6][1] = b1; pieces[6][2] = b2;
        pieces[6][3] = a2; pieces[6][4] = b3; pieces[6][5] = a3;
 
        pieces[7][0] = b1; pieces[7][1] = a1; pieces[7][2] = b2;
        pieces[7][3] = a2; pieces[7][4] = b3; pieces[7][5] = a3;
 
        vector<int> num = {0, 1, 2};
        long long answer = 5e18;
 
        for(int i=0; i<8; i++) {
            do{
                // in each rotation cases, there are 6 ways to located 3 pieces
                // select 2 pieces among 3 and put them horizontally (3C2)
                // put unselected piece horizontally or vertically (2!)
                // = 3C2 * 2! = 3! = 6
              
                // selected piece 1
                long long x1 = pieces[i][num[0]*2], y1 = pieces[i][num[0]*2 + 1];
                // selected piece 2
                long long x2 = pieces[i][num[1]*2], y2 = pieces[i][num[1]*2 + 1];
                // unselected piece
                long long x3 = pieces[i][num[2]*2], y3 = pieces[i][num[2]*2 + 1];

                // place 2 selected pieces horizontally, and then
                // place unselected piece horizontally
                long long horizontal = max(max(x1, x2), x3) * (y1 + y2 + y3);
                // or place unselected piece vertically
                long long vertical = (max(x1, x2) + x3) * max(y1 + y2, y3);
                answer = min(min(horizontal, vertical), answer);
 
            } while(next_permutation(num.begin(), num.end()));
        }
        cout<<answer<<"\n";
    }
 
    return 0;
}
