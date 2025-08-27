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
        node* next;
        node* prev;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            prev = NULL;
            left = NULL;
            right = NULL;
        }
};

node* makeTree(vector<int>& v){
    node* root = new node(v[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (i < v.size()){
        node* curr = q.front();
        q.pop();
        if(i < v.size() && v[i] != -1){
            curr->left = new node(v[i]);
            q.push(curr->left);
        }
        i++;
        if(i < v.size() && v[i] != -1){
            curr->right = new node(v[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];

const int size = 1e3 + 10;

int val[size][size];
int lvl[size][size];
int vis[size][size];

int n , m;

void reset(){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            val[i][j] = 0;
            lvl[i][j] = 1e3;
            vis[i][j] = 0;
        }
    }
}

vector<pair<int, int>> positions = {
    {-1, 0}, {1, 0},
    {0, -1}, {0, 1}
};

bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs(){
    queue<pair<int, int>> q;
    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mx = max(mx, val[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(val[i][j] == mx){
                q.push({i, j});
                lvl[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }

    int ans = -1;

    while (!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        ans = max(ans, lvl[curr.first][curr.second]);
        for(auto& pos : positions){
            int i = curr.first + pos.first;
            int j = curr.second + pos.second;
            if(!isValid(i , j)) continue;
            if(vis[i][j]) continue;
            q.push({i ,j});
            vis[i][j] = 1;
            lvl[i][j] = lvl[curr.first][curr.second] + 1;
        }
    }
    
    return ans;

}

int32_t main(){

    int T;
    cin >> T;

    while (T--){
        cin >> n >> m;
        reset();
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                cin >> val[i][j];
            }
        }
        cout <<  bfs() << endl;
    }

}