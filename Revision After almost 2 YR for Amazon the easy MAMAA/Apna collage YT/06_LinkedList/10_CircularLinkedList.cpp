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
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            left = NULL;
            right = NULL;
        }
};

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head == nullptr){
        head = n;
        n->next = head;
        return;
    }

    node* temp = head;

    while (temp->next != head){
        temp = temp->next;
    }

    n->next = head;
    temp->next = n;
    head = n;
}

void insertAtTail(node* &head, int val){
    
    if(head == nullptr){
        insertAtHead(head, val);
        return;
    }
    
    node* n = new node(val);
    node* temp = head;

    while (temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void deleteHead(node* &head){
    node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }

    node* newHead = head->next;
    temp->next = newHead;

    delete head;

    head = newHead;
    
}

void deleteNode(node* &head, int val){

    if(head->val == val){
        deleteHead(head);
        return;
    }   
    node* temp = head;
    while(temp->next->val != val){
        temp = temp->next;
    }

    node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

}

void display(node* head){
    node* temp = head;
    while (temp->next != head){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val << " ";
    cout << endl;
    
}



int32_t main(){

    node* head = nullptr;
    vector<int> v = {1, 2, 3, 4};

    for(auto& x : v){
        insertAtTail(head, x);
    }

    insertAtHead(head, 5);

    display(head);

    deleteNode(head, 5);

    display(head);

}