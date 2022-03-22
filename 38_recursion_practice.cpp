// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vs vector<string>
// #define vb vector<bool>
// #define pi pair<int,int>
// #define mi map<int,int>
// #define umi unordered_map<int,int>
// #define qi queue<int>
// #define vpi vector<pi>
// #define vvi vector<vi>
// #define ff first
// #define ss second 
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;

// int solve(int n,int k){
//     if(n==1 and k==1){
//         return 0;
//     }

//     int mid = pow(2,n-1)/2;

//     if(k<=mid)
//         return solve(n-1,k);

//     return !solve(n-1,k-mid);
    
// }

// int main(){
    

//     int n,k;
//     cin >> n >> k;
//     cout <<  solve(n,k);
    
    
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vs vector<string>
// #define vb vector<bool>
// #define pi pair<int,int>
// #define mi map<int,int>
// #define umi unordered_map<int,int>
// #define qi queue<int>
// #define vpi vector<pi>
// #define vvi vector<vi>
// #define ff first
// #define ss second 
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;


// int trap(vector<int>& height) {
//     stack<int> st;
//     int ans  = 0;
//     for(int i=0;i<height.size();i++){
//         while(!st.empty() and height[st.top()] < height[i]){
//             int cur = st.top();
//             st.pop();
//             if(st.empty()){
//                 break;
//             }
//             int diff = i - st.top() - 1;
//             ans += (min(height[st.top()],height[i]) - height[cur])*diff;
//         }
//         st.push(i);
//     }

//     return ans;
// }


// int main(){
    
//     vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

//     cout << trap(height) << endl;
    
//     return 0;
// }


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

vector<vector<int>> ans;
void generate(int sum,int i,vector<int> &temp,vector<int> &nums,int target){

    if(sum==target){

    }
    

}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
}

int main(){
    
    
    
    return 0;
}

