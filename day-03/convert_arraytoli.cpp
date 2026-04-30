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
Node* convertarrtoLL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    vector<int> arr={2,5,8,7};
    Node* head= convertarrtoLL(arr);
    printLL(head);
    return 0;
}