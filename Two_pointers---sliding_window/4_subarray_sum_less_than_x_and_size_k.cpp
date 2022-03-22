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

int maxSubarraySum(int arr[],int n,int k,int x){
    int sum = 0, ans = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }
    if(sum < x)
        ans = sum;

    for(int i=k;i<n;i++){
        sum = sum - arr[i-k] + arr[k];
        if(sum < x)
            ans = max(ans,sum);
    }

    return ans;
}

int main(){
    

    int arr[] = {7,5,4,6,8,9};
    int n = 6;
    int k = 3;
    int x = 20;

    cout << maxSubarraySum(arr,n,k,x) << endl;

    
    return 0;
}