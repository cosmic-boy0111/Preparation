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

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
unordered_map<char,int> mp;

int romanToInt(string s) {
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int i = 0;
    int sum  = 0;
    while (i < s.size())
    {
        if(s[i] == 'I' and s[i+1] == 'V'){
            sum += 4;
            i+=2;
            continue;
        }
        if(s[i] == 'I' and s[i+1] == 'X'){
            sum += 9;
            i+=2;
            continue;
        }
        if(s[i] == 'X' and s[i+1] == 'L'){
            sum += 40;
            i+=2;
            continue;
        }
        if(s[i] == 'X' and s[i+1] == 'C'){
            sum += 90;
            i+=2;
            continue;
        }
        if(s[i] == 'C' and s[i+1] == 'D'){
            sum += 400;
            i+=2;
            continue;
        }
        if(s[i] == 'C' and s[i+1] == 'M'){
            sum += 900;
            i+=2;
            continue;
        }

        sum += mp[s[i]];
        i++;
    }

    return sum;
    
}


int main(){

    cout << romanToInt("MCMXCIV");
    
    return 0;
}