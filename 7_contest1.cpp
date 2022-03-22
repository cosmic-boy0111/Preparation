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

char upper(char c){
    return char(c-32);
}

int main(){

/// 1st que

    // while (true)
    // {
    //     string s;
    //     cin >> s;
    //     if(s.size()==0){
    //         break;
    //     }
    //     inc(i,0,s.size()){
    //         s[i] = upper(s[i]);
    //     }

    //     cout << s << endl;
    // }

/// 2nd que

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n;
    //     cin >> n;
    //     long long result = 1;
    //     inc(i,0,n){
    //         int x;
    //         cin >> x;
    //         result *= x;
    //     }

    //     int least = result%10;
    //     if(least==2 || least==3 || least==5){
    //         cout << "YES" << endl;
    //         continue;
    //     }

    //     cout << "NO" << endl;
    // }
    
//// 3rd que

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n;
    //     cin >> n;
    //     string s;
    //     cin >> s;

    //     long long sum = 0;
    //     long long pow2 = 1;

    //     dec(i,n-1,0){
    //         int digit = s[i] - '0';
    //         sum += (digit*pow2);
    //         pow2 *= 2;
    //     }

    //     cout << sum << endl;
    // }
    
/// que 4

    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     long long n;
    //     cin >> n;
    //     cout << n*4 << endl;
    // }


// que 5

    int a,b,c;
    cin >> a >> b >> c;
    int cth_no;

    for(int i=1;c>0;i++){
        if(i%a==0 || i%b==0){
            c--;
            cth_no = i;
        }
    }
    
    int lcm;
    for(int i=1;i<=a*b;i++){
        if(i%a ==0 && i%b==0){
            lcm = i;
            break;
        }
    }

    int step;
    if(cth_no%a == 0 && cth_no%b == 0){
        step = lcm;
    }else if(cth_no%a == 0){
        step = a;
    }else{
        step = b;
    }


    for(int i=cth_no;i>=0;i=i-step){
        cout << i << " ";
    }
    
    
    
    return 0;
}