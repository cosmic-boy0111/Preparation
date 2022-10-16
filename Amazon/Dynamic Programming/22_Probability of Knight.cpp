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
    {2,1},{1,2},{-1,2},{-2,1},
    {-2,-1},{-1,-2},{1,-2},{2,-1}
};

double dp[101][101][101];
int vis[101][101];

double solve(int i,int j,int n,int k){

    if(i < 0 || j < 0 || j >= n || i >= n) return 0;
    if(vis[i][j]) return 0;
    vis[i][j] = 1;
    if(k == 0)return 1;
    if(dp[i][j][k]) return dp[i][j][k];
    double sum = 0;
    for(auto &x : pos){
        sum += solve(i+x.first,j+x.second,n,k-1);
    }

    return dp[i][j][k] = sum/8;

}

double findProb(int N,int start_x, int start_y, int steps){
    return solve(start_x,start_y,N,steps);
}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }



    return 0;
}