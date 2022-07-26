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

stack<int> takeStack(Node* l){
    stack<int> s;
    while (l != NULL){
        s.push(l->val);
        l = l->next;
    }

    return s;
    
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    
    stack<int> s1 = takeStack(l1);
    stack<int> s2 = takeStack(l2);

    Node* head = NULL;
    int carry  = 0;

    while ( !s1.empty() || !s2.empty() || carry ){
        int sum = carry;
        if(!s1.empty()){
            sum += s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            sum+=s2.top();
            s2.pop();
        }
        Node* n = new Node(sum%10);
        n->next = head;
        head = n;
        carry = sum/10;
    }


    return head;
    
    
}

int32_t main(){
    
    Node* l1 = NULL;
    Node* l2 = NULL;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        insertAtTail(l1,x);
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        insertAtTail(l2,x);
    }

    display(l1);
    display(l2);

    display(addTwoNumbers(l1,l2));
    
    
    
    return 0;
}