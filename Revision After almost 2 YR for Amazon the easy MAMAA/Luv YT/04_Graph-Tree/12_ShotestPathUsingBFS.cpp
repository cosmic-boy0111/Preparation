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

int getX(string s){
    return s[0] - 'a';
}

int getY(string s){
    return s[1] - '1';
}

bool vis[8][8];
bool lvl[8][8];

vector<pair<int, int>> movements = {
    {2, 1}, {2, -1},
    {-2, 1}, {-2, -1},
    {1, 2}, {-1, 2},
    {1, -2}, {-1, -2}
};

bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int shortestPath(string start, string end){
    int startX = getX(start);
    int startY = getY(start);
    int endX = getX(end);
    int endY = getY(end);

    queue<pair<int, int>> q;
    q.push({startX, startY});
    vis[startX][startY] = true;
    lvl[startX][startY] = 0;

    while(!q.empty()){
        pair<int, int> pos = q.front();
        q.pop();
        int x = pos.first, y = pos.second;
        if(x == endX && y == endY){
            return lvl[x][y];
        }
        for(auto& movement : movements){
            int childX = x + movement.first;
            int childY = y + movement.second;
            if(!isValid(childX, childY)) continue;
            if(vis[childX][childY]) continue;
            q.push({childX, childY});
            vis[childX][childY] = true;
            lvl[childX][childY] = lvl[x][y] + 1;
        }
    }

    return -1;
}

int32_t main(){

    int T;
    cin >> T;

    while(T--){
        string s1, s2;
        cin >> s1 >> s2;
        cout << shortestPath(s1, s2);
    }

}