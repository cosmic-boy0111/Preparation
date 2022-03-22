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
const int N = 1e6, MOD = 1e9+7;

// N < 100000
// a[i] < 100000


int main(){
    
    // int x;
    // int sum = 0;
    // sum = x+x;
    // int n;
    // cin >> n;
    // for(int i=0;i<n;i++){
    //     int y;
    //     y = 5;
    //     y++;
    // }

    
// given an array print sum of array in each text case
// 1 <= T <= 100000
// 1 <= N <= 100000
// 1 <= a[i] <= 1000
// sum of N over all test cases is less than 10^7

    int t;
    cin >> t;
    int cnt = 0;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        inc(i,0,n){
            int x;
            cin >> x;
            sum += x;
            cnt ++;
        }

        cout << sum << endl;
    }
    
// O(T*N) = O(N^2) = O(10^7)



    return 0;
}

// number of iteration => 3
// n < 100000
// O(5) + O(3*n)

// 1sec = 10^7 = 10^8

// O(n)