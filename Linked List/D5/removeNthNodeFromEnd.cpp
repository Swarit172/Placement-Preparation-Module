#include<bits/stdc++.h>
using namespace std;

class Node{
    //node initialization
    public:
    int data;
    Node* next;

    //constructor insertion
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //constructor deletion
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

//print of linked list
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//insertion
void insert(Node* &head,int position,int d){
    Node* temp = head;
    int cnt=1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    Node* new_node = new Node(d);
    new_node->next = temp->next;
    temp->next = new_node;
}

//***********************************************************************************
Node* removefromEnd(Node* &head,int n){
    Node* fast=head,*slow=head;

    for(int i=0;i<n;i++){
        fast = fast->next;
    }

    if(!fast) return fast->next;

    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    cout<<"Deleted node is: "<<slow->next->data<<endl;
    slow->next = slow->next->next;
    return head;
}
//***********************************************************************************

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insert(head,2,8);
    insert(head,3,12);
    insert(head,4,6);
    insert(head,5,31);
    insert(head,6,20);

    cout<<endl;
    cout<<"Initial Linked list: ";
    print(head);

    print(removefromEnd(head,2));
    
    return 0;
}