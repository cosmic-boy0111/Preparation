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


vector<int> g[N];
int depth[N], height[N];

void dfs(int vertex,int par = 0){

    for(auto child:g[vertex]){
        if(child == par) continue;

        depth[child] = depth[vertex] + 1;

        dfs(child,vertex);

        height[vertex] = max(height[vertex], height[child] + 1);
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

    for (int i = 1; i <= n; i++){
        cout << depth[i] << " " << height[i] << endl;
    }
    
    
    return 0;
}