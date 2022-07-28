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

string FirstNonRepeating(string A){
    
    string ans;
    ans.push_back(A[0]);
    unordered_map<char,int> s;
    queue<char> q;
    s[A[0]]++;
    q.push(A[0]);
    for(int i=1; i<A.size(); i++){
        if(A[i]==q.front()){
            q.pop();
            while(s[q.front()]>1 and q.size()>0) q.pop();
            if(q.empty()) q.push('#');
            ans.push_back(q.front());
        }
        else{
            s[A[i]]++;
            if(s[A[i]]==1){ 
                q.push(A[i]);
                if(q.front()=='#')q.pop();
            }
            while(s[q.front()]>1  and q.size()>0) q.pop();
            ans.push_back(q.front());
        }
    }
    return ans;
}

int32_t main(){
    
    string s;
    cin >> s;


    cout << FirstNonRepeating(s) << endl;
    
    return 0;
}