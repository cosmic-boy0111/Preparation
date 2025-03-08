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


int32_t main(){

    int n;
    cin >> n;
    // char ch = 'A';
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << ch;
    //         ch += 1;
    //     }cout << endl;
    // }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i; j++){
    //         cout << "* ";
    //     }cout << endl;
    // }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i; j++){
    //         cout << i << " ";
    //     }cout << endl;
    // }

    // char ch = 'A';
    // for(int i = 0 ; i < n; i++){
    //     for(int j = 0 ; j < i+1; j++){
    //         cout << static_cast<char>(ch + i) << " "; 
    //     }cout << endl;
    // }

    // for(int i = 1; i <= n; i++){
    //     for(int j=i; j >= 1; j--){
    //         cout << j << " ";
    //     }cout << endl;
    // }

    // int num = 1;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i; j++){
    //         cout << num << " ";
    //         num++;
    //     }cout << endl;
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < i; j++){
    //         cout << "  ";
    //     }
    //     for(int j = 1; j <= n - i; j++){
    //         cout << i+1 << " ";
    //     }cout << endl;
    // }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n - i; j++){
    //         cout << "  ";
    //     }
    //     for(int j = 1; j <= i; j++){
    //         cout << j << " ";
    //     }
    //     for(int j = i-1; j>=1; j--){
    //         cout << j << " ";
    //     }cout << endl;
    // }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= (n - i)*2; j++){
    //         cout << " ";
    //     }
    //     int space = n - (n - i + 1);
    //     cout << "*";
    //     if(space){
    //         for(int j = 1; j <= (space + i - 2)*2 + 1; j++){
    //             cout << " ";
    //         }
    //         cout << "*";
    //     }cout << endl;
    // }
    // for(int i = n-1; i >=1; i--){
    //     for(int j = 1; j <= (n - i)*2; j++){
    //         cout << " ";
    //     }
    //     int space = n - (n - i + 1);
    //     cout << "*";
    //     if(space){
    //         for(int j = 1; j <=(space + i - 2)*2 + 1; j++){
    //             cout << " ";
    //         }
    //         cout << "*";
    //     }cout << endl;
    // }

    for(int i = 1; i <= n; i++){
        int space = 2*n - 2*i;
        for(int j = 1; j <= i; j++){
            cout << "* ";
        }
        if(space){
            for(int j = 1; j <= space*2; j++){
                cout << " ";
            }
        }
        for(int j = 1; j <= i; j++){
            cout << "* ";
        }cout << endl;
    }

    for(int i = n-1; i >= 1; i--){
        int space = 2*n - 2*i;
        for(int j = 1; j <= i; j++){
            cout << "* ";
        }
        for(int j = 1; j <= space*2 ; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "* ";
        }cout << endl;
    }
    
}