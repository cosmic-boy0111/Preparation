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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout << "  " ;
        }
        for(int j=i;j>=1;j--){
            cout << "*" << " ";
        }
        for(int j=2;j<=i;j++){
            cout << "*" << " ";
        }cout << endl;
        
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n-i;j++){
            cout << "  " ;
        }
        for(int j=i;j>=1;j--){
            cout << "*" << " ";
        }
        for(int j=2;j<=i;j++){
            cout << "*" << " ";
        }cout << endl;

    }
    
    
    return 0;
}