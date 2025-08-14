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

// int widthOfBinaryTree(node* root) {
//     if(!root) return 0;
//     queue<pair<node*, pair<int, long long>>> q;
//     q.push({root, {1, 1}});
//     map<int, pair<long long, long long>> mp;
//     long long ans = INT_MIN;
//     while(!q.empty()){
//         pair<node*, pair<int, long long>> top = q.front();
//         q.pop();
//         cout << top.first->val << " " << top.second.first << " " << top.second.second << endl;
//         if(mp.find(top.second.first) == mp.end()){
//             mp[top.second.first] = {top.second.second, top.second.second};
//             ans = max(ans, top.second.second - top.second.second + 1);
//         }else{
//             mp[top.second.first].second = top.second.second;
//             ans = max(ans, mp[top.second.first].second - mp[top.second.first].first + 1);
//         }
//         if(top.first->left) q.push({top.first->left, {top.second.first + 1, 2 * (top.second.second - mp[top.second.first].first) + 1}});
//         if(top.first->right) q.push({top.first->right, {top.second.first + 1, 2 * (top.second.second- mp[top.second.first].first) + 2}});
//     }
//     return ans;
// }

int widthOfBinaryTree(node* root) {
    if(!root) return 0;
    queue<pair<node*, int>> q;
    q.push({root, 1});
    int ans = INT_MIN;
    while(!q.empty()){
        int min  = q.front().second;
        int size = q.size();
        int left, right;
        for(int i = 0; i < size; i++){
            int lvlIdx = q.front().second - min;
            if(i == 0) left = q.front().second;
            if(i == size - 1) right = q.front().second;
            if(q.front().first->left) q.push({q.front().first->left, 2 * lvlIdx + 1});
            if(q.front().first->right) q.push({q.front().first->right, 2 * lvlIdx + 2});
            q.pop();
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int32_t main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    node* root = makeTree(v);
    
    cout << widthOfBinaryTree(root);

}

/*
                    1
                3       2
            5     3        9
*/