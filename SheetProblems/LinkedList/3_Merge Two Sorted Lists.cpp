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
        node* next;

        node(int data = 0){
            val = data;
            next = NULL;
        }
};

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);

void display(node* root){
    while (root != NULL){
        cout << root->val << " ";
        root = root->next;
    }
    
}

node* mergeTwoLists(node* root1,node* root2){

    if( !root1  or !root2){
        return !root1 ? root2 : root1;
    }


    if(root1->val < root2->val){
        root1->next = mergeTwoLists(root1->next,root2);
        return root1;
    }

    root2->next = mergeTwoLists(root1,root2->next);
    return root2;


}

int32_t main(){

    node* root1 = new node(1);
    root1->next = new node(2);
    root1->next->next = new node(4);

    node* root2 = new node(1);
    root2->next = new node(3);
    root2->next->next = new node(4);


    display(mergeTwoLists(root1,root2));

    
    return 0;
}