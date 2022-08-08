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


unordered_map<int,int> mp;

void merge(vector<int> &nums, int l , int mid, int r){
    int i = l;
    int j = mid+1;
    vector<int> temp;
    int c = 0;
    while (i <= mid and j <= r){
        if(nums[i] <= nums[j]){
            mp[nums[i]] += c;
            temp.push_back(nums[i++]);
        }else{
            c++;
            temp.push_back(nums[j++]);
        }
    }
    while (i<=mid){
        mp[nums[i]] +=c;
        temp.push_back(nums[i++]);
    }

    while (j <= r){
        temp.push_back(nums[j++]);
    }

    int p = 0;
    for(int k = l ; k <= r ;k++){
        nums[k] = temp[p++];
    }
    
}

void mergeSort(vector<int> &nums, int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
}

vector<int> countSmaller(vector<int> &nums) {

    vector<int> temp(nums.size());
    for(int i=0;i<nums.size();i++){
        temp[i] = nums[i];
    }
    mergeSort(temp,0,temp.size()-1);

    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        ans.push_back(nums.size()-i-1-mp[nums[i]]);
    }

    return ans;

}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(auto &x : countSmaller(v))
        cout << x << " ";
    
    return 0;
}