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


vector<int> adj[N];
bool vis[N];

int minTime = 0;

// case 1
void handleCase1(node* root, int time){
    if(!root) return;
    if(!root->left && !root->right){
        minTime = max(minTime, time);
        return;
    }
    handleCase1(root->left, time + 1);
    handleCase1(root->right, time + 1);
}

int minimumTime(node* root, int time, int val){
    if(root == nullptr) return -1;
    // handle case 1
    cout << root->val << endl;
    if(root->val == val){
        handleCase1(root, time);
        cout << "first " << minTime << endl; 
        return 1;
    }

    // handle case 2
    int left = minimumTime(root->left, time, val);
    if(left != -1){
        minTime = max(minTime, left);
        handleCase1(root->right, left + 1);
        return left + 1;
    }
    int right = minimumTime(root->right, time, val);
    if(right != -1){
        minTime = max(minTime, right);
        handleCase1(root->left, right + 1);
        return right + 1;
    }

    return -1;
}

int32_t main(){

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    node* root = makeTree(v);
    minimumTime(root, 0, k);
    cout << minTime << endl;

}

/*
    1
     \
      2
       \
        3
         \
          4
           \
            5
*/