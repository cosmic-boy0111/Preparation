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

int get_max_area(vector<int> a){
    int n = a.size();
    int ans = 0;
    int i = 0;

    a.push_back(0);
    stack<int> st;
    while (i < n){

        while (!st.empty() and a[st.top()] > a[i]){
            int t  = st.top();
            int h = a[t];
            st.pop();

            if(st.empty()){
                ans = max(ans,h*i);
            }else{

                int len = i - st.top() - 1;
                ans = max(ans,h*len);
            }
        }

        st.push(i);
        

        i++;
    }

    return ans;
    
}

int main(){
    
    vector<int> a = {1,2,3,4,5};

    cout << get_max_area(a) << endl;
    
    
    return 0;
}