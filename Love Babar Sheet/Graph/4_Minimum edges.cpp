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

vector<pair<int,int>> pos = {
    {0,-1},{-1,0},{0,1},{1,0},
    {-1,-1},{-1,1},{1,1},{1,-1}
};

int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst){

    vector<pair<int,int>> adj[n+1];
    for(auto x : edges){
        int u = x[0];
        int v = x[1];
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e9);
    vector<int> visited(n+1,0);
    pq.push({0,src});
    dist[src] = 0;
    while ( !pq.empty() ){
        auto pr = pq.top();
        pq.pop();
        int u = pr.second;
        visited[u] = 1;
        for(auto &x : adj[u]){
            int v = x.first;
            int wt = x.second;
            if(visited[v]) continue;
            if(dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push({dist[v],v});
            }
        }
    }

    if(dist[dst] == 1e9) return -1;
    return dist[dst];

}

int32_t main(){
    
    // int n , m;
    // cin >> n >> m;
    // vector<vector<int>> v(m,vector<int>(2));
    // for(auto &x : v)
    //     cin >> x[0] >> x[1];
    // int src , dst;
    // cin >> src >> dst;

    // cout << minimumEdgeReversal(v,n,src,dst);

    string s = "abc";
    s[0] = 'p';
    cout << s << endl;


    return 0;
}