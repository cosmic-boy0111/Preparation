#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pi pair<int, int>
#define mi map<int, int>
#define umi unordered_map<int, int>
#define qi queue<int>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff first
#define ss second
#define pb push_back
#define inc(i, a, b) for (int i = a; i < b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)
#define each(x, target) for (auto &x : target)
const int N = 1e6, MOD = 1e9 + 7;

int main(){

    // string str = "hello world";
    // cout << str << endl;
    // string str2;
    // cin >> str2;

    // cout << str2 << endl;
    // string str1 = "Hello";
    // string str2 = "World";

    // string result = str1 + str2;
    // cout << result << endl;

    // if(str1 == str2)
    //     cout << "equal" << endl;
    // else
    //     cout << "not equal" << endl;
    // str1[0] = 'a';
    // cout << str1.size() << endl;
    // // cout << str1[0] << endl;

    // inc(i,0,str1.size()){
    //     cout << str1[i] << endl;
    // }

    // int t;
    // cin >> t;
    // cin.ignore();
    // while (t--)
    // {
    //     string s;
    //     getline(cin,s);
    //     cout << s << endl;
    // }

    string str;
    cin >> str;
    string str_rev;
    dec(i,str.size()-1,0){
        str_rev.push_back(str[i]);
    }
    cout << str_rev << endl;

    return 0;
}