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

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

    vector<vector<int>> a(n,vector<int>(n,1e7));
    for(auto &x : edges){
        a[x[0]][x[1]] = x[2];
        a[x[1]][x[0]] = x[2];
    }

    vector<vector<int>> d = a;
    for(int i=0;i<n;i++){
        d[i][i] = 0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }

    int mx = n;
    unordered_map<int,unordered_set<int>> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j] <= distanceThreshold)
                mp[i].insert(j);
        }
    }

    for(auto it:mp){
        if(it.second.size()<mx)
            mx = it.second.size();
    }

    int ans = 0;
    for(auto &x : mp){
        if(x.second.size() == mx)
            ans = max(ans,x.first);
    }

    return ans;



}

int32_t main(){

    int n , t;
    cin >> n >> t;
    vector<vector<int>> v(n,vector<int>(3));
    for(auto &x : v)
        cin >> x[0] >> x[1] >> x[2];
    
    cout << findTheCity(n,v,t);
    
    
    return 0;
}