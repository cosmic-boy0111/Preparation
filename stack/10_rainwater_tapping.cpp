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


int tap(vector<int> v){
    int ans = 0;
    stack<int> st;
    int i = 0 , n = v.size();


    while (i < n){
        while (!st.empty() and v[st.top()] < v[i]){

            int t = st.top();
            st.pop();

            if(st.empty()){
                break;
            }

            int diff = i - st.top() -1;
            ans += (min(v[st.top()],v[i]) - v[t])*diff ;

        }
        st.push(i);
        i++;
    }

    return ans;
    
}

int main(){

    vector<int>  v = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << tap(v);
    
    return 0;
}