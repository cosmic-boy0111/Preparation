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
const int N = 1e6;

vector<int> adj[N];
vector<bool> visited(N,false);
vector<int> nodeValue(N,0);
vector<int> parent(N,-1);

bool isSafe(int x){
    return !visited[x];
}

bool ans = false;

void dfs(int start,int n){
    nodeValue[start] = 1 + nodeValue[parent[start]];
    cout << start << " " << nodeValue[start] << endl;
    visited[start] = true;
    if(nodeValue[start] == n) {
        ans = true;
        return;
    };
    for(auto &x : adj[start]){
        if(isSafe(x) and !ans){
            parent[x] = start;
            dfs(x,n);
            parent[x] = -1;
            visited[x] = false;
            nodeValue[x] = 0;
        }
    }
}

bool check(int N,int M,vector<vector<int>> Edges){
    for(auto &x : Edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    visited[1] = true;
    parent[1] = 0;
    dfs(1,N);
    for(int i=1;i<=N;i++){
        cout <<i << " " << nodeValue[i] << endl;
    }
    return ans;

}

int32_t main(){
    
    int n , m;
    cin >> n >> m;
    vector<vector<int>> mat(m,vector<int>(2));
    for(auto &x : mat){
        cin >> x[0] >> x[1];
    }
    cout << check(n,m,mat);

    
    
    return 0;
}