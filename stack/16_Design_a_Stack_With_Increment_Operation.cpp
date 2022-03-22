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

class CustomStack {
public:
    int i = -1;
    vector<int> v;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(i == n-1){
            return;
        }
        i++;
        v.push_back(x);
    }
    
    int pop() {
        if(i == -1)
            return -1;
        int ans = v[i];
        v.pop_back();
        i--;
        return ans;
    }
    
    void increment(int k, int val) {
        int j = 0;
        while ( j<k and j<=i ){
            v[j] = v[j] + val;
            j++;
        }
    }
};

int main(){
   
    
    CustomStack st(3);
    st.push(1);
    st.push(2);

    cout << st.pop() << endl;
    st.push(2);
    st.push(3);
    st.push(4);

    st.increment(5,100);
    st.increment(2,100);

    for(auto &x:st.v){
        cout << x << " ";
    }cout << endl;

    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;


    
    return 0;
}