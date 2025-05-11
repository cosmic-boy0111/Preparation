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

int binaryToDecimal(int n){
    int ans = 0;
    int x = 1;
    while(n > 0){
        int y = n%10;
        ans += x*y;
        x *= 2;
        n /= 10;
    }

    return ans;
}

int octalToDecimal(int n){
    int ans = 0;
    int x = 1;
    while (n > 0){
        int y = n % 10;
        ans += y*x;
        x *= 8;
        n /= 10;
    }

    return ans;
    
}

int hexaDecimalToDecimal(string s){
    int ans = 0;
    int x = 1;
    for(int i=s.size()-1; i >= 0; i--){
        int y = s[i];
        if(y >= '0' && y <= '9'){
            ans += (y-'0')*x;
        }else{
            ans += (y-'A' + 10)*x;
        }
        x *= 16;
    }
    return ans;
}

int decimalToBinary(int n){
    
    vector<int> ans;
    while (n > 0){
        ans.push_back(n % 2);
        n /= 2;
    }

    int ret = 0;
    for(int i = ans.size()-1; i >= 0; i--){
        ret = ret*10 + ans[i];
    }

    return ret;

}

int decimalToOctal(int n){
    
    vector<int> ans;
    while (n > 0){
        ans.push_back(n % 8);
        n /= 8;
    }

    int ret = 0;
    for(int i = ans.size()-1; i >= 0; i--){
        ret = ret*10 + ans[i];
    }

    return ret;

}

string decimalToHexaDecimal(int n){
    
    vector<int> ans;
    while (n > 0){
        ans.push_back(n % 16);
        n /= 16;
    }
    string ret;
    for(int i = ans.size()-1; i >= 0; i--){
        ret.push_back(ans[i] > 9 ? (char)('A' + (ans[i] - 10)) : (char)('0' + ans[i]));
    }

    return ret;

}

int32_t main(){

    int n;
    cin >> n;

    // string s;
    // cin >> s;

    cout << decimalToHexaDecimal(n) << endl;

}