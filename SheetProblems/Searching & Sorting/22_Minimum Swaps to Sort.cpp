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

int minSwaps(vector<int>&nums){
    unordered_map<int,int> mp;
    int n = nums.size();
    for(int i=0;i<n;i++) mp[nums[i]] = i;
    vector<int> temp = nums;
    sort(temp.begin(),temp.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        if(temp[i] == nums[i]) continue;
        ans++;
        nums[mp[temp[i]]] = nums[i];
        nums[i] = temp[i];
        mp[nums[mp[temp[i]]]] = mp[temp[i]];
        mp[nums[i]] = i;
    }

    return ans;
}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;

    cout << minSwaps(v);
    
    
    return 0;
}