#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int lower[500001]; // 석순
    int upper[500001]; // 종유석
    vector<int> destroy;

	int n, h, val;
	cin>>n>>h;
    
	for(int i=0; i<n; i++){
		cin>>val;
		if (i % 2 == 0) 
            lower[val]++;
		else 
            upper[val]++;		
	}
    
	for(int i=h-1; i>=1; i--){
		lower[i] += lower[i + 1]; // 각 길이에 따라 부수는 석순의 수 (누적합)
		upper[i] += upper[i + 1]; // 각 길이에 따라 부수는 종유석의 수 (누적합)
	}
    
	// 높이 i일 때 파괴해야 하는 석순&종유석의 수
	for(int i=1; i<=h; i++)
		destroy.push_back(lower[i] + upper[h - i + 1]);
    
	sort(destroy.begin(), destroy.end());
    
	int num_interval = 1;
	int answer = destroy[0];
	for(int i=1; i<destroy.size(); i++){
		if (destroy[i] == answer) 
            num_interval++;	
		else 
            break;
	}
	cout<<answer<<" "<<num_interval<<endl;
	return 0;
}
