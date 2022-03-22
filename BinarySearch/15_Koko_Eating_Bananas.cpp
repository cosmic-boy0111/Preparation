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


bool isSafe(vector<int>& piles, int h,int mid){
    int cnt = 0;
    for(int i=0;i<piles.size();i++){
        if(piles[i] <= mid){
            cnt++;
        }else{
            if(piles[i]%mid == 0){
                cnt += piles[i]/mid;
            }else{
                cnt += piles[i]/mid + 1;
            }
        }
    }
    return cnt<=h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int lo = 1;
    int hi = *max_element(piles.begin(),piles.end());

    int ans = 0;
    while (lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(isSafe(piles,h,mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

    return ans;
    
        
}

int main(){
    

    vector<int> v = {30,11,23,4,20};
    int h = 6;

    cout << minEatingSpeed(v,h) << endl;
    
    
    return 0;
}