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
void printBinary(int n){for(int i=10;i>=0;i--){if((n>>i) & 1){cout << 1;}else{cout << 0;}}cout << endl;}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    while (n--)
    {
        nums1.pop_back();
    }

    for(auto &x:nums2){
        nums1.push_back(x);
    }


    sort(nums1.begin(),nums1.end());
    
}

int main(){
    

    vector<int> nums1 = {1,5,3,0,0,0};
    vector<int> nums2 = {2,2,6};

    merge(nums1,3,nums2,3);

    for(auto x : nums1){
        cout << x << " ";
    }
    
    
    return 0;
}