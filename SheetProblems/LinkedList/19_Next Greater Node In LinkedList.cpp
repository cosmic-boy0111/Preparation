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
        node* left;
        node* right;

        node(int val = 0){
            data = val;
            left = NULL;
            right = NULL;
        }
};

class Node{
    public:
        int data;
        Node* next;

        Node(int val = 0){
            data = val;
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
        cout << root->data << " ";
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
stack<int> st;
void solve(vector<int> &ans,Node* head){
    if(head->next == NULL){
        st.push(head->data);
        ans.push_back(0);
        return;
    }
    solve(ans,head->next);
    while (!st.empty() and st.top() <= head->data){
        st.pop();
    }

    if(st.empty()){
        ans.push_back(0);
    }else{
        ans.push_back(st.top());
    }

    st.push(head->data);
    
}

vector<int> nextLargerNodes(Node* head) {
    vector<int> ans;
    solve(ans,head);
    reverse(ans.begin(),ans.end());
    return ans;
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

    for(auto &x : nextLargerNodes(root)){
        cout << x << " ";
    }


    
    
    return 0;
}