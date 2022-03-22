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


/*
    given array a of n interger all intergers are present in even count expect one. find that one interger which has odd count in O(n) time and O(1) space complexity
*/


int main(){
    
/*
    x^x == 0
    x^0 == x

*/

    // int a = 4 , b = 6;

    // a = a ^ b;
    // b = b ^ a; //---> a
    // a = a ^ b;

    // cout << a << " " << b << endl;

    int n;
    cin >> n;
    int x;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> x;
        ans ^= x;
        cout << ans << endl;
    }
    cout << ans << endl;
    
    
    return 0;
}