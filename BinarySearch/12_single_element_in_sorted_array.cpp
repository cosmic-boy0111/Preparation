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

int singleNonDuplicate(vector<int>& nums) {
    int low=0;
    int high= nums.size()-2;
    while(low<=high){
        int mid =low+(high-low)/2;
        if(mid%2==0){
            if(nums[mid+1]==nums[mid]) low=mid+1;
            else high=mid-1;
        }
        else{
            if(mid-1>=0 && nums[mid-1]==nums[mid]) low=mid+1;
            else high=mid-1;
        }
    }
    return nums[low];
}

int main(){
    long long T;
    cin >> T;
    while(T--){
        
    }
    
    
    
    return 0;
}