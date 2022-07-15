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

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
  
int printMinCountPrime(int N)
{
  
    int minCount;
  
    if (isPrime(N)) {
        minCount = 1;
    }
  
    else if (N % 2 == 0) {
        minCount = 2;
    }
  
    else {
  
        if (isPrime(N - 2)) {
            minCount = 2;
        }
  
        else {
            minCount = 3;
        }
    }
    return minCount;
}

int getsum(int n){
    int sum = 0;
    for(int i=1;i<=n;i++){ 
        if(n%i==0){
            sum=sum+i;
        }
    }
    return sum;
}

int32_t main(){
    

    int n;
    cin >> n;
    int X = printMinCountPrime(n);
    int y = getsum(n);
    cout << ((4^2)+7) << endl;
    cout << X << " " << y << endl;
    cout << (n xor X + y) << endl;

    
    
    
    
    return 0;
}