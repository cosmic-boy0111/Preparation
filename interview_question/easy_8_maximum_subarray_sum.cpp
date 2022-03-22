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

int maxSubArray(vector<int> nums) {
    int len =nums.size();
    int sum=0 ,max=INT_MIN;
    for(int i=0;i<len;i++){
        sum=sum+nums[i];
        if(max<sum){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return max;
}

int main(){
    
    cout << maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
    
    return 0;
}