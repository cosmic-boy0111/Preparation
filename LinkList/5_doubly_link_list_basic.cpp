#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pi pair<int,int>
#define mi map<int,int>
#define umi unordered_map<int,int>
#define qi queue<int>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff first
#define ss second 
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e6, MOD = 1e9+7;
void printBinary(int n){
    for(int i=10;i>=0;i--){
        if((n>>i) & 1) cout << 1;
        else cout << 0;
    }cout << endl;
}
class node{
    public:
        int val;
        node* prev;
        node* next;

        node(int data = 0){
            val = data;
            prev = NULL;
            next = NULL;
        }
};


void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    if(head != NULL)
        head->prev = n;
    head = n;
}


void insertAtTail(node* &head,int val){

    if(head == NULL){
        insertAtHead(head,val);
        return;
    }

    node* n = new node(val);

    node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
    
}


void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion(node* &head,int pos){

    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int cnt = 1;
    while (temp != NULL and cnt != pos){
        temp = temp->next;
        cnt++;
    }

    temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    
}

void display(node* head){
    node* temp = head;
    while (temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
    
}

int main(){

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    // display(head);

    insertAtHead(head,7);

    deletion(head,5);
    deletion(head,1);

    display(head);
    
    
    
    return 0;
}