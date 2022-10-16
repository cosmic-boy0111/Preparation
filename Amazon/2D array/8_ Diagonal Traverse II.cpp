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

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int mx_size = 0;
    for(auto &x : nums){
        int t = x.size();
        mx_size = max(mx_size,t);
    }
    for(auto &x : nums){
        if(x.size() == mx_size) continue;
        while (x.size() < mx_size){
            x.push_back(-1);
        }
    }

    vector<int> ans;
    int n = nums.size();
    int m = nums[0].size();
    for(int i=0;i<n;i++){
        int r = i;
        int c = 0;
        while (r >= 0 and c < m){
            if(nums[r][c] != -1)
                ans.push_back(nums[r][c]);
            r--;
            c++;
        }
    }

    for(int j=1;j<m;j++){
        int r = n-1;
        int c = j;
        while (r >= 0 and c < m){
            if(nums[r][c] != -1)
                ans.push_back(nums[r][c]);
            r--;
            c++;
        }
    }

    return ans;

}

int32_t main(){
    
    vector<vector<int>> nums = {{1,2,3,4,5},{6,7},{8},{9,10,11}};
    for(auto &x : nums){
        for(auto &y : x)
            cout << y << " ";
        cout << endl;
    }

    for(auto &x : findDiagonalOrder(nums)){
        cout << x << " ";
    }


    return 0;
}