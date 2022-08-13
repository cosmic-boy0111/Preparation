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

set<vector<int>> st;

void choose(vector<int>& candidates, int i, int target, vector<int> temp, int currSum, int k){
    if(temp.size() > k) return;
    if(currSum == target and temp.size() == k){
        if(temp.size() !=0){
            st.insert(temp);
        }
        return;
    }
    if(i == candidates.size()){
        return;
    }
    

    if(currSum + candidates[i] <= target){
        currSum += candidates[i];
        temp.push_back(candidates[i]);
        choose(candidates,i+1,target,temp,currSum,k);
        currSum -= candidates[i];
        temp.pop_back();
    }

    choose(candidates,i+1,target,temp,currSum,k);

}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> v;
    for(int i=1;i<=9;i++){
        v.push_back(i);
    }
    choose(v,0,n,{},0,k);
    vector<vector<int>> ans;
    for(auto &x : st){
        ans.push_back(x);
    }

    return ans;
}

int32_t main(){
    
    int k , n;
    cin >> k >> n;

    vector<vector<int>> v = combinationSum3(k,n);
    
    
    
    return 0;
}