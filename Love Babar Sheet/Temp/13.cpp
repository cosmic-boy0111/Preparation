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

long long ans = 0;
set<vector<int>> st;
void solve(vector<int>& arr, int start, int end)
{
    // Stop if we have reached the end of the array
    if (end == arr.size())
        return;
    // Increment the end point and start from 0
    else if (start > end)
        solve(arr, 0, end + 1);
    // Print the subarray and increment the starting point
    else {
        vector<int> a;
        for(int i=start;i<=end;i++) a.push_back(arr[i]);
        st.insert(a);
        solve(arr, start + 1, end);
    }
    return;
}
long long calcBeauty(int n, vector<int> arr) {
    solve(arr,0,0);
    for(auto &x : st){
        unordered_map<int,int> mp;
        for(auto y : x) mp[y]++;
        ans += mp.size();
    }
    return ans;
}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    cout << calcBeauty(n,v);
    

    return 0;
}