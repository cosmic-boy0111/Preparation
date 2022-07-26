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
vector<bool> visited(N,false);

vector<vector<char>> ans;
void Sudoku(vector<vector<char>>& board,
int i, int j, vector<unordered_map<int,int>>& row,
vector<unordered_map<int,int>>& col,
map<pair<int,int>,unordered_map<int,int>>& mp
){
    if(i == 9) {
        ans = board;
        return;
    };
    if(j == 9){
        Sudoku(board,i+1,0,row,col,mp);
        return;
    }
    if(board[i][j] != '.'){
        Sudoku(board,i,j+1,row,col,mp);
        return;
    }
    for(int k=1;k<10;k++){
        if(! mp[{i/3,j/3}][k] and !row[i][k] and !col[j][k]){
            mp[{i/3,j/3}][k] = 1;
            row[i][k] = 1;
            col[j][k] = 1;
            board[i][j] = k+'0';
            Sudoku(board,i,j+1,row,col,mp);
            mp[{i/3,j/3}][k] = 0;
            row[i][k] = 0;
            col[j][k] = 0;
            board[i][j] = '.';
        }
    }
}

void solveSudoku(vector<vector<char>>& board) {
    vector<unordered_map<int,int>> row(9);
    vector<unordered_map<int,int>> col(9);
    map<pair<int,int>,unordered_map<int,int>> mp;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] != '.'){
                row[i][board[i][j]-'0'] = 1;
                col[j][board[i][j]-'0'] = 1;
                mp[{i/3,j/3}][board[i][j]-'0'] = 1;
            }
        }
    }

    Sudoku(board,0,0,row,col,mp);
    board = ans;
}

int32_t main(){
    vector<vector<char>> soduko = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    solveSudoku(soduko);

    for(auto &x : soduko){
        for(auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    
    
    
    return 0;
}