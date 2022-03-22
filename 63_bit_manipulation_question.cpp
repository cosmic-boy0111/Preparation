// que 1

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


// int main(){
    
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long long n;
//         cin >> n;
//         cout << __builtin_popcountll(n) << endl;
//     }
    
    
//     return 0;
// }


// que 2


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
    
    int c;
    cin >> c;
    int bit_ct = int(log2(c)) + 1;
    int a = 0 , b =0;
    vector<int> set_bits;
    for(int i=0;i<bit_ct;i++){
        if(c&(1<<i)){
            set_bits.push_back(i);
        }else{
            a |= (1<<i);
            b |= (1<<i);
        }
    }

    int sz = 1<< set_bits.size();
    long long ans = -1;
    for(int mask = 0; mask < sz; mask++){
        int a_copy = a, b_copy = b;
        for(int j=0;j<set_bits.size();j++){
            if(mask & 1<<j){
                a_copy |= (1<<set_bits[j]);
            }else{
                b_copy |= (1<<set_bits[j]);
            }
        }

        ans = max(ans,a_copy*1LL*b_copy);
    }

    cout << ans << endl;
    
    return 0;
}



