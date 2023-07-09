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

//********************************************************************************************************

    bool checkPalin(vector<int>& arr){
        int start = 0;
        int end = arr.size()-1;
        while(start < end){
            if(arr[start] == arr[end]){
                start++;;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(Node* head) {
        vector<int> arr;
        //ListNode* temp = head;
        while(head){
            arr.push_back(head->data);
            head = head->next;
        }
        return checkPalin(arr);
    }
//********************************************************************************************************

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insert(head,2,8);
    insert(head,3,12);
    insert(head,4,12);
    insert(head,5,8);
    insert(head,6,10);

    cout<<endl;
    cout<<"Initial Linked list: ";
    print(head);
    cout<<endl;


    cout<<" Palindrome: "<<isPalindrome(head);
    return 0;
}