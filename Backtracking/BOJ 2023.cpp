#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;

int isPrime(int num){
    for(int i=2; i<=sqrt(num); i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

void isAmazingPrime(int num, int len){
    if(len == n){
        cout<<num<<endl;
        return;
    }
    
    for(int i=1; i<=9; i++){
        if(isPrime(10*num + i))
            isAmazingPrime(10*num + i, len+1);
    }
    return;
}

int main(){
    cin>>n;
    
    isAmazingPrime(2,1);
    isAmazingPrime(3,1);
    isAmazingPrime(5,1);
    isAmazingPrime(7,1);
    
    return 0;
}
