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

bool isSafe(int i,int j, vector<vector<char>> board, vector<vector<int>> visited){
    return (i>=0) and (i < board.size()) and (j>=0) and (j < board[0].size()) and board[i][j]=='-' and visited[i][j];
}

void dfs(int i,int j,vector<vector<char>>& board, vector<vector<int>>& visited){
    int row[] = {-1,0,1,0};
    int col[] = {0,1,0,-1};

    visited[i][j] = 0;
    board[i][j] = 'O';

    for(int k=0;k<4;k++){
        if(isSafe(i+row[k],j+col[k],board,visited)){
            dfs(i+row[k],j+col[k],board,visited);
        }
    }

}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 'O')
                board[i][j] = '-';
        }
    }

    vector<vector<int>> visited(n,vector<int>(m,1));
    int startRow = 0;
    int startCol = 0;
    for(int i=startCol;i<m;i++){
        if(board[0][i] == '-' and visited[0][i]){
            dfs(0,i,board,visited);
        }
    }
    for(int i = startRow; i < n ; i++){
        if(board[i][0] == '-' and visited[i][0]){
            dfs(i,0,board,visited);
        }
    }

    for(int i=startCol;i<m;i++){
        if(board[n-1][i] == '-' and visited[n-1][i]){
            dfs(n-1,i,board,visited);
        }
    }

    for(int i = startRow; i < n ; i++){
        if(board[i][m-1] == '-' and visited[i][m-1]){
            dfs(i,m-1,board,visited);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == '-')
                board[i][j] = 'X';
        }
    }

}

int32_t main(){
    
    int n,m;
    cin >> n >> m;
    vector<vector<char>> mat(n,vector<char>(m));
    for(auto &x : mat){
        for(auto &y : x){
            cin >> y;
        }
    }

    solve(mat);

    for(auto &x : mat){
        for(auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    
    return 0;
}