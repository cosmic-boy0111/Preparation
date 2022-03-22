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



int main(){

    // int n;
    // cin >> n;
    // // int a[n];
    // vector<int> v(n);
    // inc(i,0,n){
    //     cin >> a[i];
    // }

    // // sort(a,a+n);
    // sort(v.begin(),v.end());

    // inc(i,0,n){
    //     cout << a[i] << " ";
    // }cout << endl;

    // // int *ptr = lower_bound(a,a+n,5);
    // auto ptr = lower_bound(v.begin(),v.end(),5);

    // // if(ptr == (a+n)) {
    // //     cout << "not found" << endl;
    // //     return 0;
    // // }
    // if(ptr == v.end()) {
    //     cout << "not found" << endl;
    //     return 0;
    // }

    // cout << (*ptr) << endl;


    int n;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }

    auto it = s.lower_bound(5); // O(log(n))
    // auto it2 = lower_bound(s.begin(),s.end(),5); // o(n)

    cout << (*it) << endl;
    
    
    return 0;
}