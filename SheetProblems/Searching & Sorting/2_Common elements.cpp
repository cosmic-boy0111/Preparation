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

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){

    unordered_map<int,int> mp;
    mp[A[0]]++;
    for(int i=1;i<n1;i++){
        if(A[i] != A[i-1])
            mp[A[i]]++;
    }
    mp[B[0]]++;
    for(int i=1;i<n2;i++){
        if(B[i] != B[i-1])
            mp[B[i]]++;
    }
    mp[C[0]]++;
    for(int i=1;i<n3;i++){
        if(C[i] != C[i-1])
            mp[C[i]]++;
    }

    vector<int> ans;
    for(auto &x : mp)
        if(x.second == 3)
            ans.push_back(x.first);

    sort(ans.begin(),ans.end());

    return ans;

}

int32_t main(){
    
    int n1, n2 , n3;
    cin >> n1 >> n2 >> n3;
    int A[n1], B[n2], C[n3];
    for(int i=0;i<n1;i++) cin >> A[i];
    for(int i=0;i<n2;i++) cin >> B[i];
    for(int i=0;i<n3;i++) cin >> C[i];

    for(auto &x : commonElements(A,B,C,n1,n2,n3));
    
    return 0;
}