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

Node* mergeLists(Node* l1,Node* l2){
    Node* temp = new Node(0);
    Node* curr = temp;

    while (l1 != NULL and l2 != NULL){
        if(l1->val <= l2->val){
            curr->next = l1;
            l1 = l1->next;
        }else{
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    while ( l1 != NULL ){
        curr->next = l1;
        l1 = l1->next;
        curr = curr->next;
    }
    while ( l2 != NULL ){
        curr->next = l2;
        l2 = l2->next;
        curr = curr->next;
    }
    
    return temp->next;

}

Node* sortList(Node* head) {

    if(head == NULL || head->next == NULL)
        return head;

    Node* temp = NULL;
    Node* slow = head;
    Node* fast = head;

    while ( fast != NULL  && fast->next != NULL){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    temp->next = NULL;
    Node* l1 = sortList(head);
    Node* l2 = sortList(slow);

    return mergeLists(l1,l2);

}




int32_t main(){
    
    Node* root = NULL;
    int n ;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        insertAtTail(root,x);
    }

    display(root);
    display(sortList(root));
    
    
    
    return 0;
}