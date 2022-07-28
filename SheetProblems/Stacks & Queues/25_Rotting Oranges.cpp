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
        int data;
        node* left;
        node* right;

        node(int val = 0){
            data = val;
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

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2)
                q.push({i,j});
        }
    }
    vector<pair<int,int>> v = {{-1,0},{1,0},{0,-1},{0,1}};
    while (!q.empty()){
        auto t = q.front();
        q.pop();
        int i = t.first;
        int j = t.second;
        for(auto &x : v){
            if((i+x.first >=0) and (i+x.first < n) and (j+x.second>=0) and (j+x.second < m)
            and grid[i+x.first][j+x.second] == 1
            ){
                grid[i+x.first][j+x.second] = grid[i][j] + 1;
                q.push({i+x.first,j+x.second});
            }
        }
    }

    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1) return -1;
            mx = max(mx,grid[i][j]);
        }
    }

    return  mx==0? 0 : mx-2;

    

}

int32_t main(){
    

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> t;
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            t.push_back(x);
        }
        v.push_back(t);
    }


    cout << orangesRotting(v);


    
    
    
    return 0;
}