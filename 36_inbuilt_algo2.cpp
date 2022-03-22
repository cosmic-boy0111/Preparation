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

    // cout << [](int x,int y){return x+y;}(4,7) <<endl;
    // auto sum = [](int x,int y){return x+y;};
    // cout << sum(4,7) << endl;


    vector<int> v={2,4,6};

    cout << all_of(v.begin(),v.end(),[](int x){return x%2==0;}) << endl;
    cout << any_of(v.begin(),v.end(),[](int x){return x>0;}) << endl;
    cout << none_of(v.begin(),v.end(),[](int x){return x>0;}) << endl;
    
    
    return 0;
}