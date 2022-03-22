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

// S1 = "0"
// S2 = "011" 100
// S3 = "0111001"
// S4 = "011100110110001"


char findKthBit(int n, int k) {
    if(n==1 and k==1){
        return '0';
    }

    int mid = pow(2,n)/2 ;
    if(k == mid){
        return '1';
    }

    if(k < mid)
        return findKthBit(n-1,k);

    char c = findKthBit(n-1,((mid-1)-(k - mid))+1);
    if(c=='1')
        return '0';
    return '1';

}

int main(){
    
    int n, k;
    cin >> n >> k;

    cout << findKthBit(n,k);
    
    return 0;
}
