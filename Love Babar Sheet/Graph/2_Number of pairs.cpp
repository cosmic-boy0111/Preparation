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

const int T = 1e5+10;
int parent[T];
int size[T];

void make(int i){
    parent[i] = i;
    size[i] = 1;
}

int find(int v){
    if(parent[v] == v) return v;
    return find(parent[v]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        
        size[a] += size[b];
        size[b] = 0;
        
    }

}


long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n){

    for(int i=0;i<n;i++) make(i);
    for(auto &x : pairs){
        Union(x[0],x[1]);
    }

    long long ans = 0 , sum = 0;
    for(int i=0;i<n;i++){
        cout << size[i] << " ";
        ans += size[i]*sum;
        sum += size[i];
    }cout << endl;

    return ans;

}

int32_t main(){
    
    
    int n , p;
    cin >> n >> p;

    vector<vector<int>> pairs(p,vector<int>(2));
    for(auto &x : pairs){
        cin >> x[0] >> x[1];
    }

    cout << numberOfPairs(pairs,p,n);


    return 0;
} 