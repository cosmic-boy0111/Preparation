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

// aproch
// 1. find deepest node from root node
// 2. assume that deepest node as a root node 
// and find the depth of deepest node 

vector<int> g[N];
int depth[N];

void dfs(int v,int par=-1){


    for(auto &child:g[v] ){
        if(child == par) continue;
        depth[child] = depth[v] + 1;
        dfs(child,v);
    }

}


int main(){
    
    int n;
    cin >> n;

    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);
    int mx_depth = -1;
    int mx_d_node;

    for(int i=1;i<=n;i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;
    }

    dfs(mx_d_node);

    
    for(int i=1;i<=n;i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
        }
    }

    cout << mx_depth << endl;





    return 0;
}