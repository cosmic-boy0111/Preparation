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

// int checkForSum(vector<int> &nums,int sum,int i,int j){
//     for(int k=0;k<nums.size();k++){
//         if(nums[k] == sum and k!=i and k!=j)
//             return k;
//     }

//     return -1;
// }


vector<int> twoSum(vector<int>& nums, int target,int selected) {
    unordered_map<int,int> mp;
    for(int i=0;i< nums.size() ;i++){
        if(i == selected) continue;
        if(mp.find(target - nums[i]) != mp.end())
            return {mp[target - nums[i]],i};
        else    
            mp[nums[i]] = i;
    }

    return {} ;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    set<vector<int>> s;
    int n = nums.size();
    for(int i=0;i<n-2;i++){
        int val = nums[i];
        int l = i+1;
        int r = n-1;
        while ( l < r ){
            int sum = val + nums[l] + nums[r];
            if(sum == 0){
                s.insert({val , nums[l++] , nums[r--]});
            }else if(sum < 0){
                l++;
            }else{
                r--;
            }
        }
        
    }

    for(auto & x : s)
        ans.push_back(x);

    return ans;
}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int> v(n);

    for(auto & x: v)
        cin >> x;

    for(auto & x : threeSum(v)){
        for(auto & y : x)
            cout << y << " ";
        cout << endl;
    }
    
    return 0;
}