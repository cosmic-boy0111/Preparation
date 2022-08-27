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

 
int dp[505][2002];
int WordWrap(int i,int rem,vector<int>& nums,int k){
    if(i == nums.size()) return 0;
    if(dp[i][rem] != -1) return dp[i][rem];

    int ans ;
    if(nums[i] > rem){
        ans = (rem+1)*(rem+1) + WordWrap(i+1,k-nums[i]-1,nums,k);
    }else{
        int choice1 = (rem+1)*(rem+1) + WordWrap(i+1,k-nums[i]-1,nums,k);
        int choice2 = WordWrap(i+1,rem-nums[i]-1,nums,k);
        ans = min(choice1,choice2);
    }

    return dp[i][rem] = ans;

}

int solveWordWrap(vector<int>nums, int k) {
    
    memset(dp,-1,sizeof(dp));
    return WordWrap(0,k,nums,k);
    
}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }
    
    
    
    return 0;
}