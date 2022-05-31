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

bool pairInSortedRotated(vector<int> &v,int n,int x){

    int i ;
    
    for(i=0;i<n-1;i++){
        if(v[i] > v[i+1])
            break;
    }

    int l = (i+1)%n;
    int r = i;


    while (l!=r){
        if(v[l] + v[r] == x)
            return true;
        if(v[l] + v[r] < x)
            l = (l+1)%n;
        else
            r = (r-1+n)%n;
    }

    return false;
    

}

int32_t main(){
    
    int n , x;
    cin >> n >> x;
    vector<int> v;
    for(int i=0;i<n;i++){
        int y;
        cin >> y;
        v.push_back(y);
    }
    
    cout << pairInSortedRotated(v,v.size(),x);

    
    return 0;
}