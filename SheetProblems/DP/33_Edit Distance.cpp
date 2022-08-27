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

static const int T = 1e3+10;
int dp[T][T];

int solve(string x,string y, int m, int n){

    if(m == -1) return n+1;
    if(n == -1) return m+1;

    if(dp[m][n] != -1) return dp[m][n];

    if(x[m] == y[n]) return dp[m][n] = solve(x,y,m-1,n-1);


    int a = solve(x,y,m-1,n-1);
    int b = solve(x,y,m,n-1);
    int c = solve(x,y,m-1,n);

    return  dp[m][n] = 1 + min({a,b,c});

}

int editDistance(string x, string y) {
    memset(dp,-1,sizeof(dp));
    return solve(x,y,x.size()-1,y.size()-1);
}   

int32_t main(){
    
    string x , y;
    cin >> x >> y;

    cout << editDistance(x,y);
    
    return 0;
}