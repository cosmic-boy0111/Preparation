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
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i] ;
    }

    int min = *(min_element(v.begin(),v.end()));

    cout  << min << endl;

    int max = *(max_element(v.begin(),v.end()));

    cout  << max << endl;

    int sum = accumulate(v.begin(),v.end(),0);

    cout << sum << endl;

    int ct = count(v.begin(),v.end(),6);

    cout << ct << endl;

    auto it = find(v.begin(),v.end(),10);

    if(it != v.end())
        cout << (*it) << endl;
    else   
        cout << "element no found" << endl;


    reverse(v.begin(),v.end());
    inc(i,0,n){
        cout << v[i] << " ";
    }cout << endl;

    
    
    return 0;
}