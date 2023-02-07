#include<bits/stdc++.h>
using namespace std;
char stk[100] ;
int mx = 50 ;
int idx = -1 ;
void push(char c){
    idx++ ; 
    stk[idx] = c ;
}
void pop(){
    idx-- ;
}
char top(){
    return stk[idx] ;
}
bool is_emt(){
    if(idx == -1) return true ;
    return false ;
}

int main(){
    string s ; cin >> s ;
    for(int i = 0 ; i < s.length() ; i++){
        if(is_emt() || s[i] == '(' || s[i] == '{' || s[i] == '[' ) push(s[i]) ;
        
        else if(s[i] == ')' && top() == '(' || 
                s[i] == ']' && top() == '[' || 
                s[i] == '}' && top() == '{' ) pop() ;
    }

    if(is_emt()) cout << "\nBalanced" ;
    else cout << "\nNot Balanced" ;
}