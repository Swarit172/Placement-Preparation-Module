//Rotate List (Leetcode)
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

//***********************************************************************************************
Node* rotateLL(Node* head, int k){
    if(head==NULL || head->next==NULL) return head;
        Node* temp = head, *prev;
        
        int count=0;
        while(head){
            count++;
            head = head->next;
        }
        //k%count - is used bcoz if k=200000000(as per contraints given)

        head = temp;
        //for(int i=0;i<(k);i++) this will work for normal conditions
        for(int i=0;i<(k%count);i++){
            while(temp->next){
                prev = temp;
                temp = temp->next;
            }
            temp->next = head;
            prev->next = NULL;
            head = temp;
            prev = temp;
        }
        return head;
}
//***********************************************************************************************
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

    cout<<"Rotated list: ";
    print(rotateLL(head,2));
    
    return 0;
}