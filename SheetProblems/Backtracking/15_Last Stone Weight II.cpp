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


bool isSubset(vector<int>& arr,int n,int sum,vector<vector<int>>& dp){
    if(sum ==0 )
        return true;

    if(n==0)
        return false;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    if(arr[n-1] <= sum)
        return dp[n][sum] = isSubset(arr,n-1,sum-arr[n-1],dp) || isSubset(arr,n-1,sum,dp);

    return dp[n][sum] = isSubset(arr,n-1,sum,dp);
    
}


int lastStoneWeightII(vector<int>& stones) {

    int n = stones.size();
    int sum = 0;
    for(auto & x : stones)
        sum+=x;

    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));

    vector<int> ansArray;
    for(int i=0;i<=sum;i++){
        if(isSubset(stones,n,i,dp)){
            ansArray.push_back(i);
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<=ansArray.size();i++){
        if(2*ansArray[i] > sum) break;;
        ans = min(ans,abs(sum-2*ansArray[i]));
    }

    return ans;
}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto & x : v)
        cin >> x;
    
    cout << lastStoneWeightII(v);
    
    return 0;
}