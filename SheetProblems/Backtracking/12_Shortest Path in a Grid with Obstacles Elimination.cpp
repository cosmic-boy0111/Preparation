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

class Node{
    public:
        int val;
        Node* next;

        Node(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(Node* &root,int val){
    if(root == NULL){
        root = new Node(val);
        return;
    }
    Node* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new Node(val); 
}

void display(Node* root){
    while (root != NULL){
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;

}


#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];

vector<pair<int,int>> way = {
    {-1,0}, {0,1}, {1,0}, {0,-1}
};

int shortestPath(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > visited(n,vector<int>(m,-1));
    queue<vector<int>> q;
    q.push({0,0,0,k});
    while (!q.empty()){
        vector<int> temp = q.front();
        q.pop();
        int x  = temp[0], y = temp[1], len = temp[2], obs = temp[3];
        if(x < 0 || y < 0 || x >= n || y >=m)
            continue;
        if(x == n-1 and y == m-1)
            return len;
        if(grid[x][y] == 1){
            if(obs > 0)
                obs--;
            else
                continue;
        }

        if(visited[x][y] < obs){
            visited[x][y] = obs;
            q.push({x + 1, y, len + 1, obs});
            q.push({x - 1, y, len + 1, obs});
            q.push({x, y + 1, len + 1, obs});
            q.push({x, y - 1, len + 1, obs});    
        }

    }

    return -1;
    
}

int32_t main(){
    
    int n ,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m));
    for(auto &x : v)
        for(auto &y : x)
            cin >> y;

    int k;
    cin >> k;

    cout << shortestPath(v,k);
    
    
    return 0;
}