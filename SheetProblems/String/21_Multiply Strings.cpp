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

string multiply(string num1, string num2) {
    int n1 = 0;
    for(auto & x : num1)
        n1 = n1*10 + (x-'0');
    int n2 = 0;
    for(auto & x : num2)
        n2 = n2*10 + (x-'0');

    long long n3 = n1*n2;
    string ans = "";
    bool under = true;
    while (n3){
        under = false;
        ans.push_back(n3%10 + '0');
        n3 = n3/10;
    }

    if(under) ans.push_back(0+'0');
    
    string temp;
    for(int i=ans.size()-1;i>=0;i--)
        temp.push_back(ans[i]);

    return temp;
}

int32_t main(){
    
    
    string n1 , n2;
    cin >> n1 >> n2;

    cout << multiply(n1,n2);
    
    return 0;
}