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


void nextPermutation(vector<int>& nums) {

    int n = nums.size() - 1;
    int l = n - 1 ;
    int r = n;

    while ( l >= 0 and nums[l] >= nums[l+1]){
        l--;
    }

    if(l == 0)
        reverse(nums.begin(),nums.end());
    else{
        while (nums[l] >= nums[r]){
            r--;
        }

        swap(nums[l],nums[r]);

        reverse(nums.begin()+l+1,nums.end());
    }
    
    
}


int32_t main(){
    
    int n;
    cin >> n;
    vector<int > nums(n);

    for(auto &x : nums){
        cin >> x;
    }       

    nextPermutation(nums);
    
    for(auto &x : nums){
        cout << x << " ";
    }cout << endl;
    
    
    return 0;
}