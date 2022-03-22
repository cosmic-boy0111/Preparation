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

void print(multiset<string> &s){
    each(x,s){
        cout << x << endl;
    }
}

int main(){

    // set<string> s;
    // s.insert("abc"); // log(n)
    // s.insert("tu7");
    // s.insert("sdf");
    // s.insert("abc");

    // auto it = s.find("abcd");
    // if(it != s.end()){
    //     // cout << (*it) << endl;
    //     s.erase(it);
    // }else{
    //     cout << "NO" << endl;
    // }

    // print(s);

    // unordered_set<staring> s;

    multiset<string> s;
    s.insert("abc"); // log(n)
    s.insert("tu7");
    s.insert("sdf");
    s.insert("abc");

    auto it = s.find("abc");
    if(it != s.end()){
        // cout << (*it) << endl;
        s.erase(it);
    }else{
        cout << "NO" << endl;
    }

    print(s);


    
    return 0;
}