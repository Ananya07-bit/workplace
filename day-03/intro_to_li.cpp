#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node*node;
void insert(int val){
    Node* temp= new Node();
    temp->data=val;
    temp->next=node;
    node=temp;
}
void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    }  
int main(){
    Node* head= new Node();
    insert(7);
    insert(-3);  
    insert(5);
    printLL(node);
    return 0;
}
