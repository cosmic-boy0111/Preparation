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



// in 1 sec = 10^7 to 10^8 interations
int32_t main(){

    // int x; // 1 interation
    // int sum = 0; // 2 interations
    // sum = x+x;

    // // number of interations = 3
    // // T = O(3)

    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
        
    // }

    // // TC = O(n);

    // // total 
    // // O(3) + O(n)
    // // so we ignore the constant
    // // so tatol is = O(n);

    // int ct =  0;
    // while(n > 0){
    //     n /= 2;
    //     ct++;
    // }
    
    // // T = O(ct) 
    // // ct is the steps required to to make n zero
    // // and we continusous descrising the value by 2
    // // sp T = O(log(n));


    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= i; j++){
    //         ct++;
    //     }
    // }

    // // T = O(1 + 2 + 3 + 4 ..... + n)
    // // T = O(n(n+1) / 2);
    // // T = O(n^2 / 2) + O(n / 2)
    // // T = O(n^2);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            sum += x;
        }
        cout << sum << endl;
    }

    // T = O(T*N);
    // T = O(N^2);


}

