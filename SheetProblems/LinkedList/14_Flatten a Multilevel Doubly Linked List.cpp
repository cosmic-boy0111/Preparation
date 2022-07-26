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
        node* child;
        node* prev;

        node(int data = 0){
            val = data;
            next = NULL;
            prev = NULL;
            child = NULL;
        }
};

class Node{
    public:
        int val;
        Node* next;

        Node(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(Node* &root,int val){
    if(root == NULL){
        root = new Node(val);
        return;
    }
    Node* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new Node(val); 
}

void display(node* root){
    while (root != NULL){
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;

}


#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);

node* flatten(node* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL and head->child == NULL) return head;
    node* temp = head;
    while (temp != NULL){
        if(temp->child == NULL){
            temp = temp->next;
            continue;
        }
        node* newTail = flatten(temp->child);
        node* preNext = temp->next;
        temp->next = newTail;
        newTail->prev = temp;
        temp->child = NULL;
        if(preNext != NULL){
            node* temp1 = newTail;
            while (temp1->next != NULL){
                temp1 = temp1->next;
            }
            temp1->next = preNext;
            preNext->prev = temp1;
        }
        temp = preNext;
    }

    return head;
    
}

int32_t main(){
    

    node* root = new node(1);
    root->next = new node(2);
    root->next->next = new node(3);
    root->next->next->next = new node(4);
    root->next->next->next->next = new node(5);
    root->next->next->next->next->next = new node(6);
    root->next->next->child = new node(7);
    root->next->next->child->next = new node(8);
    root->next->next->child->next->next = new node(9);
    root->next->next->child->next->next->next = new node(10);
    root->next->next->child->next->child = new node(11);
    root->next->next->child->next->child->next = new node(12);
    
    display(flatten(root));
    
    return 0;
}