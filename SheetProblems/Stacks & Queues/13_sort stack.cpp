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

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(ListNode* &root,int val){
    if(root == NULL){
        root = new ListNode(val);
        return;
    }
    ListNode* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new ListNode(val); 
}

void display(ListNode* root){
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

stack<int> insert(stack<int> st,int t){
    if(st.size() == 0 ){
        st.push(t);
        return st;
    }
    if(st.top() >= t){
        st.push(t);
        return st;
    }

    int t1 = st.top();
    st.pop();
    
    stack<int> s = insert(st,t);
    s.push(t1);

    return s;
}

stack<int> sortStack(stack<int> st){
    if(st.size() == 1) return st;
    int t = st.top();
    st.pop();
    stack<int> s = sortStack(st);
    stack<int> sp = insert(s,t);
    return sp;
}


int32_t main(){
    
    int n;
    cin >> n;
    stack<int> st;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        st.push(x);
    }


    stack<int> ans  = sortStack(st);
    

    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    
    
    return 0;
}