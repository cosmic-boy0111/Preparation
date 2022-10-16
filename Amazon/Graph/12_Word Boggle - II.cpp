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


bool solve(vector<vector<char>>& board,int index,int i,int j,string s,string temp,vector<vector<int>>& vis){

    // cout << temp << endl;

    int n = board.size();
    int m = board[0].size();
    if(temp.size() > s.size() ) return false;
    if(temp == s) return true;
    vis[i][j] = 1;

    bool ans = false;

    for(auto &pr : pos){
        int x = i+pr.first;
        int y = j+pr.second;
        if(x < 0 || y < 0 || x >= n || y >= m) continue;
        if(vis[x][y]) continue;
        if(board[x][y] != s[index]) continue;
        temp.push_back(s[index]);
        ans = ans or solve(board,index+1,x,y,s,temp,vis);
        if(ans) break;
        temp.pop_back();
    }

    vis[i][j] = 0;
    return ans;

}

vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary){
    unordered_map<char,stack<string>> mp;
    for(auto &x : dictionary){
        mp[x[0]].push(x);
    }

    int n = board.size();
    int m = board[0].size();


    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<string >ans;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( mp.find(board[i][j]) != mp.end()){
                int i = 0;
                int s = mp[board[i][j]].size();
                while(!mp[board[i][j]].empty() and i<s){
                    string x = mp[board[i][j]].top();
                    string temp = "";
                    temp.push_back(x[0]);
                    if(solve(board,1,i,j,x,temp,vis)) {
                        ans.push_back(x);
                        mp[board[i][j]].pop();
                    }
                    i++;
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int32_t main(){
    
    vector<string> dictionary = {"CAT","CAN","AND"};
    vector<vector<char>> board = {{'C','A','P'},{'A','N','D'},{'T','I','E'}};

    for(auto &x : wordBoggle(board,dictionary)){
        cout << x << " ";
    }




    return 0;
}