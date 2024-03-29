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
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

class Node{
    public:
        int val;
        Node* next;

        Node(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(Node* &root,int val){
    if(root == NULL){
        root = new Node(val);
        return;
    }
    Node* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new Node(val); 
}

void display(Node* root){
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

bool ans = false;

bool isValid(vector<int> sums){
    for(int i=0;i<sums.size()-1;i++)
        if(sums[i] != sums[i+1])
            return false;
    return true;
}

void solve(vector<int>& nums, int idx, vector<int> sums, int target){\

    if(ans) return;

    if(idx == nums.size()){
        if(isValid(sums))
            ans = true;
        return;
    }

    for(int i=0;i<sums.size();i++){
        if(sums[i] + nums[idx] <= target){
            sums[i] += nums[idx];
            solve(nums,idx+1,sums,target);
            sums[i] -= nums[idx];
        }
        if(sums[i] ==0 ) break;
    }

}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(),nums.end(),0)  ;
    if(sum%k) return false;
    vector<int> sums(k,0);
    solve(nums,0,sums,sum/k);
    return ans;
}

int32_t main(){
    int n , k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;

    cout << canPartitionKSubsets(v,k);
    
    return 0;
}