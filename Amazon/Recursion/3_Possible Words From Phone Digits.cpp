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

unordered_map<int,vector<char>> mp = {
    {2,{'A','B','C'}},
    {3,{'D','E','F'}},
    {4,{'G','H','I'}},
    {5,{'J','K','L'}},
    {6,{'M','N','O'}},
    {7,{'P','Q','R','S'}},
    {8,{'T','U','V'}},
    {9,{'W','X','Y','Z'}},
};

vector<string> ans;
void solve(int a[],int N,int index,string temp){
    if(index >= N) {
        ans.push_back(temp);
        return;
    }

    for(auto &x : mp[a[index]]){
        temp.push_back(x);
        solve(a,N,index+1,temp);
        temp.pop_back();
    }

}

vector<string> possibleWords(int a[], int N){
    solve(a,N,0,"");
    return ans;
}

int32_t main(){
    
    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    for(auto &x : possibleWords(a,N))
        cout << x << endl;
    
    
    return 0;
}