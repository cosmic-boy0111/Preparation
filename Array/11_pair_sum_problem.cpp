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


bool pairSum(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == k){
                cout << i << " " << j << endl;
                return true;
            }
        }
    }

    return false;
}

bool pairSum2(int arr[],int n,int k){

    // int lo = 0,hi = n-1;
    // while (lo < hi){
    //     if(arr[lo] + arr[hi] == k){
    //         cout << lo << " " << hi << endl;
    //         return true;
    //     }else if(arr[lo] + arr[hi] > k){
    //         hi--;
    //     }else{
    //         lo++;
    //     }
    // }

    // return false;

    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]] = i;
    }
    
    for(int i=0;i<n;i++){
        if(mp.find(k-arr[i]) != mp.end()){
            cout << i << " " << mp[k-arr[i]] << endl;
            return true;
        }
    }

    return false;
    

}

int main(){
    
    
    int arr[] = {2,4,7,11,14,16,20,21};
    int k = 31;

    cout << pairSum2(arr,8,k);
    
    return 0;
}