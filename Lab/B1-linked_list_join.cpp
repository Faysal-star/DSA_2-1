#include<bits/stdc++.h>
using namespace std ;
class node{
public:
    int info ;
    node *link ;
};

void creation(node **head , int item){
    node *ptr = new node() ;
    ptr->info = item ;
    ptr->link = NULL ;

    if(*head == NULL){
        *head = ptr ;
        return ;
    }
    else{
        node *temp = *(head) ;
        while(temp->link != NULL) temp = temp->link ;
        temp->link = ptr ;
        return ;
    }
}

void display(node **head){
    node *temp = *head ;
    while(temp != NULL){
        cout << temp->info << " -> " ;
        temp = temp -> link ;
    }
    cout << endl ;
}

int first_ins(node **head , int item , int n){
    node *ptr = new node() ;
    ptr->info = item ;
    ptr->link = *head ;
    *head = ptr ;
    return n+1 ;

}

int last_ins(node **head , int item , int n){
    node *ptr = new node() ;
    ptr->info = item ;
    ptr->link = NULL ;

    if(*head == NULL){
        *head = ptr ;
        return n+1 ;
    }
    else{
        node *temp = *(head) ;
        while(temp->link != NULL) temp = temp->link ;
        temp->link = ptr ;
        return n+1;
    }
}

int mergee(node **head1 , int n , node **head2 , int m){
    node *temp = *head1 ;
    while(temp->link != NULL) temp = temp->link ;
    temp->link = *head2 ;
    return m+n ;
}

int main(){
    node *head1 = NULL ;
    node *head2 = NULL ;
    int item ;
    cout << "For list 1 : \n" ;
    int n ; cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> item ;
        creation(&head1 , item) ;
    }
    display(&head1) ;

    cout << "For list 2 : \n" ;
    int m ; cin >> m ;
    for(int i = 0 ; i < m ; i++){
        cin >> item ;
        creation(&head2 , item) ;
    }
    display(&head2) ;
    cout << "Merged\n" ;

    n = mergee(&head1 , n , &head2 , m) ;
    display(&head1) ;

    cout << "Item to insert at first : ";
    cin >> item ;
    n = first_ins(&head1 , item , n) ;
    display(&head1) ;

    cout << "Item to insert at last : ";
    cin >> item ;
    n = last_ins(&head1 , item , n) ;
    display(&head1) ;
    
}
