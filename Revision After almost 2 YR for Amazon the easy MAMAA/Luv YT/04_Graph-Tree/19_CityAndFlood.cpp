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

int parent[N];
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    int p_a = find(a);
    int p_b = find(b);
    if(p_a != p_b){
        if(size[p_b] > size[p_a]){
            swap(p_a, p_b);
        }
        size[p_a] += size[p_b]; 
        parent[p_b] = p_a;
    }
}

int32_t main(){

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        make(i);
    }

    int k;
    cin >> k;

    while(k--){
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(parent[i] == i) ans++;
    }

    cout << ans << endl;

}