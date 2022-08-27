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

int ans  = 0;
unordered_set<string> st;

bool check(string s){
    if(s.size() <= 1) return true;
    int mid = s.size() / 2;
    for(int i=0;i<mid;i++)
        if(s[i] != s[s.size()-i-1]) return false;
    return true;
}

void solve(int i,string str,string temp){
    if(st.find(temp) != st.end()) return;
    if(i >= str.size()){
        if(check(temp) and temp != "" and st.find(temp) == st.end()){
            ans  = (ans + 1)%1000000007;
            st.insert(temp);
        }
        return;
    }

    temp.push_back(str[i]);
    solve(i+1,str,temp);
    temp.pop_back();
    solve(i+1,str,temp);

}

long long int  countPS(string str){
    solve(0,str,"");
    return ans;
}




int32_t main(){
    
    string s;
    cin >> s;

    cout << countPS(s);
    
    
    return 0;
}