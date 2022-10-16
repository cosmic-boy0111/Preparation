#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pi pair<int,int>
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

int solve(vector<int>& price,int index,int sum,int count,int buy){
    if(index >= price.size()) return sum;
    if(count < 0) return sum;

    int curr_profit = 0;
    for(int i=index;i<price.size();i++){
        if(price[i] < buy) return solve(price,index+1,sum + curr_profit,count-1,price[i]);
        if(curr_profit < price[i]-buy) curr_profit = max(curr_profit,price[i]-buy);
        else return(price,index+1,sum+curr_profit,count-1,price[i]);
    }

    return curr_profit;


}

int maxProfit(vector<int>&price){

    int n = price.size();
    int dp[n] = {0};
    int mx = price[n-1];
    int mi = price[0];

    for(int i=n-2;i>=0;i--){
        mx = max(mx,price[i]);
        dp[i] = max(dp[i+1],mx-price[i]);
    }

    for(int i=1;i<n;i++){
        mi = min(mi,price[i]);
        dp[i] = max(dp[i-1],dp[i] + (price[i]-mi));
    }

    return dp[n-1];

}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int>arr(n);
    for(auto &x : arr) cin >> x;

    cout << maxProfit(arr);



    return 0;
}