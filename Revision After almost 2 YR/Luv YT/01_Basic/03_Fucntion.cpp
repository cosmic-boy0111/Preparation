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

void printBinary(int n){
    for(int i=10;i>=0;i--){
        if((n>>i) & 1) cout << 1;
        else cout << 0;
    }cout << endl;
}

class node{
    public:
        int val;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];


void printHello(){
    cout << "Hello world!" << endl;
}

int sum(int a, int b){
    int result = a + b;
    return result;
}

int digit_sum(int n){
    int digit_sum = 0;
    while (n)
    {
        digit_sum += n % 10;
        n /= 10;
    }
    return digit_sum;
}

void increment(int& n){
    n++;
}

void swap(int& a, int& b){
    a = a + b;
    b = a - b;
    a = a - b;
}

int32_t main(){

    // printHello();

    // cout << sum(1, 1) << endl;

    // int a, b;
    // cin >> a >> b;
    // cout  << digit_sum(a) + digit_sum(b) << endl;

    int a =  3;
    int b = 5;
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;

    
    return 0;

}