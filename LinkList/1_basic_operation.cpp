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
        node* next;

        node(int data = 0){
            val = data;
            next = NULL;
        }
};


void insertAtHead(node* &head,int data){
    node* n = new node(data);
    n->next = head;
    head = n;
}


void insertAtTail(node* &head,int data){
    node* n = new node(data);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    
}

void display(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
    
}

bool search(node* head,int key){
    node* temp = head;
    while (temp != NULL)
    {
        if(temp->val == key)
            return true;
        temp = temp->next;
    }

    return false;
    
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node* &head,int val){

    if(head == NULL){
        return;
    }

    if(head->val == val){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while (temp->next->val != val){
        temp = temp->next;
        if(temp->next == NULL)
            return;
    }

    node* todelete = temp->next;

    temp->next = temp->next->next;

    delete todelete;
    
}

int main(){
    

    node* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);

    // display(head);

    insertAtHead(head,4);

    display(head);

    // cout << search(head,3);

    deletion(head,3);
    display(head);
    
    
    
    return 0;
}