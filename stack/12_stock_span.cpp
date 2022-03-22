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


vector<int> stockSpan(vector<int> prices)  {
    vector<int> ans;
    stack<pair<int,int>> st;
    for(auto &x: prices){
        int days = 1;
        while (!st.empty() and st.top().first <= x){
            days += st.top().second;
            st.pop();
        }

        st.push({x,days});
        ans.push_back(days);
    }

    return ans;
}


int main(){
    

    for(auto x: stockSpan({100,80,60,70,60,75,85})){
        cout << x << " ";
    }
    
    return 0;
}