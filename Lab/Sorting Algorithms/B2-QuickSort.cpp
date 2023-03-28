#include<bits/stdc++.h>
using namespace std;

void swp(int *a , int *b){
    int t = *a ;
    *a = *b ;
    *b = t ;
}

int partition(int *a , int l , int r){
    int pivot = a[r] ;
    int i = l - 1 ;
    for(int j = l ; j < r ; j++){
        if(a[j] < pivot) swp(&a[++i] , &a[j]) ;
    }

    swp(&a[i+1] , &a[r]) ;
    return i+1 ;
}

void QuickSort(int *a , int l , int r){
    if(l >= r) return ;

    int pi = partition(a , l , r) ;
    QuickSort(a , l , pi-1) ;
    QuickSort(a , pi+1 , r) ;
}
int main(){
    int n ; cin >> n ;
    int ar[n];
    for(int i = 0 ; i < n ; i++) cin >> ar[i] ;
    QuickSort(ar , 0 , n-1) ;
    for(int i = 0 ; i < n ; i++) cout << ar[i] << " " ;
}