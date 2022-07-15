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
int rows;
int cols;
bool isFound(vector<vector<char> > &board, const char* curChar, int curRow, int curCol)
{
    if(curRow<0 || curCol<0 || curRow>=rows || curCol>=cols || board[curRow][curCol]=='\0' || *curChar!=board[curRow][curCol])
        return false;
    if(*(curChar+1)=='\0')
        return true;
    char t=board[curRow][curCol];
    board[curRow][curCol]='\0';
    
    if(isFound(board, curChar+1, curRow-1, curCol) || isFound(board, curChar+1, curRow+1, curCol) || isFound(board, curChar+1, curRow, curCol-1) || isFound(board, curChar+1, curRow, curCol+1))
        return true; 
    
    board[curRow][curCol] = t;
    return false;
}
    bool exist(vector<vector<char>> &board, string word) {
        rows = board.size();
        cols = board[0].size();
    for(int curRow = 0; curRow < rows; ++curRow)
    {
        for(int curCol = 0; curCol < cols; ++curCol)
        {
            if(isFound(board, word.c_str(), curRow, curCol))
                return true;
        }
    }
    return false;
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

    string s;
    cin >> s;

    cout << exist(mat,s) ;
    
    
    return 0;
}