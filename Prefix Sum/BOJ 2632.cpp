// 누적합 응용 & 슬라이딩 윈도우

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int order, m, n, answer = 0;
    cin>>order; cin>>m>>n;
    
    vector<int> pizza_a; vector<int> pizza_b;
    vector<int> sum_a; vector<int> sum_b;

    for(int i=0; i<m; i++){
        int tmp; cin>>tmp;
        pizza_a.push_back(tmp);
    }
    for(int i=0; i<m-1; i++)
        pizza_a.push_back(pizza_a[i]);

    for(int i=0; i<n; i++){
        int tmp; cin>>tmp;
        pizza_b.push_back(tmp);
    }
    for(int i=0; i<n-1; i++)
        pizza_b.push_back(pizza_b[i]);

    // 누적합 구하기(단순 누적합 X) => 피자 A, B 기준 나올 수 있는 피자조각 크기의 합 저장
    // 조각 크기의 합이 같더라도 다른 조각들로 구성될 수 있음 => 중복저장
    for(int piece=1; piece<=m; piece++){
        int size = m;
        if(piece != 1 && piece != m) 
            size += (piece-1);
        
        int partial_sum = 0;
        for(int i=0; i<piece; i++)
            partial_sum += pizza_a[i];
        
        for(int i=0; i<=size-piece; i++){
            if(i == 0){
                if(partial_sum <= order && partial_sum > 0)
                    sum_a.push_back(partial_sum);
            }

            else{
                partial_sum -= pizza_a[i-1]; 
                partial_sum += pizza_a[i+piece-1];

                if(partial_sum <= order && partial_sum > 0)
                    sum_a.push_back(partial_sum);
            }
        }
    }
    
    for(int piece=1; piece<=n; piece++){
        int size = n;
        if(piece != 1 && piece != n) 
            size += (piece-1);
        
        int partial_sum = 0;
        for(int i=0; i<piece; i++)
            partial_sum += pizza_b[i];
        
        for(int i=0; i<=size-piece; i++){
            if(i == 0){
                if(partial_sum <= order && partial_sum > 0)
                    sum_b.push_back(partial_sum);
            }
            
            else{
                partial_sum -= pizza_b[i-1]; 
                partial_sum += pizza_b[i+piece-1];

                if(partial_sum <= order && partial_sum > 0)
                    sum_b.push_back(partial_sum);
            }
        }
    }
    
    sort(sum_a.begin(), sum_a.end());
    sort(sum_b.begin(), sum_b.end());
        
    for(int i=0; i<sum_a.size(); i++){
        if(sum_a[i] == order)
            answer += 1;
            
        else if(sum_a[i] > order)
            continue;
        
        else{
            int diff = (order - sum_a[i]);
            if(binary_search(sum_b.begin(), sum_b.end(), diff))
                answer += 1;
        }
    }

    cout<<answer<<"\n";
    return 0;
}
