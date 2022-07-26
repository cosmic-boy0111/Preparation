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

set<vector<int>> st;

void choose(vector<int>& candidates, int i, int target, vector<int> temp, int currSum){
    if(currSum == target){
        if(temp.size() !=0)
            st.insert(temp);
        return;
    }
    if(i == candidates.size()){
        return;
    }
    

    if(currSum + candidates[i] <= target){
        currSum += candidates[i];
        temp.push_back(candidates[i]);
        choose(candidates,i,target,temp,currSum);
        currSum -= candidates[i];
        temp.pop_back();
    }

    choose(candidates,i+1,target,temp,currSum);

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    choose(candidates,0,target,{},0);
    vector<vector<int>> ans;
    for(auto &x : st)
        ans.push_back(x);
    return ans;
}

int32_t main(){
    

    int n , k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;

    for(auto &x : combinationSum(v,k)){
        for(auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    
    
    return 0;
}