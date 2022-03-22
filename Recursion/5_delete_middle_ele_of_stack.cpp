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


void delete_middle(stack<int> &st,int k){

    if(st.size()==0){
        return;
    }

    if(k==1){
        st.pop();
        return;
    }
    int top = st.top();
    st.pop();
    delete_middle(st,k-1);

    st.push(top);


}


int main(){

    // 1 2 3 4 5
    stack<int> st;
    int n;
    cin >> n;
    inc(i,0,n){
        int x;
        cin >> x;
        st.push(x);
    }

    int k = n/2 + 1;

    delete_middle(st,k);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}