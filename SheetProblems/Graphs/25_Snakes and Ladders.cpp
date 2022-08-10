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


int snakesAndLadders(vector<vector<int>>& board) {
    unordered_map<int, int> mp;
    int n = board.size();
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] != -1) {
                int val;
                if((n-i)%2 != 0) val = (n-i-1)*n + j + 1;
                else val = (n-i-1)*n + n - j;
                mp[val] = board[i][j];
            }
        }
    }

    queue<pair<int, int>> q;
    vector<int> visited(n*n+1, false);
    q.push({1, 0});
    while(!q.empty()) {
        int node = q.front().first;
        int moves = q.front().second;
        q.pop();
        if(node == n*n) return moves;
        if(visited[node]) continue;
        visited[node] = true;
        for(int k = 1; k <= 6; k++) {
            if(node+k > n*n) continue;
            int x = node + k;
            if(mp.find(x) != mp.end()) x = mp[x];
            q.push({x, moves+1});
        }
    }
    return -1;

}

int32_t main(){
    
    vector<vector<int>> board = {   {-1,-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1,-1},
                                    {-1,30,-1,-1,13,-1},
                                    {-1,-1,-1,-1,-1,-1},
                                    {-1,15,-1,-1,-1,-1}};

    // vector<vector<int>> board = {{-1,-1},{-1,3}};

    cout << snakesAndLadders(board);
    
    
    
    return 0;
}