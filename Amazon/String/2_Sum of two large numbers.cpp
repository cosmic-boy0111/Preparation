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

string findSum(string X, string Y) {
    if(X.size() < Y.size())
        swap(X,Y);
    
    string upY = "";
    for(int i=0;i<X.size()-Y.size();i++)
        upY.push_back('0');
    for(int i=0;i<Y.size();i++)
        upY.push_back(Y[i]);

    string ans = "";
    int ext = 0;
    int i = X.size()-1;
    while ( i >= 0 ){
        int t = X[i]-'0' + upY[i]-'0' + ext;
        ans.push_back(t%10 + '0');
        ext = t/10;
        i--;
    }
    if(ext != 0) ans.push_back(ext+'0');
    reverse(ans.begin(),ans.end());
    string result = "";
    bool is0 = true;
    for(int i=0;i<ans.size();i++){
        if(ans[i] != '0' and is0) is0 = false;
        if(is0 == false) result.push_back(ans[i]);
    }
    return result == "" ? "0" : result;
}

int32_t main(){
   
    string x , y;
    cin >> x >> y;

    cout << findSum(x,y);
    
    
    
    return 0;
}