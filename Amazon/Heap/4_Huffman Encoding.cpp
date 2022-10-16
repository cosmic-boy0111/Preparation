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

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

TreeNode(int data = 0){
val = data;
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

vector<pair<int,int>> pos = {
    {0,-1},{-1,0},{0,1},{1,0},
    {-1,-1},{-1,1},{1,1},{1,-1}
};

class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }

};


void travel(Node* root,string temp,vector<string>& ans,unordered_map<int,bool>& mp){

    if(root == NULL) return;
    
    travel(root->left,temp+'0',ans,mp);
    if(mp.find(root->data) != mp.end()) ans.push_back(temp);
    travel(root->right,temp+'1',ans,mp);

}

vector<string> huffmanCodes(string S,vector<int> f,int N){

    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    unordered_map<int,bool> mp;
    for(auto &x : f){
        mp[x] = true;
        pq.push({x,new Node(x)});
    }

    while ( pq.size() > 1 ){
        auto p1 = pq.top();
        pq.pop();
        auto p2 = pq.top();
        pq.pop();
        Node* n = new Node(p1.first+p2.first);
        n->left = p1.second;
        n->right = p2.second;
        pq.push({n->data,n});
    }

    vector<string> ans;
    travel(pq.top().second,"",ans,mp);
    return ans;

}

int32_t main(){
    

    string s = "";
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;

    for(auto &x : huffmanCodes(s,v,n))
        cout << x << " ";
    



    return 0;
}