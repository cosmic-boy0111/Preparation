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

void printBinary(int n){
    for(int i=10;i>=0;i--){
        if((n>>i) & 1) cout << 1;
        else cout << 0;
    }cout << endl;
}

class node{
    public:
        int val;
        node* next;
        node* prev;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            prev = NULL;
            left = NULL;
            right = NULL;
        }
};

node* makeTree(vector<int>& v){
    node* root = new node(v[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (i < v.size()){
        node* curr = q.front();
        q.pop();
        if(i < v.size() && v[i] != -1){
            curr->left = new node(v[i]);
            q.push(curr->left);
        }
        i++;
        if(i < v.size() && v[i] != -1){
            curr->right = new node(v[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

const int N = 500;
const int INF = 1e6 + 10;

long long dist[N][N];

int32_t main(){

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> dist[i][j];
        }
    }

    vector<int> delOrder(n);
    for(auto& x : delOrder){
        cin >> x;
    }

    reverse(delOrder.begin(), delOrder.end());

    vector<long long> ans;

    for(int k = 0; k < n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                long long new_dist = dist[i][delOrder[k]] + dist[delOrder[k]][j];
                dist[i][j] = min(dist[i][j], new_dist);
            }
        }

        long long sum = 0;

        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= k; j++){
                sum += dist[delOrder[i]][delOrder[j]];
            }
        }

        ans.push_back(sum);
        
    }

    reverse(ans.begin(), ans.end());

    for(auto& x : ans){
        cout << x << " ";
    }
}