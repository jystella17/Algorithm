// 프로그래머스 Lv.2 올바른 괄호

#include <string.h>
#include <stack>
#include <iostream>
using namespace std;

bool solution(string s){
    bool answer = true;
    char parentheses[100000];
    strcpy(parentheses, s.c_str());
    
    stack<char> ss;
    for(int i=0; i<s.length(); i++){
        if(parentheses[i] == '(')
            ss.push(parentheses[i]);
        
        else{
            if(ss.size() > 0) ss.pop();
            else{
                answer = false;
                break;
            }
        }
    }
    
    if(ss.size() > 0) answer = false;

    return answer;
}
