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
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
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

void display(Node* root){
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

Node* reverseList(Node* head){
    Node* pre = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr){
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
    
}

void reorderList(Node* head) {  
    Node* slow = head;
    Node* fast = head->next;

    if(!fast) return;

    while ( fast != NULL and fast->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;

    fast = reverseList(fast);

    slow = head;

    while (slow){
        Node* temp = slow->next;
        slow->next = fast;
        Node* temp1 = fast != NULL ? fast->next : fast;
        if(fast){
            fast->next = temp;
        }
        fast = temp1;
        slow = temp;
    }
    

}

int32_t main(){
    
    
    Node* root = NULL;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        insertAtTail(root,x);
    }

    reorderList(root);
    display(root);
    
    
    return 0;
}