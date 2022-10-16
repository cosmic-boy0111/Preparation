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

vector<int> minimumTime(int n,vector<vector<int>> &edges,int m){
    vector<vector<int>> adj(n,vector<int>());
    for(auto &x : edges){
        adj[x[0]-1].push_back(x[1]-1);
    }
    vector<int> indegree(n,0);
    vector<int> ans(n,-1);

    for(int i=0;i<n;i++){
        for(auto &x : adj[i]) indegree[x]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            ans[i] = 1;
            q.push(i);
        }
    }

    while ( !q.empty() ){
        int curr = q.front();
        q.pop();
        for(auto &x : adj[curr]){
            ans[x] = max(ans[x],1 + ans[curr]);
            indegree[x] --;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }


    return ans;
    

}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }



    return 0;
}