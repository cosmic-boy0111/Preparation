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

bool isFeasible(int arr[],int n,int k,int mid){
    int pos = arr[0];
    int elements = 1;
    for(int i=1; i<n; i++){
        if(arr[i]-pos >= mid){
            elements++;
            pos = arr[i];
            if(elements == k)
                return true;
        }
    }

    return false;
}

int largestMinDistance(int arr[],int n,int k){
    sort(arr,arr+n);
    int result = -1;
    int lo = 1;
    int hi = arr[n-1];
    while (lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(isFeasible(arr,n,k,mid)){
            result = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }

    return result;
    
}

int main(){
    
    int arr[] = {1,2,8,4,9};
    int n = 5;
    int k = 3;

    cout << largestMinDistance(arr,n,k) << endl;
    
    return 0;
}