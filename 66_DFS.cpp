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
const int N = 1e5+10, MOD = 1e9+7;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){

    vis[vertex] = true;
    cout << vertex << endl;

    for(auto &child: g[vertex]){
        cout << "par" << " " << vertex << ", " << "child " << child << endl;
        if(vis[child]) continue;
        dfs(child);
    }

}
// O(V+E)

int main(){

    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);
    
    return 0;
}