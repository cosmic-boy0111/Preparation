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


vector<int> size;
vector<int> parent;

void make(int n){
    for(int i=0;i<n;i++){
        parent.push_back(i);
        size.push_back(1);
    }
}

int find(int i){
    if(parent[i] == i) return i;
    return find(parent[i]);
}

void makeUnion(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b]) 
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int minCostConnectPoints(vector<vector<int>>& points) {


    vector<pair<int,pair<int,int>>> v;
    int n = points.size();
    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            v.push_back({
                abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]),
                {i,j}
            });
        }
    }

    make(n);
    int ans = 0;
    sort(v.begin(),v.end());
    for(auto &x : v){
        int wt = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if(find(u) == find(v)) continue;
        ans += wt;
        makeUnion(u,v);
    }

    return ans;

}

int32_t main(){
    
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(2));
    for(auto &x : v)
        cin >> x[0] >> x[1];
    
    cout << minCostConnectPoints(v);
    
    return 0;
}