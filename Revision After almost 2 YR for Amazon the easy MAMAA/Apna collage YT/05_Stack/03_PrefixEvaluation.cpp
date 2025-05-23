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

int prefixEvaluation(string s){

    stack<int> st;
    for(int i = s.size()-1; i>=0; i--){
        char c = s[i];
        if(c >= '0' && c <= '9'){
            st.push(c-'0');
            continue;
        }

        int t1 = st.top();
        st.pop();
        int t2 = st.top();
        st.pop();

        switch (c)
        {
            case '+':
                st.push(t1 + t2);
                break;
            case '-':
                st.push(t1 - t2);
                break;
            case '*':
                st.push(t1 * t2);
                break;
            case '/':
                st.push(t1 / t2);
                break;
            case '^':
                st.push(pow(t1, t2));
                break;
            
            default:
                break;
        }
    }

    return st.top();

}

int32_t main(){

    string s;
    cin >> s;

    int ans = prefixEvaluation(s);
    cout << ans << endl;

}