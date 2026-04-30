#include<bits/stdc++.h>
using namespace std;    
struct Node{
    int data;
    Node* next;
    Node(int data1){
    data=data1;
    next=nullptr;
}
};

void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    vector<int> arr={2,5,8,7};
    Node* head= convertarrtoLL(arr);
    printLL(head);
    return 0;
}