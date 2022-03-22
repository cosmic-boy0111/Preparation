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

int INF = 1e9+10;

vector<pair<int,int>> adj[N];
vector<int> lvl(N,INF);
int n,m;

int bfs(){

    deque<int> q;
    q.push_back(1);
    lvl[1] = 0;

    while (!q.empty()){
        int cur_v = q.front();
        q.pop_front();

        for(auto child : adj[cur_v]){
            int child_v = child.first;
            int wt = child.second;
            if( lvl[cur_v] + wt < lvl[child_v] ){
                lvl[child_v] = lvl[cur_v] + wt;
                if(wt == 1){
                    q.push_back(child_v);
                }else{
                    q.push_front(child_v);
                }
            }
        }

    }


    return lvl[n] == INF ? -1 : lvl[n];
    

}


int32_t main(){
   
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        if(x==y) continue;
        adj[x].push_back({y,0});
        adj[y].push_back({x,1});
    }

    cout << bfs() << endl;
    
    return 0;
}