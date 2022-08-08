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
    vector<vector<int>> dist(n+10,vector<int>(n+10));
    for(int i=0;i<n+10;i++){
        for(int j=0;j<n+10;j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }

    for(auto &x : edges){
        dist[x[0]][x[1]] = x[2];
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] != INT_MAX and dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == INT_MAX){
                cout << "I" << " ";
            }else{
                cout << dist[i][j] << " ";
            }
        }cout << endl;
    }

    int ans = 0;
    int mn = INT_MAX;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(dist[i][j] <= distanceThreshold) cnt++;
        }
        cout << i << " : " << cnt << endl;
        if(cnt < mn){
            ans = i;
            mn = cnt;
        }
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