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

/*
0123
()()


1
*/

int maxLen(string s) {
    // code here
    stack<char> st;
    int previousSum = 0;
    int temp = 0;
    int ans = 0;
    for(auto& x : s){
        if(x == '('){
            st.push(x);
            continue;
        }
        
    }    
}

int32_t main(){

    string s;
    cin >> s;

    vector<string> lovdispValues;

    string temp = "";
    for(auto& x : s){
        if(x == ','){
            lovdispValues.push_back(temp);
            temp = "";
            continue;
        }
        temp.push_back(x);
    }
    lovdispValues.push_back(temp);

    string values;
    bool first = true;
    for (const auto& lovValue : lovdispValues)
    {
        if(first && lovValue.size() > 255)
        {
            cout << "break 1" << endl;
            break;
        }
        cout << lovValue << " " << values.size() << " 1 " << lovValue.size() << " : " <<  values.size() + 1 + lovValue.size() << endl;
        if(!first && values.size() + 1 + lovValue.size() > 255)
        {
            cout << "break 2" << endl;
            break;
        }
        if (!first)
        {
            values += ',';
        }
        values += lovValue;
        first = false;
    }
    cout << s << endl;
    cout << values << endl;
    cout << values.size() << endl;
    values = "\"" + values +  "\"";

}

/*
1234
*/
/*

( ( ) ) ) ) ( ) ( ) ) ( ) ( ) ( ( ) (
0 0 0 0 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 6


        temp = 4
*/