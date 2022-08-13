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

int dp[110];
int solve(int i,int n,string s){
    if(s[i] == '0') return 0;
    if(i >= n) return 1;
    if(dp[i] != -1) return dp[i];
    int temp = stoi(s.substr(i,2));
    if(s[i+1] == '0'){
        if(temp >= 10 and temp <=20){
            return dp[i] = solve(i+2,n,s);
        }
    }

    int ans1 = solve(i+1,n,s);
    int ans2 = 0;
    if(temp >= 10 and temp <=26){
        ans2 = solve(i+2,n,s);
    }

    return dp[i] = ans1 + ans2;
}

int numDecodings(string s) {
    memset(dp,-1,sizeof(dp));
    return solve(0,s.size(),s);

}

int32_t main(){
    
    string s;
    cin >> s;

    cout << numDecodings(s) << endl;
    
    
    return 0;
}