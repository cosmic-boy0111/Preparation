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
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            if(((i+j)%4 == 0 ) || (i==2 and j%4==0)){
                cout << "*" << " ";
            }else{
                cout << "  ";
            }
        }cout << endl;
    }
    
    return 0;
}