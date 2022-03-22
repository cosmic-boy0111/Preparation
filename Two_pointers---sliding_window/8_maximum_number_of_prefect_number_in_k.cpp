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

vector<int> perfectSum(N,1);


int maxNumberOfPerfects(int arr[],int n,int k){
    for(int i=2;i<N;i++){
        for(int j=2*i;j<N;j+=i){
            perfectSum[j] += i;
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i] == perfectSum[arr[i]]){
            arr[i] = 1;
        }else{
            arr[i] = 0;
        }
    }

    int sum = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }

    int ans = sum;

    for(int i=k;i<n;i++){
        sum = sum + arr[i] - arr[i-k];
        ans = max(ans,sum);
    }

    return ans;


}

int32_t main(){
    
    int arr[] = {28,2,3,6,496,99,8128,24};
    int k = 4;
    int n = 8;
    
    cout << maxNumberOfPerfects(arr,n,k);
    
    return 0;
}