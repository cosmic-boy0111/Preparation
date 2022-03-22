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

bool func(int i)
{
    return i <= 10 ? true : false;
}

int main()
{

    // int a = 5;
    // int b = 3;
    // int c = 4;
    // cout << ((b>a) || (b>c)) << endl;

    // && ||
    // and or

    // int n;
    // cin >> n;

    // if(!(n%2))
    //     cout << "yes " << endl;
    // else
    //     cout << "no" << endl;

    // int i=1;

    // while (i<=10){
    //     cout << i << endl;
    //     i++;
    // }

    // inc(i,1,11){
    //     cout << i << endl;
    // }

    // int i=1;
    // for(;func(i);cout<<i++<<endl){}
    // int n;
    // cin >> n;
    // inc(i,1,n+1){
    //     inc(j,1,i+1){
    //         cout << "*" ;
    //     }cout << endl;

    // }

    // while (true)
    // {
    //     int x;
    //     cin >> x;
    //     if(x==42){
    //         break;
    //     }
    //     cout << x << endl;
    // }

    int n;
    cin >> n;
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n = n / 10;
    }
    cout << sum << endl;
    return 0;
}