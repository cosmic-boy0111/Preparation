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
const int N = 1e3, MOD = 1e9+7;

// adj matrix --> Graph
int graph1[N][N];
int graph3[N][N];
// adj list --> Graph
vector<int> graph2[N];
vector<pair<int,int>> graph4[N];


int main(){
    

    int n,m;
    cin >> n >> m;

    // unweighted graph
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;

        graph1[x][y] = 1;
        graph1[y][x] = 1;
        // O(N^2) -- space complexity

        graph2[x].push_back(y);
        graph2[y].push_back(x);
        // O(N+M) -- space complexity
    }

    // weighted graph
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin >> x >> y;

        graph3[x][y] = wt;
        graph3[y][x] = wt;
        // O(N^2) -- space complexity

        graph4[x].push_back({y,wt});
        graph4[y].push_back({x,wt});
        // O(N+M) -- space complexity
    }

    
    
    return 0;
}