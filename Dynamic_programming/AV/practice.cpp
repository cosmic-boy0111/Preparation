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

int rodCutting(vector<int> length,vector<int> prize, int n, int N){
    
    int dp[n+1][N+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=N;j++){
            if(i ==0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=N;j++){
            if(length[i-1] <= j){
                dp[i][j] = max(prize[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][N] ;

}


int coinsChangeWays(vector<int> coins, int n,int sum){

    int dp[n+1][sum+1];
    for( int i=0 ; i<=n ;i++){
        for(int j=0;j<=sum;j++){
            if(i ==0 ) dp[i][j] = 0;
            if(j ==0) dp[i][j] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1] <= j){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}

int minimumCoinsRequired(vector<int> coins, int n, int sum){
    
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i ==0 ) dp[i][j] = INT_MAX-1;
            else if(j==0) dp[i][j] = 0;
            
        }
    }

    for(int i=1;i<=sum;i++){
        if(i%coins[0] == 0){
            dp[1][i] = i/coins[0];
        }else{
            dp[1][i] = INT_MAX-1;
        }
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1] <= j){
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    

    return dp[n][sum];
}


int longestCommonSubsequence(string x,string y,int n,int m){

    if(n ==0 || m ==0 ) return 0;

    if(x[n-1] == y[m-1]){
        return 1+longestCommonSubsequence(x,y,n-1,m-1);
    }

    return max(longestCommonSubsequence(x,y,n-1,m),longestCommonSubsequence(x,y,n,m-1)) ;

}

int longestCommonSubsequenceTopDown(string x,string y, int n, int m){

    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i ==0 || j ==0) dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[i-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][m] ;

}


int longestCommonSubstring(string x,string y, int n,int m){
    
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i ==0 || j ==0)
                dp[i][j] = 0;
        }
    }

    int ans = INT_MIN;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }


    return ans ;

}

string printLCS(string x,string y, int n,int m){

    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i ==0 || j==0) dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }

    int i = n;
    int j = m;

    string s = "";

    while (i > 0 and j > 0){

        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
            continue;
        }
        if(dp[i][j-1] > dp[i-1][j]){
            j--;
            continue;
        }

        i--;

    }


    reverse(s.begin(),s.end());

    return s;
    

}

int shortestCommonSuperSequence(string x,string y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i ==0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }


    return m+n - dp[n][m] ;

}

void minimumInsertionDeletion(string x,string y, int n,int m){
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i ==0 || j==0)   
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }

    cout << n - dp[n][m] << " " << m - dp[n][m] << endl;

}


int longestPalindromicSubsequence(string x,int n){
    string y = x;
    reverse(y.begin(),y.end());

    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i ==0 || j ==0)
                dp[i][j]  = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][n] ;

}

int minimumDeletionPalindromicString(string x, int n){
    string y = x;
    reverse(y.begin(),y.end());

    int dp[n+1][n+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return n-dp[n][n];
}


string printShortestCommonSuperSequence(string x,string y,int n,int m){
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i ==0 || j ==0) dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int i = n;
    int j = m;

    string ans = "";
    while (i > 0 and j > 0){
        if(x[i-1] == y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
            continue;
        }

        if(dp[i][j-1] > dp[i-1][j]){
            ans.push_back(y[j-1]);
            j--;
            continue;
        }

        ans.push_back(x[i-1]);
        i--;
    }

    while (i > 0){
        ans.push_back(x[i-1]);
        i--;
    }

    while (j > 0){
        ans.push_back(y[j-1]);
        j--;
    }
    
    

    reverse(ans.begin(),ans.end());

    return ans;
    


}


int longestRepeatingSubsequence(string x,int n){
    string y = x;

    int dp[n+1][n+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i ==0 || j==0) 
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1] and i != j)
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][n];

}


bool sequencePatternMatching(string x,string y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) 
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return n == dp[n][m];

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


    ///////////// rod cutting problem

    // int n , N;
    // cin >> n >> N;

    // vector<int> length(n);
    // vector<int> prize(n);

    // for(auto &x : length)
    //     cin >> x;
        
    // for(auto &x : prize)
    //     cin >> x;

    // cout << rodCutting(length,prize,n,N) << endl;


    ////////////////// coin change ways

    // int n , sum;
    // cin >> n >> sum ;

    // vector<int> coins(n);
    // for(auto &x: coins)
    //     cin >> x;

    // cout << coinsChangeWays(coins, n, sum) << endl;


    ////////////////// coin change minimum number of coins

    // int n , sum;
    // cin >> n >> sum ;

    // vector<int> coins(n);
    // for(auto &x : coins)
    //     cin >> x;


    // cout << minimumCoinsRequired(coins,n,sum) << endl;


    ///////////////// longest common subsequence recursive

    // string s1;
    // string s2;

    // cin >> s1 >> s2;

    // cout << longestCommonSubsequence(s1,s2,s1.size(),s2.size());

    ///////////// longest common subsequence top down
    // string x , y; 
    // cin >> x >> y;
    // cout << longestCommonSubsequenceTopDown(x,y,x.size(),y.size());


    //////////////// longest common substring

    // string x;
    // string y;

    // cin >> x >> y;

    // cout << longestCommonSubstring(x,y,x.size(),y.size());

    ////////////////// print LCS

    // string x;
    // string y;
    
    // cin >> x >> y;

    // cout << printLCS(x,y,x.size(),y.size());

    ///////////////// shortest common super sequence
    
    // string x;
    // string y;

    // cin >> x >> y;

    // cout << shortestCommonSuperSequence(x,y,x.size(),y.size());

    ////////////////// minimum number of insertion and deletion

    // string x;
    // string y;
    // cin >> x >> y;

    // minimumInsertionDeletion(x,y,x.size(),y.size());


    ////////////// longest palindromic subsequence

    // string x;
    // cin >> x;


    // cout << longestPalindromicSubsequence(x,x.size());


    //////////// minimum number of deletion to make string palindrom

    // string x;
    // cin >> x ;

    // cout << minimumDeletionPalindromicString(x,x.size());

    /////////////// print shortest common super sequence

    // string x;
    // string y;

    // cin >> x >> y;

    // cout << printShortestCommonSuperSequence(x,y,x.size(),y.size());


    //////////////// longest repeating subsequence

    // string x;
    // cin >> x;

    // cout << longestRepeatingSubsequence(x,x.size());

    ///////////////// sequence pattern matching

    // string x, y;
    // cin >> x >> y;

    // cout << sequencePatternMatching(x,y,x.size(),y.size());












        

    
    
    
    return 0;
}