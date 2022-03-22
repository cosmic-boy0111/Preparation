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
void printBinary(int n){for(int i=10;i>=0;i--){if((n>>i) & 1){cout << 1;}else{cout << 0;}}cout << endl;}

void primeSieve(int n){
    int prime[100] = {0};

    for(int i=2;i<=n;i++){
        if(prime[i] == 0){
            for(int j=i*i;j<=n;j+=i){
                prime[i] = 1;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(prime[i] == 0){
            cout << i << " ";
        }
    }cout << endl;


}

int main(){
    
    int n;
    cin >> n;

    primeSieve(n);

    
    return 0;
}