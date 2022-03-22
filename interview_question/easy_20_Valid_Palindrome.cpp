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

bool isPalindrome(string s) {
    string newStr = "";
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(c >= 'A' and c<='Z'){
            newStr.push_back(char(c+32));
        }else if((c >= '0' and c <= '9') || (c>='a' and c<='z')){
            newStr.push_back(c);
        }
    }

    bool ans = true;

    for(int i=0;i<newStr.size()/2;i++){
        if(newStr[i] != newStr[newStr.size()-i-1]){
            ans = false;
            break;
        }
    }

    return ans;
}

int main(){
    
    string s = " ";
    cout << isPalindrome(s);
    
    return 0;
}