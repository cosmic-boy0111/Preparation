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

int dp[801][801][3];

int solve(int h,int m,int count,int pre,vector<pair<int,int>>& condition){
    if(h <= 0 || m <= 0) return 0;
    if(dp[h][m][pre] != -1) return dp[h][m][pre];
    int mx = INT_MIN;
    for(int i=0;i<3;i++){
        if(i == pre) continue;
        int t = 1 + solve(h + condition[i].first, m + condition[i].second,count+1,i,condition);
        mx = max(mx, t);
    }
    return dp[h][m][pre] = mx;
}

int maxLevel(int h,int m){

    memset(dp,-1,sizeof(dp));
    vector<pair<int,int>> v = {{-20,5},{-5,-10},{3,2}};
    return solve(h,m,0,-1,v) - 1;

}

int32_t main(){
    
    int h, m;
    cin >> h >> m;

    cout << maxLevel(h,m);



    return 0;
}