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
#define inc(i, a, b) for (int i = a; i < b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)
#define each(x, target) for (auto &x : target)
const int N = 1e6, MOD = 1e9 + 7;

int fact(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }

    return factorial;
}

int main()
{

    int n;
    cin >> n;

    int ans = fact(n);
    cout << ans;

    return 0;
}