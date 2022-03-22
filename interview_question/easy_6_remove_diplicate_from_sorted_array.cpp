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


int removeDuplicates(vector<int> nums) {
    int temp = INT_MIN;
    vector<int> ans;
    // int k = 0;
    for(auto &x:nums){
        if(temp != x) ans.push_back(x);
        temp = x;
    }
    // k = ans.size();
    nums = ans;

    return ans.size();

}

int main(){
    
    cout << removeDuplicates({1,1,2});
    
    
    return 0;
}