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

int travel(vector<vector<int>>& matrix,int i,int j,int pre,vector<vector<int>>& dp){
    if(i < 0 or i>=matrix.size() or j < 0 or j>=matrix[0].size()) return 0;
    if(pre >= matrix[i][j]) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int u = travel(matrix,i-1,j,matrix[i][j],dp);
    int r = travel(matrix,i,j+1,matrix[i][j],dp);
    int d = travel(matrix,i+1,j,matrix[i][j],dp);
    int l = travel(matrix,i,j-1,matrix[i][j],dp);

    return dp[i][j] = 1+max(u,max(r,max(d,l)));
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int longest_path = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int path = travel(matrix,i,j,-1,dp);
            longest_path = max(longest_path,path);
        }
    }

    return longest_path;
}

int32_t main(){
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat;
    for(int i=0;i<n;i++){
        vector<int> v(m);
        for(auto &x : v){
            cin >> x;
        }
        mat.push_back(v);
    }


    cout << longestIncreasingPath(mat);
    
    
    
    return 0;
}