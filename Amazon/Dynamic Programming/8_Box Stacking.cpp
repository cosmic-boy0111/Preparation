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


void solve(vector<int> nums,int i,set<vector<int>>& ans){
    if(i >= nums.size()){
        ans.insert(nums);
        return;
    }

    for(int j = i; j < nums.size() ;j++){
        if(j != i and nums[j] == nums[j-1]) continue;
        swap(nums[i],nums[j]);
        solve(nums,i+1,ans);
        swap(nums[i],nums[j]);
    }
}

int solve(int n,int height[],int width[],int length[],vector<int> pre){

    

    int result = 0;
    for(int i=0;i<n;i++){
        vector<int>  curr = {height[i],width[i],length[i]};
        sort(curr.begin(),curr.end());
        set<vector<int>> st;
        solve(curr,0,st);
        for(auto &x : st){
            int h = x[0];
            int w = x[1];
            int l = x[2];
            
        }
    }
    

}


int maxHeight(int height[],int width[],int length[],int n){



}


int32_t main(){
    
    int n;
    cin >> n;

    int height[n];
    int width[n];
    int length[n];

    for(int i=0;i<n;i++) cin >> height[i];
    for(int i=0;i<n;i++) cin >> width[i];
    for(int i=0;i<n;i++) cin >> length[i];

    cout << maxHeight(height,width,length,n);



    return 0;
}