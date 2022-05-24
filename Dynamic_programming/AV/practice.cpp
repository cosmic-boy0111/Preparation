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

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);


int knapsackRecursive(vector<int> val,vector<int> wt,int n,int W){

    if(n== 0 || W == 0){
        return 0;
    }


    if(wt[n-1] <= W){
        int choose = val[n-1] + knapsackRecursive(val,wt,n-1,W-wt[n-1]);
        int notChoose = knapsackRecursive(val,wt,n-1,W);

        return max(choose,notChoose);
    }

    return knapsackRecursive(val,wt,n-1,W);

}

map<pair<int,int>, int> memo;

int knapsackMemorization(vector<int> val,vector<int> wt,int n,int W){

    if(n== 0 || W == 0){
        return 0;
    }

    if(memo.find({n,W}) != memo.end()){
        return memo[{n,W}];
    }


    if(wt[n-1] <= W){
        int choose = val[n-1] + knapsackMemorization(val,wt,n-1,W-wt[n-1]);
        int notChoose = knapsackMemorization(val,wt,n-1,W);

        return memo[{n,W}] = max(choose,notChoose);
    }

    return memo[{n,W}] = knapsackMemorization(val,wt,n-1,W);

}

int knapsackTopDown(vector<int> val,vector<int> wt,int n,int W){

    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i ==0 || j ==0 ){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];

}

bool subsetSum(vector<int> val,int n,int sum){

    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i ==0 )
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }


    for( int i=1; i<=n ;i++){
        for(int j=1;j<=sum;j++){
            if(val[i-1] <= j){
                dp[i][j] = dp[i-1][j-val[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}

bool equalSum(vector<int> val, int n){
    int sum = accumulate(val.begin(),val.end(),0);

    if(sum%2 == 0){
        return subsetSum(val,n,sum/2);
    }else{
        return false;
    }

}

int countSubsets(vector<int> val,int n,int sum){

    int dp[n+1][sum+1] ;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i ==0 ) dp[i][j] = 0;
            if(j ==0 ) dp[i][j] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(val[i-1] <= j){
                dp[i][j] = dp[i-1][j-val[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}

int subsetDifference(vector<int> val,int n){

    int sum = accumulate(val.begin(),val.end(),0);
    vector<int> subsetSumVec;
    for(int i=0;i<=sum;i++){
        if(subsetSum(val,n,i)){
            subsetSumVec.push_back(i);
        }
    }

    int ans = INT_MAX;
    for(int i=0;i<subsetSumVec.size()/2;i++){
        ans = min(ans,sum-2*subsetSumVec[i]);
    }

    return ans;

}

int countSubsetDifference(vector<int> val,int n,int diff){
    int sum = accumulate(val.begin(),val.end(),0);
    int s = (diff+sum)/2;

    int dp[n+1][s+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(val[i-1] <= j){
                dp[i][j] = dp[i-1][j-val[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][s];

}

int targetSum(vector<int> val,int n,int sumGiven){


    int sum = accumulate(val.begin(),val.end(),0);
    int s = (sumGiven+sum)/2;

    int dp[n+1][s+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(val[i-1] <= j){
                dp[i][j] = dp[i-1][j-val[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][s];



}

int32_t main(){
    
    ////////////////////// 0-1 knapsack recursive
    // int n,W;
    // cin >> n >> W;
    // vector<int> val;
    // vector<int> wt;
    // for(int i=0;i<n;i++){
    //     int v,w;
    //     cin >> v >> w;
    //     val.push_back(v);
    //     wt.push_back(w);
    // }


    // cout << knapsackRecursive(val,wt,n,W) << endl;

    /////////////////////  0-1 knapsack memorization
    // int n,W;
    // cin >> n >> W;
    // vector<int> val;
    // vector<int> wt;
    // for(int i=0;i<n;i++){
    //     int v,w;
    //     cin >> v >> w;
    //     val.push_back(v);
    //     wt.push_back(w);
    // }


    // cout << knapsackMemorization(val,wt,n,W) << endl;


    /////////////////// 0-1 knapsack dop-down approach
    // int n,W;
    // cin >> n >> W;
    // vector<int> val;
    // vector<int> wt;
    // for(int i=0;i<n;i++){
    //     int v,w;
    //     cin >> v >> w;
    //     val.push_back(v);
    //     wt.push_back(w);
    // }

    // cout << knapsackTopDown(val,wt,n,W) << endl;

    ////////////////// subset sum problem

    // int n,sum;
    // cin >> n >> sum;

    // vector<int> val(n);
    // for(auto &x:val){
    //     cin >> x;
    // }

    // cout << subsetSum(val,n,sum) << endl;


    //////////////// equal sum problem
    // int n;
    // cin >> n;
    // vector<int> val(n);

    // for(auto &x:val){
    //     cin >> x;
    // }

    // cout << equalSum(val,n);

    /////////////// count of subsets

    // int n , sum;
    // cin >> n >> sum;

    // vector<int> val(n);
    // for(auto &x:val){
    //     cin >> x;
    // }

    // cout << countSubsets(val,n,sum);

    /////////////// minimum subset sum difference

    // int n;
    // cin >> n;
    // vector<int> val(n);

    // for(auto &x:val){
    //     cin >> x;
    // }


    // cout << subsetDifference(val,n);

    ////////////// count number of subset with given difference

    // int n,diff;
    // cin >> n >> diff;
    // vector<int> val(n);
    // for(auto &x:val){
    //     cin >> x;
    // }

    // cout << countSubsetDifference(val,n,diff);


    ///////////// target sum

    // int n,sum;
    // cin >> n >> sum;
    // vector<int> val(n);

    // for(auto &x:val){
    //     cin >> x;
    // }

    // cout << targetSum(val,n,sum);


    ///////////// 


        

    
    
    
    return 0;
}