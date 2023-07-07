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

//*****************************************************************************************************
Node* AddTwoNum(Node* head, Node* hhead){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    int carry = 0;
    while(head || hhead || carry){
        int sum=0;
        if(head!=NULL){
            sum += head->data;
            head = head->next;
        }

        if(hhead!=NULL){
            sum += hhead->data;
            hhead = hhead->next;
        }

        sum = sum + carry;
        carry = sum/10;
        Node* list = new Node(sum%10);
        temp->next = list;
        temp = temp->next;
    }

    return dummy->next;
}

//*****************************************************************************************************

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insert(head,2,8);
    insert(head,3,12);

    cout<<endl;
    cout<<"Initial Linked list1: ";
    print(head);

    Node* node2 = new Node(7);
    Node* hhead = node2;
    insert(hhead,2,6);
    insert(hhead,3,1);
    insert(hhead,4,8);

    cout<<endl;
    cout<<"Initial Linked list2: ";
    print(hhead);

    cout<<endl<<"Sum of both linked list: ";
    print(AddTwoNum(head,hhead));

    return 0;
}