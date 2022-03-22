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

void printVec(vector<int> &v){
    cout << "size : " << v.size() << endl;
    each(x,v){
        cout << x << " ";
    }cout << endl;
}

int main(){


    // pair<int,string> p;

    // // p = make_pair(2,"abc");
    // p = {2,"abc"};
    // pair<int,string> p1 = p;
    // p1.first = 3;
    // cout << p.first << " " << p.second << endl;

    // int a[] = {1,2,3};
    // int b[] = {2,3,4};

    // pair<int,int> p_array[3];
    // p_array[0] = {1,2};
    // p_array[1] = {2,3};
    // p_array[2] = {3,4};

    // swap(p_array[0],p_array[2]);

    // for(int i=0;i<3;i++){
    //     cout << p_array[i].ff << " " << p_array[i].ss << endl;
    // }
    

    // vector<int> v;
    // int n;
    // cin >> n;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin >> x;
    //     printVec(v); 
    //     v.push_back(x); // 0(1)
    // }

    // printVec(v);

    vi v;
    v.pb(7);
    v.pb(6);
    

    vector<int> v2 = v; // O(n)
    v2.push_back(5);
    printVec(v);
    printVec(v2);



    return 0;
}