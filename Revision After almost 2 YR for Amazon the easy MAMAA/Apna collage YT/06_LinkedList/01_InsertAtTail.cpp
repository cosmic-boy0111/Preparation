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
        int data;
        node* next;
        node* left;
        node* right;

        node(int val = 0){
            data = val;
            next = nullptr;
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
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = nullptr;
        }

};


// Node* insertAtTail(Node* &root, int val){

//     // if(root == nullptr){
//     //     Node* rc = new Node(val);
//     //     return rc;
//     // }

//     // Node* hypo = insertAtTail(root->next, val);
//     // root->next = hypo;

//     // return root;

    
//     Node* n = new Node(val);
//     if(root == nullptr){
//         root = n;
//         return root;
//     }
//     Node* temp = root;

//     while ( temp->next != nullptr ){
//         temp = temp->next;
//     }
    
//     temp->next = n;

//     return root;

// }

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head == nullptr){
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

int32_t main(){

    node* root = new node(1);
    root->next = new node(2);
    
    insertAtHead(root, 0);
    node* newRoot = root;
    while (newRoot != nullptr){
        cout << newRoot->data << " ";
        newRoot = newRoot->next;
    }
    

}