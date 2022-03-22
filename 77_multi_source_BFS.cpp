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

int val[N][N];
int vis[N][N];
int lev[N][N];

int n,m;

vector<pair<int,int>> moments = {
    {0,1},{0,-1},
    {1,0},{-1,0},
    {1,1},{1,-1},
    {-1,1},{-1,-1}
};

bool isValid(int i,int j){
    return i>=0 and j>=0  and i< n and j< m;
}

int bfs() {
    int mx = 0;
    inc(i , 0 , n){
        inc(j , 0 , m){
            mx = max(mx,val[i][j]);
        }
    }

    queue<pair<int,int>> q;

    inc(i , 0 , n){
        inc(j , 0 , m){
            if(mx == val[i][j]){
                q.push({i,j});
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }

    int ans = 0;

    while (! q.empty()){
        auto v = q.front();
        int v_x = v.first;
        int v_y = v.second;
        q.pop();

        for(auto moment : moments){
            int child_x = moment.first + v_x;
            int child_y = moment.second + v_y;
            if(!isValid(child_x,child_y)) continue;
            if(vis[child_x][child_y]) continue;
            q.push({child_x,child_y});
            lev[child_x][child_y] = lev[v_x][v_y] + 1;
            vis[child_x][child_y] = 1;
            ans = max(ans,lev[child_x][child_y]);
        }

    }

    return ans;
    



}

void reset(){
    inc(i , 0 , n){
        inc(j , 0 , m){
            vis[i][j] = 0;
            lev[i][j] = INF;
        }
    }
}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        reset();
        cin >> n >> m;
        inc(i , 0 , n){
            inc(j , 0 , m){
                cin >> val[i][j];
            }
        }

        cout << bfs() << endl;
    }


    
    
    
    return 0;
}