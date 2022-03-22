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

bool isSatisfy(vector<int> &position,int mid,int m){
    int lastPos = INT_MIN;
        
    for(auto x : position) {
        if(x >= lastPos + mid) {
            lastPos = x;
            m--;
        }
        
        if(m==0) return true;
    }
    
    return false;
}

int maxDistance(vector<int>& position, int m) {
    int lo = 1;
    int hi = INT_MAX;

    sort(position.begin(),position.end());
    // 22 57 74 79
    int ans = 1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(isSatisfy(position,mid,m)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }

    return ans;
    

}

int main(){
    
    vector<int> v = {79,74,57,22};
    int m = 4;

    cout << maxDistance(v,m) << endl;
    
    return 0;
}