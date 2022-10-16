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


string rremove(string s){
    if(s.size() == 1) return s;
    stack<pair<char,int>> st;
    for(auto &x : s){
        if(st.empty()){
            st.push({x,1});
            continue;
        }
        if(st.top().first == x){
            auto t = st.top();
            st.pop();
            st.push({x,t.second+1});
            continue;
        }
        if(st.top().second != 1){
            st.pop();
        }
        if(st.top().first == x){
            auto t = st.top();
            st.pop();
            st.push({x,t.second+1});
            continue;
        }
        st.push({x,1});

    }
    if(!st.empty() and st.top().second != 1) st.pop();
    string ans = "";
    while ( !st.empty() ){
        ans.push_back(st.top().first);
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
    
}

int32_t main(){
    
    string s;
    cin >> s;

    cout << rremove(s);


    return 0;
}