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


bool canMake(vector<int>& bloomDay, int m, int k,int mid){
    int cnt = 0;
    int adj = 0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i] <= mid){
            adj++;
            if(adj == k){
                cnt++;
                adj = 0;
            }
        }else{
            adj = 0;
        }
    }

    return cnt >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int lo = *min_element(bloomDay.begin(),bloomDay.end());
    int hi = *max_element(bloomDay.begin(),bloomDay.end());

    int ans = -1;

    while (lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(canMake(bloomDay, m, k,mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

    return ans;
    

}


int main(){
    

    vector<int> v = {7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;

    cout << minDays(v,m,k) << endl;
    
    
    return 0;
}