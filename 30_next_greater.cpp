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


vector<int> NGE(vector<int> v){
    vector<int> nge(v.size());
    stack<int> st;
    for(int i=0;i<v.size();i++){
        while (!st.empty() and v[i]>v[st.top()]){
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()){
        nge[st.top()] = -1;
        st.pop();
    }

    return nge;
    
}


int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    vector<int> nge = NGE(v);

    for(int i=0;i<n;i++){
        cout << v[i] << " " << (nge[i]==-1?-1:v[nge[i]]) << endl;
    }
    
    return 0;
}