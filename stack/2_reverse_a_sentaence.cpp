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


void reverseSentence(string s){
    stack<string> st;
    for(int i=0;i<s.size();i++){
        string word = "";
        while (s[i]!=' ' and i<s.size()){
            word.push_back(s[i]);
            i++;
        }
        st.push(word);
    }

    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }cout << endl;

    
    
}


int main(){
    

    string s = "Hey, how are you doing?";

    reverseSentence(s);


    
    return 0;
}