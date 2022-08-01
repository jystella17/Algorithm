#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
    int answer=0;
    int size = s.length();

    for(int len=size; len>1; len--){
        for(int start=0; start<=size-len; start++){
            bool isPalindrome = true;

            for(int i=0; i<len/2; i++){
                if(s[start+i] != s[start+len-i-1]){
                    isPalindrome = false;
                    break;
                }
            }

            if(isPalindrome)
                return len;
        }
    }
}
