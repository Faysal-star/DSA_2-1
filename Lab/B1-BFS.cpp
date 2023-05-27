#include<bits/stdc++.h>
using namespace std;
const int N = 200 ;
int mat[N+1][N+1] ;
int que[N] ;
bool vis[N] ;
int st = 0 ;
int ed = 0 ;

void push(int d){
    que[ed] = d ;
    ed++ ;
}
int pop(){
    int d = que[st] ;
    st++ ;
    return d ;
}
bool is_empt(){
    if(st == ed) return 1 ;
    return 0 ;
}

void bfs(int v , int n){
    push(n);
    while(!is_empt()){
        int d = pop() ;
        if(!vis[d]){
            vis[d] = 1 ;
            cout << d << " " ;

            for(int i = 0 ; i <= v ; i++){
                if(mat[d][i] == 1){
                    push(i) ;
                }
            }
        }
    }
}

int main(){
    int v , e ; 
    cin >> v >> e ;
    for(int i = 0 ; i < e ; i++){
        int x , y ;
        cin >> x >> y ;
        mat[x][y] = 1 ;
    }

    int ver ;
    cin >> ver ;
    cout << ver << " -> " ;
    bfs(v , ver) ;
}

/* Sample input
4 7

0 0
0 2
1 0
1 2
2 1
2 3
3 3

2
*/

/* Output 
2 -> 2 1 3 0
*/