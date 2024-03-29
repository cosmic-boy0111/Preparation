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

vector<string> ans;
set<string> st;

void solve(string s, int n, string result){
    for(int i=1;i<=n;i++){
        string temp = s.substr(0,i);
        if(st.find(temp) != st.end()){
            if(i == n){
                result += temp;
                ans.push_back(result);
                return;
            }
            solve(s.substr(i),n-i,result+temp+" ");
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    for(auto &x : wordDict)
        st.insert(x);
    solve(s,s.size(),"");
    return ans;
}

int32_t main(){
    
    string s;
    cin >> s;
    vector<string> dict = {"cat","cats","and","sand","dog"};

    for(auto &x : wordBreak(s,dict))
        cout << x << endl;
    
    
    return 0;
}