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


int getVal(int a,int b){
    if(a/float(b) > a/b){
        return a/b + 1;
    }

    return a/b;
}

bool isSatisfy(vector<int> &nums,int threshold,int mid){
    int sum = 0;
    for(auto &x:nums){
        sum += getVal(x,mid);
    }

    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {


    int lo = 1;
    int hi = INT_MAX;

    int ans = 1;
    while (lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(isSatisfy(nums,threshold,mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

    return ans;
    
        
}

int main(){
    
    vector<int> v = {2,3,5,7,11};
    int t = 11;

    cout << smallestDivisor(v,t);
    
    return 0;
}