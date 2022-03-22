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

///// prefix sum in 1D array /////

// given array a of N integers. given Q queries
// and in each query given L and R print sum of
// array ele from index L to R(L, R included)

// cnst:
// 1 <= N <= 10^5
// 1 <= a[i] <= 10^9
// 1 <= Q <= 10^5
// 1 <= L,R <= N

// const int N = 1e5+10;
// int a[N];
// int pre[N];


// int main(){
    
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         cin >> a[i];
//         pre[i] = pre[i-1] + a[i];
//     }

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int l,r;
//         cin >> l >> r;
//         cout << pre[r] - pre[l-1] << endl;
//     }

//     // O(n) + O(Q*N) = O(N^2) = 10^10;
//     // O(n) + o(q) = O(N) = 10^5;
    
    
    
//     return 0;
// }


// given 2d array a of N*N integers. Given Q
// queries and in each query given a, b, c and d
// print sum of square represented by (a,b) as
// top left point and (c,d) as bottom right point

// cnst:
// 1 <= N <= 10^3
// 1 <= a[i][j] <= 10^9
// 1 <= Q <= 10^5
// 1 <= a,b,c,d <= N

const int N = 1e3+10;
int ar[N][N];
long long pre[N][N];

int main(){

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> ar[i][j];
            pre[i][j] = ar[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        // long long sum = 0;
        // for(int i=a;i<=c;i++){
        //     for(int j=b;j<=d;j++){
        //         sum = sum + ar[i][j];
        //     }
        // }

        // cout << sum << endl;

        cout << pre[c][d] - pre[a-1][d] - pre[c][b-1] + pre[a-1][b-1] << endl;
    }

    // O(N^2)  +O(Q*N^2) = 10^11;
    // O(N^2) = 10^6;
    

    return 0;
}