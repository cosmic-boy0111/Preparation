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
const int t = 1e3+10;
int dp[t][t];



void countSum(vector<int> arr,int n,int sum,int cal,vector<int> temp){

    if(sum == cal){
        for(auto &x: temp)
            cout << x << " ";
        cout << endl;
        return;
    }

    

    if(n == 0) return ;

    if(cal + arr[n-1] <= sum){
        temp.push_back(arr[n-1]);
        cal += arr[n-1];
        countSum(arr,n,sum,cal,temp);
        temp.pop_back();
        cal -= arr[n-1];
        countSum(arr,n-1,sum,cal,temp);
    }

    countSum(arr,n-1,sum,cal,temp);

}



int countSum(vector<int>& nums,int sum,vector<int>& dp){
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(dp[sum-1] != -1) return dp[sum-1];
    int ans = 0;
    
    for(int i=0;i<nums.size();i++){
        ans += countSum(nums,sum-nums[i],dp);
    }

    return dp[sum-1] = ans;
}

int combinationSum4(vector<int>& nums, int target) {
    // countSum(nums,nums.size(),target,0,{});
    vector<int> dp(target,-1);
    return countSum(nums,target,dp);
}

int32_t main(){
   
    int n , t;
    cin >> n >> t;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    // cout << n << " " << t << endl;
    // for(auto &x : v)
    //     cout << x << " ";

    cout << combinationSum4(v,t);

    
    return 0;
}