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
void printBinary(int n){for(int i=10;i>=0;i--){if((n>>i) & 1){cout << 1;}else{cout << 0;}}cout << endl;}

// given Q querise Q <= 10^5
// in each query given V;
// print subtree sum of V and number in even numbers
// in subtree of V



vector<int> g[N];
int even[N];
int sum[N];

void dfs(int vertex,int par=0){

    if(vertex%2 == 0){
        even[vertex] += 1;
    }

    sum[vertex] += vertex;

    for(auto &child:g[vertex]){

        if(par == child) continue;
        dfs(child,vertex);
        even[vertex] += even[child];
        sum[vertex] += sum[child];

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

    int q;
    cin >> q;
    while (q--){
        int v;
        cin >> v;
        cout << even[v] << " " << sum[v] << endl;
    }
    


    
    return 0;
}