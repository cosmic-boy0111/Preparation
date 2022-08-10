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


vector<int> calMaxDist(int src,int n,vector<pair<int,int>> adj[]){
    vector<int> dist(n, INT_MIN);
    dist[src] = 0;
    set<pair<int, int> > s;
    s.insert(make_pair(dist[src], src));
    
    while(!s.empty()){
        auto top = *(s.begin());
        int d = top.first;
        int node = top.second;
        s.erase(s.begin());
        
        for(auto nbr: adj[node]){
            int v = nbr.first;
            int w = nbr.second;

            //only this cond. differs from dijkstra algo, get the max dist
            if(w+d > dist[v]){
                auto f = s.find(make_pair(dist[v], v));
                if(f != s.end()){
                    s.erase(f);
                }
                dist[v] = w + d;
                s.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src){
    vector<pair<int,int>> adj[v];
    for(auto &x : edges){
        adj[x[0]].push_back({x[1],x[2]});
    }


    return calMaxDist(src,v,adj);


}

int32_t main(){
    int v,e,src;
    cin >> v >> e >> src;
    vector<vector<int>> edges(v,vector<int>(3));
    for(auto &x : edges){
        cin >> x[0] >> x[1] >> x[2];
    }

    for(auto &x : maximumDistance(edges,v,e,src)){
        cout << x << " ";
    }
    
    
    return 0;
}