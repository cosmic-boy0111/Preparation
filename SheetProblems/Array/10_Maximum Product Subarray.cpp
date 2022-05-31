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
        int val;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);


int maxProduct(vector<int>& nums) {

    int ans = nums[0];
    int mn = nums[0];
    int mx = nums[0];

    for(int i=1;i<nums.size();i++){
        if(nums[i] < 0)
            swap(mn,mx);
        
        mn = min(nums[i],mn*nums[i]);
        mx = max(nums[i],nums[i]*mx);

        ans = max(ans,mx);
    }


    return ans;
    
}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int> ans(n);
    for(auto &x : ans)
        cin >> x;

    cout << maxProduct(ans) << endl;

    return 0;
}