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
Node* intersectionOfTwoLL(Node* head,Node* hhead){
    
    //difference
    int l1=0,l2=0;
    Node* temp1,*temp2;
    temp1 = head;
    temp2 = hhead;
    while(head || hhead){
        if(head){
            l1++;
            head = head->next;
        }
        if(hhead){
            l2++;
            hhead = hhead->next;
        }
    }
    int diff = l1-l2;

    head = temp1;
    hhead = temp2;
    if(diff<0){
        while(diff++ != 0){
            hhead = hhead->next;
        }
    }
    else{
        while(diff-- != 0){
            head = head->next;
        }
    }

    while(head){
        if(head == hhead){
            return head;
        }
        head =head->next;
        hhead = hhead->next;
    }
    return head;
}
//**********************************************************************************

int main(){
    Node* node1 = new Node(4);
    Node* head = node1;
    insert(head,2,1);
    insert(head,3,8);
    insert(head,4,4);
    insert(head,5,5);
    node1 = node1->next->next;

    cout<<endl;
    cout<<"Initial Linked list1: ";
    print(head);

    Node* node2 = new Node(5);
    Node* hhead = node2;
    insert(hhead,2,6);
    insert(hhead,3,1);
    node2->next = node1;
    // insert(hhead,4,8);
    // insert(hhead,5,4);
    // insert(hhead,6,5);

    cout<<endl;
    cout<<"Initial Linked list2: ";
    print(hhead);

    cout<<endl;
    Node* ele = intersectionOfTwoLL(head,hhead);
    if(ele == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<ele->data<<endl;
    return 0;

    
    return 0;
}