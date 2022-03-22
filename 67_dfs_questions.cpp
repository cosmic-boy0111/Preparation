
// // que 1

// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vs vector<string>
// #define vb vector<bool>
// #define pi pair<int,int>
// #define mi map<int,int>
// #define umi unordered_map<int,int>
// #define qi queue<int>
// #define vpi vector<pi>
// #define vvi vector<vi>
// #define ff first
// #define ss second 
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;

// vector<int> g[N];
// bool vis[N];

// vector<vector<int>> cc;
// vector<int> current_cc;

// void dfs(int vertex){

//     vis[vertex] = true;

//     // cout << vertex << " ";
//     current_cc.push_back(vertex);

//     for(auto child: g[vertex]){
//         // cout << "par" << " " << vertex << ", " << "child " << child << endl;
//         if(vis[child]) continue;
//         dfs(child);
//     }

// }
// int main(){
    
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<m;i++){
//         int v1,v2;
//         cin >> v1 >> v2;
//         g[v1].push_back(v2);
//         g[v2].push_back(v1);
//     }

//     int cnt = 0;

//     for(int i=1;i<=n;i++){
//         if(vis[i])
//             continue;
//         current_cc.clear();
//         dfs(i);
//         cc.push_back(current_cc);
//         cnt++;
//     }

//     for(auto x:cc){
//         for(auto y:x){
//             cout << y << " ";
//         }cout << endl;
//     }

    

//     cout << "count of connected compo : " << cnt << endl;
    
    
//     return 0;
// }

// que 2

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
bool vis[N];

bool dfs(int vertex,int par){

    vis[vertex] = true;

    // cout << vertex << " ";

    bool isLoopExits = false;

    for(auto child: g[vertex]){
        // cout << "par" << " " << vertex << ", " << "child " << child << endl;
        if(vis[child] and child == par) continue;
        if(vis[child]) return true;
        isLoopExits |= dfs(child,vertex);
    }

    return isLoopExits;

}
int main(){
    
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bool isLoopExits = false;

    for(int i=1;i<=n;i++){
        if(vis[i])
            continue;
        if(dfs(i,0)){
            isLoopExits = true;
            break;
        }
    }

    cout << isLoopExits << endl;

    
    
    return 0;
}