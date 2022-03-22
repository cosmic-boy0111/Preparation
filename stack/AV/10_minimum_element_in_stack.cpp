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

stack<int> st;
stack<int> ss;


// O(n) space aproch
void push(int a){
    st.push(a);
    if(ss.empty() || a <= ss.top())
        ss.push(a);
}

int top(){
    if(st.empty())
        return -1;
    int ans = st.top();
    st.pop();
    if(ss.top() == ans)
        ss.pop();
    return ans;
}

int getMin(){
    if(ss.empty())
        return -1;
    return ss.top();
}


// O(1) space aproch

int ME = -1;
int minEle(){
    if(st.empty())
        return -1;
    return ME;
}

void push(int a){
    if(st.empty()){
        st.push(a);
        ME = a;
    }else{
        if(a >= ME){
            st.push(a);
        }else{
            st.push(2*a - ME);
            ME = a;
        }
    }
}

void pop(){
    if(st.empty())
        return ;
    else{
        if(st.top() >= ME)
            st.pop();
        else{
            ME = 2*ME - st.top();
            st.top();
        }
    }
}


int top(){
    if(st.empty())
        return -1;
    else{
        if(st.top() >= ME){
            return st.top();
        }else{
            return ME;
        }
    }
}


int main(){
    

    
    
    
    return 0;
}