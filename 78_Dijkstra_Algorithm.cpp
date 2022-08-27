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

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<pair<int,int>> g[N];
// int INF = N;

int dijkstra(int source, int n,vector<pair<int,int>> g[]){

    

    int N = 1e6;
    int INF = N;
    vector<int> vis(N,0);
    vector<int> dist(N,INF);

    minHeapPair st;
    st.push({0,source});
    dist[source] = 0;

    while ( ! st.empty()){
        auto node = st.top();
        st.pop();
        int v = node.second;
        int dst = node.first;
        if(vis[v]) continue;
        vis[v] = 1;

        for(auto child : g[v]){
            int child_v = child.first;
            int wt = child.second;

            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.push({dist[child_v],child_v});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] == INF) return -1;
        ans = max(ans,dist[i]);
    }

    return ans;

}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int>> g[N];
    for(auto vec : times){
        g[vec[0]].push_back({vec[1],vec[2]});
    }
    return dijkstra(k,n,g);
}

int32_t main(){
    

    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        int x,y,w;
        cin >> x >> y >> w;
        g[x].push_back({y,w});

    }
    
    
    return 0;
}