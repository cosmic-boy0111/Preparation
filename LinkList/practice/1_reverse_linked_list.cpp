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


node* reverseList(node* root){
    vector<int> tempVector;
    while (root != NULL){
        tempVector.push_back(root->val);
        root = root->next;
    }

    node* dummy = new node(0);
    node* temp = dummy;

    for(int i=tempVector.size()-1;i>=0;i--){
        temp->next = new node(tempVector[i]);
        temp = temp->next;
    }

    return dummy->next;
    
}


void display(node* root){
    if(root == NULL) return;
    cout << root->val << " ";
    display(root->next);
}


node* reverseThreePointer(node* root){
    node* prePtr  = NULL;
    node* currPtr = root;
    node* nextPtr;

    while (currPtr != NULL){
        nextPtr = currPtr->next;
        currPtr->next = prePtr;

        prePtr = currPtr;
        currPtr = nextPtr;
    }

    return prePtr;
    
}


node* reverseLinkList(node* root){
    if(root->next == NULL || root==NULL)
        return root;
    

    node* lastNode = reverseLinkList(root->next);
    root->next->next = root;
    root->next = NULL;

    return lastNode;

}

void inset(node* &root,int val){
    if(root == NULL){
        root =  new node(val);
        return;
    }


    node* temp = root;
    while (temp->next!= NULL){
        temp = temp->next;
    }

    temp->next = new node(val);
    
}

int32_t main(){

    node* root = NULL;
    
    int n;
    cin >> n;
    inc(i,0,n){
        int x;
        cin >> x;
        inset(root,x);
    }
    // display(reverseList(root));
    // display(reverseThreePointer(root));
    display(reverseLinkList(root));

    
    
    
    return 0;
}