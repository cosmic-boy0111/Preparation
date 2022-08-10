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

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data = 0){
            val = data;
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



void dfs(int index,vector<int> adj[],stack<int>& st,vector<int>& vis)  {
    vis[index] = true;
    for(auto &x : adj[index]){
        if(vis[x]) continue;
        dfs(x,adj,st,vis);
    }
    st.push(index);
}

void find(int index,vector<int> adj[],vector<int>& vis,vector<int>& temp){

    vis[index] = true;
    temp.push_back(index);
    for(auto &x : adj[index]){
        if(vis[x]) continue;
        find(x,adj,vis,temp);
    }

}

int kosaraju(int V, vector<int> adj[]){

    stack<int> st;
    vector<int> vis(V,0);

    for(int i=0;i<V;i++){
        if(!vis[i])
            dfs(i,adj,st,vis);
    }

    vector<int> transpose[V];
    for(int i=0;i<V;i++){
        vis[i] = 0;
        for(auto &x : adj[i]){
            transpose[x].push_back(i);
        }
    }

    vector<vector<int>> ans;

    while (!st.empty()){
        int t = st.top();
        st.pop();
        if(vis[t]) continue;
        vector<int> temp;
        find(t,transpose,vis,temp);
        ans.push_back(temp);
    }
    

    return ans.size();

}


int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }
    
    
    
    return 0;
}