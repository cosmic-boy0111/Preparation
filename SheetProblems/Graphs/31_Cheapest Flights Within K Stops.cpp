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



int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    int INF =  INT_MAX;

    vector<pair<int,int>> adj[n];
    for(auto &x : flights)
        adj[x[0]].push_back({x[1],x[2]});

    int dist[n+10][k+2];
    for(int i=0;i<n+10;i++){
        for(int j=0;j<k+2;j++){
            dist[i][j] = INF;
        }
    }

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
    q.push({0,src,0});
    dist[src][0] = 0;
    while ( !q.empty() ){
        vector<int> t = q.top();
        q.pop();
        int d = t[0];
        int n = t[1];
        int s = t[2];

        if(n == dst) return d;
        if(s > k) continue;
        for(auto &x : adj[n]){
            if(x.second + d < dist[x.first][s+1]){
                dist[x.first][s+1] = x.second + d;
                q.push({dist[x.first][s+1],x.first,s+1});
            }
        }
    }

    return -1;
    
}

int32_t main(){
    
    
    
    return 0;
}