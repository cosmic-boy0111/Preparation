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

struct Item{
    int value;
    int weight;
};


bool cmp(struct Item a1, struct Item a2){
    double r1 = double(a1.value) / double(a1.weight);
    double r2 = double(a2.value) / double(a2.weight);
    return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr,arr+n,cmp);

    double amount = 0.0;
    for(int i=0;i<n and W;i++){
        if(W >= arr[i].weight){
            amount += double(arr[i].value);
            W -= arr[i].weight;
            continue;
        }
        amount += double(double(arr[i].value)*double(W)/double(arr[i].weight));
        break;
    }
    return amount;

}

int32_t main(){
    

    int n , W;
    cin >> n >> W;
    Item arr[n];
    for(int i =0 ;i<n;i++){
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << fractionalKnapsack(W,arr,n);

    
    return 0;
}