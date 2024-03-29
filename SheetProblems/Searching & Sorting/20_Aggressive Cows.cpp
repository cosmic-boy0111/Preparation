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

bool isSatisfy(vector<int>& nums,int dist,int k){
    k--;
    int pre = nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i] - pre >= dist){
            k--;
            if(k == 0) return true;
            pre = nums[i];
        }
    }

    return false;
}

int AggressiveCows(vector<int> nums,int k){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int l = nums[0];
    int r = nums[n-1];
    while (r-l > 1){
        int mid = (l+r)/2;
        if(isSatisfy(nums,mid,k)){
            l = mid;
        }else{
            r = mid-1;
        }
    }

    if(isSatisfy(nums,r,k)) return r;
    return l;
    

}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        int n , k;
        cin >> n >> k;
        vector<int> v(n);
        for(auto &x : v)
            cin >> x;
        cout << AggressiveCows(v,k);
    }
    
    
    
    return 0;
}


