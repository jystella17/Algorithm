// 좋다, 이분탐색
// Map이나 HashMap 사용하는 방법 찾아보기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, ans=0;
    vector<int> A;
    
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        A.push_back(tmp);
    }
    
    sort(A.begin(), A.end());
    
    for(int i=0; i<n; i++){
        int left = 0;
        int right = n-1;
        
        while(left < right){
            int sum = A[left] + A[right];
            
            if(sum == A[i]){
                if(left != i && right != i){
                    ans++;
                    break;
                }
                
                else if(left == i)
                    left++;
                
                else if(right == i)
                    right--;
            }
            
            else if(sum < A[i])
                left++;
            
            else
                right--;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
