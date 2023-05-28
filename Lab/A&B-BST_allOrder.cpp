#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data ;
    Node* left ;
    Node* right ;
    Node(int d){
        data = d ;
        left = NULL ;
        right = NULL ;
    }
};

// Recursion insert

void insert(Node **head , int data){
    if(*head == NULL){
        *head = new Node(data) ;
        return ;
    }
    if(data < (*head)->data){
        insert(&((*head)->left) , data) ;
    }
    else{
        insert(&((*head)->right) , data) ;
    }
}

// Loop insert

void loop_insert(Node **head , int data){
    Node *temp = new Node(data) ;
    if(*head == NULL){
        *head = temp ;
        return ;
    }
    Node *cur = *head ;
    while(cur != NULL){
        if(data < cur->data){
            if(cur->left == NULL){
                cur->left = temp ;
                return ;
            }
            cur = cur->left ;
        }
        else{
            if(cur->right == NULL){
                cur->right = temp ;
                return ;
            }
            cur = cur->right ;
        }
    }
}

void preOrder(Node *head){
    if(head == NULL) return ;
    cout << head->data << " " ;
    preOrder(head->left) ;
    preOrder(head->right) ;
}

void inOrder(Node *head){
    if(head == NULL) return ;
    inOrder(head->left) ;
    cout << head->data << " " ;
    inOrder(head->right) ;
}

void postOrder(Node *head){
    if(head == NULL) return ;
    postOrder(head->left) ;
    postOrder(head->right) ;
    cout << head->data << " " ;
}

int main(){
    int n ; 
    cin >> n ;
    Node *root = NULL ;
    int data ;
    while(n--){
        cin >> data ;
        loop_insert(&root , data) ;
    }

    cout << "PreOrder: " ;
    preOrder(root) ;
    cout << endl ;
    cout << "InOrder: " ;
    inOrder(root) ;
    cout << endl ;
    cout << "PostOrder: " ;
    postOrder(root) ;

}