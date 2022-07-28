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

queue<int> solve(queue<int> q, int k){
    if(k == 0) return q;
    int t = q.front();
    q.pop();
    k--;
    queue<int> temp = solve(q,k);
    temp.push(t);
    
    return temp;
}

queue<int> modifyQueue(queue<int> q, int k) {
    queue<int> ans =  solve(q,k);


    for(int i=0;i<ans.size()-k;i++){
        ans.push(ans.front());
        ans.pop();
    }
    
    return ans;
}

int32_t main(){
    
    int n , k;
    cin >> n >> k;
    queue<int> q;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        q.push(x);
    }

    queue<int> result = modifyQueue(q,k);
    while (!result.empty()){
        cout << result.front() << " ";
        result.pop();
    }
    
    
    
    return 0;
}