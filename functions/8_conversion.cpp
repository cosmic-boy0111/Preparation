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

int BD(int n){
    int ans = 0;
    int x = 1;
    while (n)
    {
        int y = n%10;
        ans += (x*y);
        n = n/10;
        x = x*2;
    }
    

    return ans;

}

int OD(int n){
    int ans = 0;
    int x = 1;
    while (n)
    {
        int y = n%10;
        ans += (x*y);
        n = n/10;
        x = x*8;
    }
    

    return ans;
}

int HD(string n){
    int ans = 0;
    int x = 1;

    int s = n.size();

    for(int i=s-1;i>=0;i--){
        if(n[i] >= '0' and n[i]<='9') {
            ans += x*(n[i]-'0');
        }else if(n[i] >= 'A' and n[i] <= 'F') {
            ans += x*(n[i]-'A' + 10);
        }
        x*=16;
    }

    return ans;
}

void DB(int n){
    
    for(int i=10;i>=0;i--){
        if((n>>i) & 1 )
            cout << 1;
        else    
            cout << 0;
    }
    
}


int main(){
   
    // int n;
    // cin >> n;

    // cout << BD(n);
    // cout << OD(n);

    // string n;
    // cin >> n;

    // cout << HD(n);

    int n;
    cin >> n;

    DB(n);

    return 0;
}