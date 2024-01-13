// 백준 G2 피자 판매
// 누적합 응용

#include <iostream>
using namespace std;

int main(){
    int order; cin>>order;
    int m, n; cin>>m>>n;

    // 각 크기별로 몇 개의 서로 다른 모양이 존재하는지 저장
    int pa[1000001], pb[1000001];
    pa[0] = 1; pb[0] = 1;

    // 1번부터 i번 조각까지 연속적으로 골랐을 때 조각들의 크기 합 저장 (누적합)
    int sumA[1001], sumB[1001];
    sumA[0] = 0; sumB[0] = 0;
    
    for(int i=1; i<=m; i++){
        int piece; cin>>piece;
        sumA[i] = (sumA[i-1] + piece);
    }
    
    for(int i=1; i<=n; i++){
        int piece; cin>>piece;
        sumB[i] = (sumB[i-1] + piece);
    }
    
    for(int i=1; i<=m; i++){
        // i > j인 경우 (ex. i = 5, j = 2 => 5, 1, 2번 조각 선택)
        // 누적합 배열의 인덱스 변형 -> 전체 조각을 골랐을 때의 누적합 - i~m번 조각을 골랐을 때의 누적합 + 1~j번 조각을 골랐을 때의 누적합
        for(int j=1; j<i; j++){
            int size = (sumA[m] - sumA[i-1] + sumA[j]);
            pa[size]++;
        }

        // j >= i인 경우 (ex. i = 3 & j = 4 => 3~4번 조각 선택)
        // 누적합 배열의 인덱스 그대로 사용
        for(int j=i; j<=m; j++){
            int size = (sumA[j] - sumA[i-1]);
            pa[size]++;
        }
    }

    // 누적합 배열의 인덱스 변형 -> 전체 조각을 골랐을 때의 누적합 - i~n번 조각을 골랐을 때의 누적합 + 1~j번 조각을 골랐을 때의 누적합
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            int size = (sumB[n] - sumB[i-1] + sumB[j]);
            pb[size]++;
        }
        
        for(int j=i; j<=n; j++){
            int size = (sumB[j] - sumB[i-1]);
            pb[size]++;
        }
    }
    // 모든 조각을 고르는 경우, 어떤 조각을 먼저 골라도 같은 형태의 그림 => 1로 셋팅
    pa[sumA[m]] = 1; pb[sumB[n]] = 1;
    
    int answer = 0;
    int start = 0, end = order;
  
    // 피자 a, b에서 각각 크기 0/order, 1/order-1, .... order/0 만큼 고르는 경우
    while(start <= order){
        answer += (pa[start] * pb[end]);
        start++; end--;
    }
    
    cout<<answer<<"\n";
    return 0;
}
