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
    {0,-1},{-1,0},{0,1},{1,0}
};

long long dp[1005][1005];

int solve(vector<vector<int>> &mat,int i,int j,int path){
    

    int n = mat.size();
    int m = mat[0].size();


    
    if(i < 0 || i >=n || j < 0 || j >= m || mat[i][j] == 0) return INT_MAX;

    if(j == m-1) {
        if(mat[i][j] == 1) return path + 1;
        return INT_MAX;
    };

    mat[i][j] = 0;
    int ans = INT_MAX;
    for(auto &pr : pos){
        int x = i + pr.first;
        int y = j + pr.second;

        ans = min(ans,solve(mat,x,y,path+1));

    }

    mat[i][j] = 1;
    return ans;

}


int findShortestPath(vector<vector<int>> &mat){
    vector<pair<int,int>> v;
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0) v.push_back({i,j});
        }
    }

    for(auto &x : v){
        int i = x.first;
        int j = x.second;
        for(auto &pr : pos){
            int p1 = i + pr.first;
            int p2 = j + pr.second;
            if(p1 < 0 or p2 < 0 or p1 >= n or p2 >= m) continue;
            mat[p1][p2] = 0;
        }
    }


    for(auto &x : mat){

        for(auto &y : x) cout << y << " ";
        cout << endl;

    }

    int ans = INT_MAX;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        if(mat[i][0] == 0) continue;
        ans = min(ans , solve(mat,i,0,0));
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }

    return ans == INT_MAX ? -1 : ans;

}

int32_t main(){
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(auto &x : mat){
        for(auto &y : x) cin >> y;
    }

    cout << findShortestPath(mat);


    return 0;
}