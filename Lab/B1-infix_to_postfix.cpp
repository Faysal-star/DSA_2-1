#include<bits/stdc++.h>
using namespace std ;
char stk[100] ;
int top_i = -1 ;
void push(char c){
    top_i++ ;
    stk[top_i] = c ;
}
void pop(){
    top_i-- ;
}
char top(){
    return stk[top_i] ;
}

int pre(char c){
    if(c == '^') return 3 ;
    if(c == '*' || c == '/') return 2 ;
    if(c == '+' || c == '-') return 1 ;
    return 0 ;
}

string inf_to_post(string in){
    string post = "" ;
    int len = in.length() ;
    for(int i = 0 ; i < len ; i++){
        if(in[i] == '('){
                push('(') ;
        }
        else if(in[i] == ')'){
            while(top() != '('){
                post+= top() ;
                pop() ;
            }
            pop() ;
        }
        else if((in[i] >= 'a' && in[i] <= 'z') || (in[i] >= 'A' && in[i] <= 'Z')){
            post+= in[i] ;
        }
        else{
            while(pre(top()) >= pre(in[i])){
                post += top() ;
                pop() ;
            }
            push(in[i]) ;
        }
    }
    return post ;
}


int main(){
    string inf ;
    cout << "Insert Infix Expression : " ;
    cin >> inf ;
    string post = inf_to_post("("+inf+")") ;
    cout << "Postfix Expression : " ;
    cout << post << endl ;
}
