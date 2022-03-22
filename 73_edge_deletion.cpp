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
int subtree_sum[N];
int val[N];

void dfs(int vertex,int par){

    subtree_sum[vertex] += val[vertex];

    for(auto &child:g[vertex]){
        if(child == par) continue;
        dfs(child,vertex);

        subtree_sum[vertex] += subtree_sum[child];
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

    dfs(1,-1);
    long long ans = 0;
    for(int i=2;i<=n;i++){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        ans = max(ans,(part1*1LL*part2)) & MOD;
    }
    cout << ans << endl;
    
    return 0;
}