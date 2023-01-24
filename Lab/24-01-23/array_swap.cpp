// Take a square matrix input , and transpose it passing it to a function, without using multiple array 
#include<bits/stdc++.h>
using namespace std;
void replace(int *a , int r){
    for(int i = 0 ; i < r ; i++){
        for(int j = i+1 ; j < r ; j++){
            swap(*(a + (i*r + j)) , *(a + (j*r + i))) ;

            /** without swap() #1
              int *x = (a + (i*r + j)) ;
              int *y = (a + (j*r + i)) ;

              *x = *x + *y ;
              *y = *x - *y ;
              *x = *x - *y ;  
            **/

            /** without swap() #2 
               int x = *(a + (i*r + j)) ;
               int y = *(a + (j*r + i)) ;
               *(a + (i*r + j)) = y ;
               *(a + (j*r + i)) = x ; 
            **/   
        }
    }
}
int main(){
    int r ; cin >> r ;
    int a[r][r] ;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r ; j++){
            cin >> a[i][j] ;
        }
    }

    replace(&a[0][0] , r) ;
    cout << endl ;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r ; j++){
            cout << a[i][j] << " " ;
        }
        cout << endl ;
    }

}