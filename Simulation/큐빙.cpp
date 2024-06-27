// 백준 5373 큐빙 (P5)
// 배열 회전 시 이전 값 = 이후 값 형태로 식이 작성되어야 함에 주의

#include <iostream>
using namespace std;

// U, D, F, B, L, R 순서
char cube[6][3][3] = {
        {{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}},
        {{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}},
        {{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}},
        {{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}},
        {{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}},
        {{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}}
};
char modify[6][3][3];

void rotate_dimension(int dimension, char direction) {
    char tmp[3][3];

    if(direction == '+'){
        for (int j=0; j<3; j++)
            for (int i=0; i<3; i++)
                tmp[j][2-i] = modify[dimension][i][j];
    }
    else{
        for(int j=0; j<3; j++)
            for(int i=0; i<3; i++)
                tmp[2-j][i] = modify[dimension][i][j];
    }

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            modify[dimension][i][j] = tmp[i][j];
}

void rotate_cube(int dimension, char direction) {
    if(dimension == 0){
        char prev[3] = {modify[2][0][0], modify[2][0][1], modify[2][0][2]};

        if(direction == '+'){
            for(int k=0; k<3; k++)
                modify[2][0][k] = modify[5][0][k];
                
            for(int k=0; k<3; k++)
                modify[5][0][k] = modify[3][0][k];

            for(int k=0; k<3; k++)
                modify[3][0][k] = modify[4][0][k];

            for (int k=0; k<3; k++)
                modify[4][0][k] = prev[k];
        }

        else if(direction == '-'){
            char prev[3] = {modify[2][0][0], modify[2][0][1], modify[2][0][2]};

            for(int k=0; k<3; k++)
                modify[2][0][k] = modify[4][0][k];

            for(int k=0; k<3; k++)
                modify[4][0][k] = modify[3][0][k];

            for(int k=0; k<3; k++)
                modify[3][0][k] = modify[5][0][k];

            for(int k=0; k<3; k++)
                modify[5][0][k] = prev[k];
        }
    }

    if(dimension == 1){
        if(direction == '+'){
            char prev[3] = {modify[2][2][0], modify[2][2][1], modify[2][2][2]};

            for(int k=0; k<3; k++)
                modify[2][2][k] = modify[4][2][k];

            for (int k=0; k<3; k++)
                modify[4][2][k] = modify[3][2][k];
            
            for(int k=0; k<3; k++)
                modify[3][2][k] = modify[5][2][k];

            for(int k=0; k<3; k++)
                modify[5][2][k] = prev[k];
        }

        else if(direction == '-'){
            char prev[3] = {modify[2][2][0], modify[2][2][1], modify[2][2][2]};

            for(int k=0; k<3; k++)
                modify[2][2][k] = modify[5][2][k];

            for(int k=0; k<3; k++)
                modify[5][2][k] = modify[3][2][k];

            for(int k=0; k<3; k++)
                modify[3][2][k] = modify[4][2][k];

            for(int k=0; k<3; k++)
                modify[4][2][k] = prev[k];
        }
    }

    if(dimension == 2){
        if(direction == '+'){
            char prev[3] = {modify[0][2][0], modify[0][2][1], modify[0][2][2]};

            for(int k=0; k<3; k++)
                modify[0][2][k] = modify[4][2-k][2];

            for(int k=0; k<3; k++)
                modify[4][k][2] = modify[1][0][k];

            for(int k=0; k<3; k++)
                modify[1][0][k] = modify[5][2-k][0];

            for(int k=0; k<3; k++)
                modify[5][k][0] = prev[k];
        }

        else if(direction == '-'){
            char prev[3] = {modify[0][2][0], modify[0][2][1], modify[0][2][2]};

            for(int k=0; k<3; k++)
                modify[0][2][k] = modify[5][k][0];

            for(int k=0; k<3; k++)
                modify[5][k][0] = modify[1][0][2-k];

            for(int k=0; k<3; k++)
                modify[1][0][k] = modify[4][k][2];

            for(int k=0; k<3; k++)
                modify[4][k][2] = prev[2-k];
        }
    }

    if(dimension == 3){
        if(direction == '+'){
            char prev[3] = {modify[0][0][0], modify[0][0][1], modify[0][0][2]};

            for(int k=0; k<3; k++)
                modify[0][0][k] = modify[5][k][2];

            for(int k=0; k<3; k++)
                modify[5][k][2] = modify[1][2][2-k];

            for(int k=0; k<3; k++)
                modify[1][2][k] = modify[4][k][0];

            for(int k=0; k<3; k++)
                modify[4][k][0] = prev[2-k];
        }

        else if(direction == '-'){
            char prev[3] = {modify[0][0][0], modify[0][0][1], modify[0][0][2]};

            for(int k=0; k<3; k++)
                modify[0][0][k] = modify[4][2-k][0];

            for(int k=0; k<3; k++)
                modify[4][k][0] = modify[1][2][k];

            for(int k=0; k<3; k++)
                modify[1][2][k] = modify[5][2-k][2];

            for(int k=0; k<3; k++)
                modify[5][k][2] = prev[k];
        }
    }

    if(dimension == 4){
        if(direction == '+'){
            char prev[3] = {modify[0][0][0], modify[0][1][0], modify[0][2][0]};

            for(int k=0; k<3; k++)
                modify[0][k][0] = modify[3][2-k][2];

            for(int k=0; k<3; k++)
                modify[3][k][2] = modify[1][2-k][0];

            for(int k=0; k<3; k++)
                modify[1][k][0] = modify[2][k][0];

            for(int k=0; k<3; k++)
                modify[2][k][0] = prev[k];
        }

        else if(direction == '-'){
            char prev[3] = {modify[0][0][0], modify[0][1][0], modify[0][2][0]};

            for(int k=0; k<3; k++)
                modify[0][k][0] = modify[2][k][0];

            for(int k=0; k<3; k++)
                modify[2][k][0] = modify[1][k][0];

            for(int k=0; k<3; k++)
                modify[1][k][0] = modify[3][2-k][2];

            for(int k=0; k<3; k++)
                modify[3][k][2] = prev[2-k];
        }
    }

    if(dimension == 5){
        if(direction == '+'){
            char prev[3] = {modify[0][0][2], modify[0][1][2], modify[0][2][2]};

            for(int k=0; k<3; k++)
                modify[0][k][2] = modify[2][k][2];

            for(int k=0; k<3; k++)
                modify[2][k][2] = modify[1][k][2];

            for(int k=0; k<3; k++)
                modify[1][k][2] = modify[3][2-k][0];

            for(int k=0; k<3; k++)
                modify[3][k][0] = prev[2-k];
        }

        else if(direction == '-'){
            char prev[3] = {modify[0][0][2], modify[0][1][2], modify[0][2][2]};

            for(int k=0; k<3; k++)
                modify[0][k][2] = modify[3][2-k][0];

            for(int k=0; k<3; k++)
                modify[3][k][0] = modify[1][2-k][2];

            for(int k=0; k<3; k++)
                modify[1][k][2] = modify[2][k][2];

            for(int k=0; k<3; k++)
                modify[2][k][2] = prev[k];
        }
    }
}

void init(){
    for(int k=0; k<6; k++)
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                modify[k][i][j] = cube[k][i][j];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int tc; cin>>tc;
    for(int t=0; t<tc; t++){
        init();

        int n; cin>>n;
        for(int i=0; i<n; i++){
            string s; cin>>s;

            int direction = 0;
            if (s[0] == 'U') direction = 0;
            if (s[0] == 'D') direction = 1;
            if (s[0] == 'F') direction = 2;
            if (s[0] == 'B') direction = 3;
            if (s[0] == 'L') direction = 4;
            if (s[0] == 'R') direction = 5;
            rotate_dimension(direction, s[1]);
            rotate_cube(direction, s[1]);

        }
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                cout<<modify[0][i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
