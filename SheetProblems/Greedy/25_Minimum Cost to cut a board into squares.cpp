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

int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){

    sort(X.begin(),X.end(),greater<int>());
    sort(Y.begin(),Y.end(),greater<int>());

    int i = 0 , j = 0;
    int hr = 1, vr = 1;

    int ans = 0;

    while (i < M-1 and j < N-1){
        if(X[i] > Y[j]){
            ans += X[i] * vr;
            hr ++;
            i++;
        }else{
            ans += Y[j] * hr;
            vr ++;
            j++;
        }
    }

    int total = 0;
    while (i < M-1){
        total += X[i++];
    }

    ans += total * vr;

    total = 0;
    while (j < N-1){
        total += Y[j++];
    }
    ans += total * hr;


    return ans;
    
    
    

}

int32_t main(){
    
    int m , n;
    cin >> m >> n;
    vector<int> X(m-1);
    for(auto &x : X)
        cin >> x;
    vector<int> Y(n-1);
    for(auto &x : Y)
        cin >> x;
    
    cout << minimumCostOfBreaking(X,Y,m,n);
    
    
    return 0;
}