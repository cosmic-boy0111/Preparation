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

void preorder(node* root, int row, int level, map<pair<int, int>, multiset<int>>& mp){
    if(!root) return;
    mp[{level, row}].insert(root->val);
    preorder(root->left, row + 1, level - 1, mp);
    preorder(root->right, row + 1, level + 1, mp);
}

vector<vector<int>> verticalTraversal(node* root){
    map<pair<int, int>, multiset<int>> mp; // O(n+2)
    preorder(root, 0, 0, mp); // O(n * lon n)
    vector<vector<int>> ans;
    int preKey = INT_MIN;
    vector<int> temp;
    for(auto& x : mp){
        if(x.first.first != preKey){
            if(!temp.empty()) ans.push_back(temp);
            preKey = x.first.first;
            temp.clear();
        }
        temp.insert(temp.end(), x.second.begin(), x.second.end()); // O(n * level)
    }
    if(!temp.empty()) ans.push_back(temp);
    return ans;
}

int32_t main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& x : v){
        cin >> x;
    }

    node* root = makeTree(v);
    vector<vector<int>> ans = verticalTraversal(root);
    for(auto& x : ans){
        for(auto& y : x){
            cout << y << " ";
        }cout << endl;
    }
}