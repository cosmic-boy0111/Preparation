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


bool solve(int i,int sum,vector<pair<int,int>> adj[],vector<int>& vis,int target){

    if(sum >= target) return true;
    vis[i] = true;
    for(auto &x : adj[i]){
        if(vis[x.first]) continue;
        sum += x.second;
        if(solve(x.first,sum,adj,vis,target)) return true;
        sum -= x.second;
    }

    vis[i] = false;

    return false;

}

bool findPathMoreThanK(int n,vector<vector<int>>& edges,int target) {


    vector<pair<int,int>> adj[n];
    vector<int> vis(n,0);
    for(auto x : edges){
        adj[x[0]].push_back({x[1],x[2]});
        adj[x[1]].push_back({x[0],x[2]});
    }

    return solve(0,0,adj,vis,target);


}

bool pathMoreThanK(int V, int E, int k, int a[]) {
    vector<vector<int>> edges;
    int i =0;
    while ( i < E*3-2 ){
        vector<int> temp;
        for(int j=0;j<3;j++){
            temp.push_back(a[i++]);
        }
        edges.push_back(temp);
    }
    
    return findPathMoreThanK(V,edges,k);
    
}

int32_t main(){
    

    int a[] = {1,2,1,0,2,7};
    int V = 3;
    int E = 2;
    int K = 8;

    cout << pathMoreThanK(V,E,K,a);
    
    
    return 0;
}