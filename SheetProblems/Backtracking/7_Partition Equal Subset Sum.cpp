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

map<pair<int,int>,int> mp;
bool subsetSum(vector<int> nums,int n,int temp,int sum){
    if(n==0) return false;
    if(temp == sum) return true;
    if(mp.find({n,temp}) != mp.end()) return mp[{n,temp}];
    if(temp + nums[n-1] <= sum){
        return mp[{n,temp}] = subsetSum(nums,n-1,temp + nums[n-1],sum) || subsetSum(nums,n-1,temp,sum);
    }
    return mp[{n,temp}] = subsetSum(nums,n-1,temp,sum);
}

bool canPartition(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    for(auto &x : nums)
        sum+=x;
    if(sum%2 == 1) return false;
    return subsetSum(nums,n,0,sum/2);
}

int32_t main(){
    

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;

    cout << canPartition(v) ;

    
    
    
    return 0;
}