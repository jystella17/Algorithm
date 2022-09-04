#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {

    int n, k, i;
    char str[500001];
    deque<char> dq;

    cin>>n>>k;
    cin>>str;

    for (i = 0; i < n; i++) {
        while(k && !dq.empty() && dq.back() < str[i]) {
            dq.pop_back();
            k--;
        }
        dq.push_back(str[i]);
    }

    for (i = 0; i < dq.size() - k; i++) {
        cout<<dq[i];
    }

    cout<<endl;

    return 0;
}
