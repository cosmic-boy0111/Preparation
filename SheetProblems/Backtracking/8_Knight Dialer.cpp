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

int mod = 1e9+7;

long func(int i, int j, int hops, vector<vector<vector<long>>> &dp){
    if(i<0 || i>=4 || j<0 || j>=3 || (i==3 && j!=1))  return 0;
    if(hops == 1)   return 1;
    
    if(dp[i][j][hops] != -1)
        return dp[i][j][hops];
    
    dp[i][j][hops] = func(i-2, j-1, hops-1, dp)%mod+func(i-2, j+1, hops-1, dp)%mod+
                    func(i-1, j-2, hops-1, dp)%mod+func(i+1, j-2, hops-1, dp)%mod+
                    func(i-1, j+2, hops-1, dp)%mod+func(i+1, j+2, hops-1, dp)%mod+
                    func(i+2, j-1, hops-1, dp)%mod+func(i+2, j+1, hops-1, dp)%mod;
    
    return dp[i][j][hops];
}

int knightDialer(int n) {
    vector<vector<vector<long>>> dp (4, vector<vector<long>> (3, vector<long> (n+1, -1)));
    long ans=0;
    for(int i=0; i<4; i++)
        for(int j=0; j<3; j++)
            ans = (ans+func(i, j, n, dp))%mod;
    
    return (int)ans;
}

int32_t main(){
    
    int n;
    cin >> n;

    cout << knightDialer(n);
    
    
    return 0;
}