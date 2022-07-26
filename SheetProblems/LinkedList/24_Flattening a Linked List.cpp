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
        node* bottom;

        node(int val = 0){
            data = val;
            next = NULL;
            bottom = NULL;
        }
};

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtBottom(node* &root,int val){
    if(root == NULL){
        root = new node(val);
        return;
    }
    node* temp = root;
    while (temp->bottom != NULL){
        temp = temp->next;
    }

    temp->next = new node(val); 
}

void display(node* root){
    while (root != NULL){
        cout << root->data << " ";
        root = root->bottom;
    }

    cout << endl;

}


#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);


node* mergeTwoSortedList(node* first,node* second){
    if(!first) return second;
        
    if(!second) return first;
        
    if(first -> data < second -> data){
        first -> bottom = mergeTwoSortedList(first -> bottom, second);
        return first;
    }
    second -> bottom = mergeTwoSortedList(first, second -> bottom);
    return second;
}

node *flatten(node *root){

    if(root == NULL || root->next == NULL) 
        return root;
    
    node* down = root;
    node* next = flatten(root->next);

    return mergeTwoSortedList(down,next);

}

int32_t main(){
    

    
    
    return 0;
}