#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int info ;
    node *prev , *next ;
};
void insert(node **head , int data){
    node *ptr = new node() ;
    ptr->info = data ;
    ptr->prev = ptr->next = NULL ;
    if(*head == NULL) *head = ptr ;
    else{
        node *temp = *head ;
        while(temp->next != NULL) temp = temp->next ;
        ptr->prev = temp ;
        temp->next = ptr ;
    }
}
void reverse(node **head){
    node *temp = *head ;
    node *ptr = NULL ;
    while(temp != NULL){
        ptr = temp->prev ;
        temp->prev = temp->next ;
        temp->next = ptr ;
        temp = temp->prev ; 
    }
    *head = ptr->prev ;
}

void display(node **head){
    node *temp = *head ;
    while(temp != NULL){
        cout << temp->info;
        if(temp->next != NULL) cout << " <-> " ;
        temp = temp->next ;
    }
    cout << endl ;
}
int main(){
    node *head = NULL ;
    int n ; cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int data ; cin >> data ;
        insert(&head , data) ;
    }

    cout << "Original : \n"; 
    display(&head) ;

    cout << "Reversed : \n" ;
    reverse(&head) ;
    display(&head) ;
}