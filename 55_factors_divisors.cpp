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
    int ct = 0;
    int sum = 0;

    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            cout << i << " " << n/i << endl;
            ct+=1;
            sum+=i;
            if(i!=n/i){
                sum+=n/i;
                ct+=1;
            }
        }
    }

    // O(sqrt(N))
    

    cout << ct << " " << sum << endl;
    
    
    return 0;
}