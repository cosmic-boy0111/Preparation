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

void printHello(){
    cout << "hello world" << endl;
}

int sum(int a,int b){
    int result = a+b;
    return result;
}

void increment(int &n){
    n++;
}

// void swap(int &a,int &b){
//     int temp = a;
//     a = b;
//     b = temp;    
// }


void func(int a[]){
    a[0] = 5;
    // cout << a.size() << endl;
}

int main(){
    


    // printHello();
    // cout << sum(2,3) << endl;

    // int n = 3;
    // cout << n << endl;

    // increment(n);

    // cout << n << endl;

    // int a = 3;
    // int b = 5;

    // cout << a << " " << b << endl;
    // swap(a,b);
    // cout << a << " " << b << endl;


    // string s = "hello";
    // cout << s << endl;
    // func(s);
    // cout << s << endl;

    
    int a[10];
    a[0] = 7;
    cout << a[0] << endl;

    func(a);

    cout << a[0] << endl;

    
    return 0;
}