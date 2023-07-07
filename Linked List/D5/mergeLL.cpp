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

//**********************************************************************************
Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* head = new Node(0);
        Node* curr = head;

        while(list1 != NULL && list2 != NULL){
            if(list1->data <= list2->data){
                curr->next = list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        if(list1 != NULL) curr->next = list1;
        if(list2 != NULL) curr->next = list2;
            
        return head->next;
    }
//**********************************************************************************

int main(){
    Node* node1 = new Node(3);
    Node* head = node1;
    insert(head,2,7);
    insert(head,3,10);

    cout<<endl;
    cout<<"Initial Linked list1: ";
    print(head);

    Node* node2 = new Node(1);
    Node* hhead = node2;
    insert(hhead,2,2);
    insert(hhead,3,5);
    insert(hhead,4,8);
    insert(hhead,5,10);

    cout<<endl;
    cout<<"Initial Linked list2: ";
    print(hhead);

    cout<<endl;
    cout<<"Merge list: ";
    print(mergeTwoLists(head,hhead));

    
    return 0;
}