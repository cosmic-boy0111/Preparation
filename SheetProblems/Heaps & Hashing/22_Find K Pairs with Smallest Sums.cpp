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

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int i = 0;
    int j = 0;
    vector<vector<int>> ans;
    while (true){
        ans.push_back({nums1[i],nums2[j]});
        // cout << nums1[i] << " " << nums2[j] << endl;
        if(ans.size() == k) break;
        if(i == nums1.size()-1 and j == nums2.size()-1)  break;
        if(i == nums1.size()-1){
            i = 0;
            j++;
        } 
        else if(j == nums2.size()-1){
            j = 0;
            i++;
        }
        else if(nums1[i] + nums2[j+1] < nums1[i+1] + nums2[j]) j++;
        else i++;
    }
    
    return ans;

}

int32_t main(){

    int n , k;
    cin >> n >> k;
    vector<int> v1(n);
    vector<int> v2(n);
    for(auto &x : v1)
        cin >> x;
    for(auto &x : v2)
        cin >> x;

    
    for(auto &x : kSmallestPairs(v1,v2,k)){
        cout << x[0] << " " << x[1] << endl;
    }
    
    return 0;
}