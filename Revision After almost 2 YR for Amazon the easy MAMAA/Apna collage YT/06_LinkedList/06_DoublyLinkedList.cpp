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

class Node {
    public:
        int val;
        Node* next;
        Node* prev;

        Node( int data ){
            val = data;
            next = nullptr;
            prev = nullptr;
        }
};

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    if(head == nullptr){
        head = n;
        return;
    }

    n->next = head;
    head->prev = n;

    head = n;
}

void insertAtTail(Node* &head, int val){
    if(head == nullptr){
        insertAtHead(head, val);
        return;
    }
    
    Node* temp = new Node(val);
    Node* demoHead = head;
    while (demoHead->next != nullptr){
        demoHead = demoHead->next;
    }

    demoHead->next = temp;
    temp->prev = demoHead;
}

void deleteNode(Node* &head, int val){
    Node* temp = head;
    if(temp->val == val){
        temp->next->prev = nullptr;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    while (temp->val != val){
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    if(temp->next){
        temp->next->prev = temp->prev;
    }
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;    
}

void travel(Node* head){
    while (head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }cout << endl;
}

int32_t main(){

    Node* head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    insertAtHead(head, 4);

    deleteNode(head, 3);

    travel(head);
    
}