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
vector<int> visited(15,0);

int solve(vector<vector<int>> & graph, int visited_node_size,int path, int start, int size){
    if(visited_node_size == size) {
        return path;
    }

    visited[start] +=1;
    int ans = INT_MAX;
    for(auto &x : graph[start]){
        if(visited[x] < size){
            path += 1;
            if(visited[x] == 0){
                visited_node_size += 1;
            }
            ans = min(ans,solve(graph,visited_node_size,path,x,size));
            path -= 1;
        }
    }

    cout << ans << endl;

    return ans;

}

int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    int visited_node_size = 0;
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        vector<int> vis(15,0);
        visited = vis;
        ans = min(ans,solve(graph,visited_node_size,0,i,n));
        // cout << ans << endl;
    }
    return ans;
}

int32_t main(){

    int n;
    cin >> n;
    vector<vector<int> >  v(n);
    for(int i=0;i<n;i++){
        int m ;
        cin >> m;
        vector<int> t(m);
        for(auto &x : t)
            cin >> x;
        v[i] = t;
    }

    cout << shortestPathLength(v);
    
    return 0;
}