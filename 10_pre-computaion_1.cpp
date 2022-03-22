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
#define pb push_back
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int MOD = 1e9+7;

// given T test cases and in each 
// test case a number N. print its factorial
// for each test case % M
// where M = 10^9 + 7.

// cst:
// 1 <= T <= 10^5
// 1 <= N <= 10^5

// const int N = 1e5+10;
// long long fact[N];

// int main(){
//     long long T;
//     cin >> T;
//     fact[0] = fact[1] = 1;
//     inc(i,2,N){
//         fact[i] = i*fact[i-1];
//     }
//     while(T--){
//         int n;
//         cin >> n;

//         cout << fact[n] << endl;
//     }

//     // O(T*N)
//     // O(N) + O(T) = 10^5
    
    
    
//     return 0;
// }


/////////// HASHING  ////////////


// given array a of N integers. given Q queries
// and in each query given a number X, print
// count of that number in array.

// cnst:
// 1 <= N <= 10^5
// 1 <= a[i] <= 10^7
// 1 <= Q <= 10^5

const int N = 1e7+10;
int hsh[N];

int main(){

    int n;
    cin >> n;
    int a[n];

    inc(i,0,n){
        cin >> a[i];
        hsh[a[i]]++;
    }

    int q;
    cin >> q;
    while (q--)         
    {
        int x;
        cin >> x;
        cout << hsh[x] << endl;
    }

    // O(N) + O(Q*N) = O(N^2)  = 10^10
    // O(N) + O(Q) = O(N)  = 10^5

    

    return 0;
}