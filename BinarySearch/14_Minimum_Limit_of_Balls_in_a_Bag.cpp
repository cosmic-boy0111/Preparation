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

int minimumSize(vector<int>& nums, int maxOperations) {
    int lo = 1;
    int hi=*max_element(nums.begin(),nums.end());  
    int ans = 0;

    while (lo <= hi){
        int mid = lo + (hi-lo)/2;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > mid){
                if(nums[i]%mid==0)
                    cnt += nums[i]/mid-1;
                else    
                    cnt += nums[i]/mid;
            }
        }
        if(cnt > maxOperations){
            lo = mid+1;
        }else{
            ans = mid;
            hi = mid-1;
        }
    }
    
    return ans;

}

int main(){
    


    
    
    return 0;
}