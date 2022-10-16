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

vector<pair<int,int>> pos = {
    {0,-1},{-1,0},{0,1},{1,0},
    {-1,-1},{-1,1},{1,1},{1,-1}
};

map<int,int> mp;

int subtreeSum(TreeNode* root){
    if(root == NULL) return 0;
    int sum = root->val + subtreeSum(root->left) + subtreeSum(root->right);
    mp[sum]++;
    return sum;
}

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.first > p2.first;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    subtreeSum(root);
    vector<pair<int,int>> v;
    for(auto & x : mp){
        v.push_back({x.second,x.first});
    }
    sort(v.begin(),v.end(),cmp);
    vector<int> ans;

    if(v.size() == 0) return {};
    int frq = v[0].first;
    for(auto &x : v){
        if(x.first == frq) ans.push_back(x.second);
    }



    return ans;
}

int32_t main(){
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);


    vector<int> ans = findFrequentTreeSum(root);
    for(auto &x : ans) cout << x << " ";


    return 0;
}