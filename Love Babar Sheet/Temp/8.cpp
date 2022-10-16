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

vector<string> func(string textInput){
    // transform(textInput.begin(), textInput.end(), textInput.begin(), ::tolower);
    unordered_map<string,int> mp; 
    string temp = "";
    for(auto &x : textInput){
        if(x == ' '){
            mp[temp]++;
            temp = "";
            continue;
        }
        temp.push_back(x);
    }
    mp[temp] ++;
    vector<pair<int,string>> v;
    for(auto &x : mp){
        v.push_back({x.second,x.first});
    }

    set<string> ans;
    for(auto &x : v){
        if(x.first <= 1) continue;
        ans.insert(x.second);
    }

    vector<string> result;
    for(auto &x : ans) result.push_back(x);

    vector<string> T ;
    T.push_back("NA");
    if(result.size() == 0) return T;
    return result;
}



int32_t main(){
    
    string s = "cat barman latt cat matter matter CaT";

    for(auto &x : func(s))
        cout << x << " ";


    return 0;
}