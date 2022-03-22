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

vector<int> g[N];
int par[N];

void dfs(int v,int p = -1){
    par[v] = p;
    for(auto &child:g[v]){
        if(child == p) continue;
        dfs(child,v);
    }
}

vector<int> path(int v){
    vector<int> ans;
    while (v != -1)
    {
        ans.push_back(v);
        v = par[v];
    }

    reverse(ans.begin(),ans.end());

    return ans;
    
}


int main(){
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    int x,y;
    cin >> x >> y;

    vector<int> path_x = path(x);
    vector<int> path_y = path(y);

    int mn_ln = min(path_x.size(),path_y.size());

    int lca = -1;
    for(int i=0;i<mn_ln;i++){
        if(path_x[i] == path_y[i])
            lca = path_x[i];
        else    
            break;
    }

    cout << lca << endl;
    
    return 0;
}