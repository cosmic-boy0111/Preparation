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


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans(nums1.size());
    unordered_map<int,int> mp;
    stack<int> st;
    for(int i=nums2.size()-1;i>=0;i--){
        while(!st.empty() and st.top() <= nums2[i])
            st.pop();
        if(st.empty()){
            mp[nums2[i]] = -1;
        }else{
            mp[nums2[i]] = st.top();
        }

        st.push(nums2[i]);
    }

    for(int i=0;i<nums1.size();i++){
        ans[i] = mp[nums1[i]];
    }

    return ans;

}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int> v1(n);
    for(auto &x : v1)
        cin >> x;

    int m;
    cin >> m;
    vector<int> v2(m);
    for(auto &x : v2)
        cin >> x;
    
    for(auto & x : nextGreaterElement(v1,v2))
        cout << x << " ";
    cout << endl;

    
    
    return 0;
}