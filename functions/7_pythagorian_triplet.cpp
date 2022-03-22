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

bool check(int x,int y,int z){
    int a = max(x,max(y,z));
    int b,c;
    if(a == x){
        b = y;
        c = z;
    }else if( a == y){
        b = x;
        c = z;
    }else{
        b = x;
        c = y;
    }

    return a*a == b*b + c*c;
}

int main(){
   
    int x,y,z;
    cin >> x >> y >> z;

    if(check(x,y,z)){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    
    
    return 0;
}