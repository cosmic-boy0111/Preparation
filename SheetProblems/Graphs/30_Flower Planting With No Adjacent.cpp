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


bool isSafe(int i,int j,vector<int> adj[],vector<int>& col){
    for(auto x : adj[i])
        if(col[x] == j) return false;

    return true;
}

bool solve(int i,int n,vector<int> adj[],vector<int>& col){
    
    if(i > n) return true;
    for(int j=1;j<=4;j++){
        if(isSafe(i,j,adj,col)){
            col[i] = j;
            if(solve(i+1,n,adj,col)) return true;
            col[i] = -1;
        }
    }

    return false;
}

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {


    vector<int> col(n+1,-1);
    vector<int> adj[n+1];
    for(auto x : paths){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    solve(1,n,adj,col);
    col.erase(col.begin());

    return col;

}

int32_t main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m,vector<int>(2));
    for(auto &x : v)
        cin >> x[0] >> x[1];
    
    for(auto &x : gardenNoAdj(n,v))
        cout << x << " ";

    return 0;
}