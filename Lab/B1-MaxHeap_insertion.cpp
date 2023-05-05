#include<bits/stdc++.h>
using namespace std;
void insert(int *tree , int data , int i){
    tree[i] = data ; 
    int ptr = i ;
    int par = (i-1)/2 ;
    while(ptr > 0){
        if(tree[ptr] > tree[par]){
            swap(tree[ptr] , tree[par]) ;
            ptr = par ;
            par = (ptr-1)/2 ;
        }
        else break ;
    }
}
int main(){
    int n ; cin >> n ;
    int tree[4*n] ;
    for(int i = 0 ; i < n ; i++){
        int data ; cin >> data ;
        insert(tree , data , i) ;
    }
    for(int i = 0 ; i < n ; i++) cout << tree[i] << " " ;
}