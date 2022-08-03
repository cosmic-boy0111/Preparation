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
        int data;
        node* left;
        node* right;

        node(int val = 0){
            data = val;
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

int ans = INT_MAX;

void solve(vector<int> & jobs, vector<int> &temp, int n , int m){
    if(n == 0){
        ans = min(ans,m);
        return;
    }

    if(m >= ans) return;
    for(int i=0;i<temp.size();i++){

        if(i>0 && temp[i]==temp[i-1]) continue;

        temp[i] += jobs[n-1];
        int t = m;
        m = max(m,temp[i]);
        solve(jobs,temp,n-1,m);
        m = t;
        temp[i] -= jobs[n-1];

    }
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    
    vector<int> temp(k,0);
    int n = jobs.size();
    int m = INT_MIN;
    sort(jobs.begin(),jobs.end());
    solve(jobs,temp,n,m);
    return ans;
}

int32_t main(){
    
    int n , k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &x : arr)
        cin >> x;
    
    cout << minimumTimeRequired(arr,k);


    
    return 0;
}