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

vector<string> avoidExplosion(vector<vector<int>> mix, int n,vector<vector<int>> danger, int m) {

    unordered_map<int,vector<int>> mp;
    set<vector<int>> temp;
    for(auto &x : danger){
        temp.insert(x);
        temp.insert({x[1],x[0]});
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }



    
    set<int> st;
    vector<string> ans;
    for(auto &x : mix){
        if(temp.find(x) != temp.end()){
            ans.push_back("No");
            continue;
        }
        bool flag = true;
        for(auto &y  :x){
            if(mp.find(y) != mp.end()){
                
                for(auto &z : mp[y]){
                    if( !st.empty() and st.find(z) != st.end()){
                        flag = false;
                        break;
                    }
                     
                }
            }
            if(!flag) break;
        }
        if(flag){
            st.insert(x[0]);
            st.insert(x[1]);
            ans.push_back("Yes");
        }else{
            ans.push_back("No");
        }
    }

    return ans;

}

int s0(int a,int b){
    if(b and a) return 3 + s0(0,2) + s0(b-5,0);
    return a + b;
}

int32_t main(){
    int n = 4, m = 2;
    vector<vector<int>> mix = {{1, 2}, {2, 3}, {1, 3}, {2, 4}};
    vector<vector<int>> danger = {{2, 4}, {1, 4}};

    cout << endl;
    for(auto &x : avoidExplosion(mix,n,danger,m)){
        cout << x << " ";
    }

    
}
