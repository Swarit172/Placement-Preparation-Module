#include<bits/stdc++.h>
using namespace std;

bool validParen(string st){
    stack<int> s;
    for(auto ch : st){
        if(ch == '(' or ch == '[' or ch == '{')
            s.push(ch);
        else{
            if(s.empty() or (ch==')' && s.top()!='(') or (ch=='}' && s.top()!='{') or (ch==']' && s.top()!='['))
                return false;
            else{
                s.pop();
            }
        }
    }
    return (s.empty()) ? true : false;
}

int main(){
    string st = "({]})";
    if(validParen(st)){
        cout<<st<<" - is a valid palindrome";
    }
    else{
        cout<<st<<" - not a valid palindrome";
    }
}