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



int check(vector<int> &nums, int mid){
    
    int cnt = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=mid){
            cnt++;
        }
    }

    return cnt;

}


int specialArray(vector<int>& nums) {
    // t t t t t f f f f 
    int lo = 0,hi = 1000;
    while (lo<=hi)
    {
        int mid = (lo+hi)/2;
        int cnt = check(nums,mid);
        if(cnt == mid){
            return mid;
        }else if(cnt > mid){
            lo = mid+1;
        }else{
            hi = mid-1;
        }

    }

    return -1;
    
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << specialArray(arr);
    
    
    return 0;
}