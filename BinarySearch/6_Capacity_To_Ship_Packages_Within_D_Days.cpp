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

bool isSatisfy(int mid,vector<int>& w,int days){
    int sum = 0;
    int day = 1;

    for(int i=0;i<w.size();i++){
        sum+=w[i];
        if(sum > mid){
            day ++ ;
            sum = w[i];
        }
        if(day > days)
            return false;
    }

    return true;
}

int shipWithinDays(vector<int>& weights, int days) {


    if(weights.size() < days) {
        return -1;
    }
    int hi = 0;
    for(int i=0;i<weights.size();i++){
        hi += weights[i];
    }

    // int res = -1;
    int lo = *max_element(weights.begin(), weights.end());

    // int lo = 1;
    while (hi - lo > 1)
    {
        int mid = (hi+lo) / 2;
        if(isSatisfy(mid,weights,days)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }

    if(isSatisfy(lo,weights,days)){
        return lo;
    }
    if(isSatisfy(hi,weights,days)){
        return hi;
    }

    return -1;
    

}

int main(){
    

    vector<int> w = {1,2,3,1,1};
    int days = 4;
    
    cout << shipWithinDays(w,days);
    
    return 0;
}