// NCPC 2019 (Nordic Collegiate Programming Contest)
// Problem K (Keep it cool)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, s, d;
    cin>>n>>m>>s>>d;

    // pair : num of soda exists, original index
    priority_queue<pair<int, int>> fridge;
    int slots[100];

    for(int i=0; i<s; i++){
        int soda; cin>>soda;
        // sort fridge by the number of current soda in each slot
        // priority queue is max heap in c++, so multiply -1 to the num. of soda
        // to make min heap (ascending order)
        fridge.push(make_pair(-soda, i));
        slots[i] = soda;
    }

    while(n > 0 && !fridge.empty()){
        int current_soda = -fridge.top().first;
        int idx = fridge.top().second;
        fridge.pop();

        // if the slot is full
        if(current_soda == d) continue;

        // if the slot is not full, fill empty spaces with new soda 
        // until all new soda glasses are put in the fridge
        int new_soda = min(d - current_soda, n);
        n -= new_soda;
        // to distinguish slots have new sodas, make the value of the slot to minus
        // when you put new soda into each slot
        slots[idx] = -new_soda;
    }

    int sum = 0;
    for(int i=0; i<s; i++){
        if(slots[i] <= 0) continue;
        
        // slots where new sodas are added should not be selected
        // to make every student m get cold soda
        // and because slot[i] < 0 if you put new soda in slot i
        // so student can choose slot i when slot[i] > 0
        sum += slots[i];
        // the output should be the number of new sodas added to each slot,
        // so update slots[i] to 0
        slots[i] = 0;
    }

    // if students cannot choose m cold sodas from fridge
    // = if student should choose some slots where new sodas exist
    if(sum < m){
        cout<<"impossible"<<"\n";
    }
    else{
        for(int i=0; i<s; i++){
            if(slots[i] < 0)
                slots[i] = -slots[i];

            cout<<slots[i]<<" ";
        }
    }
    return 0;
}
