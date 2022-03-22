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

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size() ;i++){
        if(mp.find(target - nums[i]) != mp.end())
            return {mp[target - nums[i]],i};
        else    
            mp[nums[i]] = i;
    }

    return {} ;
}

int main(){
    
    int n,t;
    cin >> n >> t;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }


    vector<int> ans = twoSum(v,t);
    cout << ans[0] << " " << ans[1] << endl;
    
    return 0;
}