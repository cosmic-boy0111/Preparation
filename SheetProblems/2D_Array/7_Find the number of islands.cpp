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

bool isSafe(int i,int j,vector<vector<char>> & grid,
vector<vector<int>>& visited){
    return (i>=0) and (i<grid.size()) and (j>=0) and (j < grid[0].size()) and (grid[i][j] == '1') and visited[i][j];
}

void markVisited(int i,int j,vector<vector<char>> & grid,
vector<vector<int>>& visited){
    static int row[8] = {-1,-1,-1,0,1,1,1,0};
    static int col[8] = {-1,0,1,1,1,0,-1,-1};

    visited[i][j] = 0;

    for(int k=0;k<8;k++){
        if(isSafe(i+row[k],j+col[k],grid,visited))
            markVisited(i+row[k],j+col[k],grid,visited);
    }

}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n,vector<int>(m,1));

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(grid[i][j] == '1' and visited[i][j]){
                markVisited(i,j,grid,visited);
                ans++;

            }

        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << visited[i][j] << " ";
    //     }cout << endl;
    // }


    

    return ans;

}

int32_t main(){
    
    int n,m;
    cin >> n >> m;
    vector<vector<char>> mat(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }

    cout << numIslands(mat);
    
    return 0;
}