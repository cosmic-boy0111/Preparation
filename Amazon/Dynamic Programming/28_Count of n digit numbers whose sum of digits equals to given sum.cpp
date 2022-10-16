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

long dp[102][1002];

long solve(int n,int curr,int sum,string temp){

    if(curr == n and sum == 0){
        return 1;
    }
    if(curr >= n) return 0;
    if(sum < 0) return 0;

    if(dp[curr][sum] != -1) return dp[curr][sum];

    long ans = 0;

    for(int i=0;i<=9;i++){
        if(curr == 0 and i == 0)continue;
        curr += 1;
        sum -= i;
        ans = (ans + solve(n,curr,sum,temp))%1000000007;
        curr -= 1;
        sum += i;
    }

    return ans%1000000007;

}

long int countWays(int n, int Sum){
    memset(dp,-1,sizeof(dp));
    long ans = solve(n,0,Sum,"");
    return ans == 0 ? -1 : ans;
}

int32_t main(){
    
    int n , sum;
    cin >> n  >> sum ;

    cout << countWays(n,sum);



    return 0;
}