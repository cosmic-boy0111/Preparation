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


int main(){
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    

// brut force
    // int maxSum = INT_MIN;
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int sum = 0;
    //         for(int k=i;k<=j;k++){
    //             sum += arr[k];
    //         }

    //         maxSum = max(maxSum,sum);
    //     }
    // }
    // cout << maxSum << endl;

// cumulative sum
    // int currSum[n+1];
    // currSum[0] = 0;
    // for(int i=1;i<=n;i++){
    //     currSum[i] = arr[i-1] + currSum[i-1];
    // }

    // int maxSum = INT_MIN;

    // for(int i=1;i<=n;i++){
    //     int sum = 0;
    //     for(int j=0;j<i;j++){
    //         sum = currSum[i] - currSum[j];
    //         maxSum = max(sum,maxSum);
    //     }
    // }

    // cout << maxSum << endl;

// kadane's algorithm

    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum < 0){
            currSum = 0;
        }
        maxSum = max(maxSum,currSum);
    }

    cout << maxSum << endl;
    
    
    
    return 0;
}