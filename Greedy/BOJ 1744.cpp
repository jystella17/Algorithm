// BOJ 1744 수 묶기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> sequence_positive;
    vector<int> sequence_negative;
    vector<int> answer;
    bool is_zero = false;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        
        if(tmp > 0 && tmp != 1)
            sequence_positive.push_back(tmp);
        
        else if(tmp == 0)
            is_zero = true;
        
        else if(tmp == 1)
            answer.push_back(tmp);
        
        else
            sequence_negative.push_back(tmp);
    }
    
    sort(sequence_positive.rbegin(), sequence_positive.rend());
    int size_p = sequence_positive.size();
    for(int i=0; i<size_p; i=i+2){
        if(i+1 != size_p){
            int tmp = sequence_positive[i] * sequence_positive[i+1];
            answer.push_back(tmp);
        }
        
        else
            answer.push_back(sequence_positive[i]);
    }
    
    sort(sequence_negative.begin(), sequence_negative.end());
    int size_n = sequence_negative.size();
    for(int i=0; i<size_n; i=i+2){
        if(i+1 != size_n){
            int tmp = sequence_negative[i] * sequence_negative[i+1];
            answer.push_back(tmp);
        }
        
        else if(i+1 == size_n && !is_zero)
            answer.push_back(sequence_negative[i]);
        
        else
            answer.push_back(0);
    }
    
    int sum = 0;
    for(int i=0; i<answer.size(); i++)
        sum += answer[i];
    
    cout<<sum<<endl;
    return 0;
}
