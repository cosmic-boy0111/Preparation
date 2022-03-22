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


void insert(stack<int> &st,int top){

    if(st.empty()){
        st.push(top);
        return;
    }

    int temp = st.top();
    st.pop();
    insert(st,top);

    st.push(temp);


}

void reverse_stack(stack<int> &st){

    // cout << st.top() << " ";

    if(st.size()==1){
        return;
    }


    int top = st.top();
    st.pop();
    reverse_stack(st);

    insert(st,top);

}


int main(){

    stack<int> st;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        st.push(x);
    }

    reverse_stack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
    
    return 0;
}