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

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(ListNode* &root,int val){
    if(root == NULL){
        root = new ListNode(val);
        return;
    }
    ListNode* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new ListNode(val); 
}

void display(ListNode* root){
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

vector<pair<int,int>> pos = {
    {0,-1},{-1,0},{0,1},{1,0},
    {-1,-1},{-1,1},{1,1},{1,-1}
};

bool dfs(int i,int j,int k,string s,vector<vector<char>>& board,vector<vector<int>> & vis){
    if(k == s.size()) return true;
    int n = board.size();
    int m = board[0].size();
    if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j]) return false;
    vis[i][j] = 1;
    if(board[i][j] == s[k]){
        for(auto &pr : pos){
            int x = i+pr.first;
            int y = j+pr.second;
            if(dfs(x,y,k+1,s,board,vis)) return true;
        }
    }

    vis[i][j] = 0;
    return false;

}

vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
    set<string> temp;
    vector<string> ans;

    int n = board.size();
    int m = board[0].size();

    for(auto &s : dictionary){
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == s[0]){
                    if(dfs(i,j,0,s,board,vis)){
                        temp.insert(s);
                    }
                }
            }
        }
    }

    for(auto &x : temp) ans.push_back(x);
    return ans;

}

int32_t main(){
    

    
    return 0;
}