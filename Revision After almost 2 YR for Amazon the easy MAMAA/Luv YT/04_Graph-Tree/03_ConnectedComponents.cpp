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
        node* next;
        node* prev;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            prev = NULL;
            left = NULL;
            right = NULL;
        }
};

node* makeTree(vector<int>& v){
    node* root = new node(v[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (i < v.size()){
        node* curr = q.front();
        q.pop();
        if(i < v.size() && v[i] != -1){
            curr->left = new node(v[i]);
            q.push(curr->left);
        }
        i++;
        if(i < v.size() && v[i] != -1){
            curr->right = new node(v[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];

// store the connect components.
vector<vector<int>> store;

void dfs(int index, vector<int>& temp){
    vis[index] = true;
    temp.push_back(index);
    for(auto& x : adj[index]){
        if(vis[x]) continue;
        dfs(x, temp);
    }
}

bool checkCycle(int index, int par){
    vis[index] = true;
    bool ans = false;
    for(auto& x : adj[index]){
        if(vis[x] && x == par) continue;
        if(vis[x]) return true;
        ans = ans || checkCycle(x, index);
    }
    return ans;
}

int32_t main(){

    int n , m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    bool ans = false;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        if(checkCycle(i, -1)){
            ans = true;
            break;
        }
    }

    cout << ans << endl;

    // int ans = 0;
    // for(int i = 1; i<=n ; i++){
    //     if(vis[i]) continue;
    //     vector<int> temp;
    //     dfs(i, temp);
    //     store.push_back(temp);
    //     ans++;
    // }

    // cout << ans << endl;
    // for(auto& x : store){
    //     for(auto& y : x){
    //         cout << y << " ";
    //     }cout << endl;
    // }
}