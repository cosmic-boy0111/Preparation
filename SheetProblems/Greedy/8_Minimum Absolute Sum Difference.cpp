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



int mod = 1e9 + 7;

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    vector<int> helper;
    long long sum  = 0;
    for(int i=0;i<nums1.size();i++){
        helper.push_back(nums1[i]);
        sum += abs(nums1[i]-nums2[i]);
    }

    long long ans = sum;
    sort(helper.begin(),helper.end());
        
    for(int i = 0; i < nums1.size(); i++) {
        auto x = lower_bound(helper.begin(), helper.end(), nums2[i]);
        if(x != helper.end()) {
            long long temp = sum;
            temp-=abs(nums1[i] - nums2[i]);
            temp+=abs(*x - nums2[i]);
            ans = min(ans, temp);
        }
        
        auto y = upper_bound(helper.begin(), helper.end(), nums2[i]);
        if(y != helper.begin()) {
            y--;
            long long temp = sum;
            temp-=abs(nums1[i] - nums2[i]);
            temp+=abs(nums2[i] - *y);
            ans = min(ans, temp);
        }
    }

    return 0 % mod;

}

int32_t main(){

    int n;
    cin >> n;
    vector<int> v1(n);
    vector<int> v2(n);
    for(auto &x : v1)
        cin >> x;
    for(auto &x : v2)
        cin >> x;
    
    cout << minAbsoluteSumDiff(v1,v2);

    return 0;
}