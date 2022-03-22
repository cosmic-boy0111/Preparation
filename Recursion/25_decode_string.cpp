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

string decodeString(string s) {
    
    if(s.size()<=1){
        return s;
    }

    bool check = true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='['){
            check = false;
            break;
        }
    }

    if(check){
        return s;
    }


    string pre_str = "";
    int pre = 10;
    int sum = 0;
    int i=0;
    stack<char> st;
    string next = "";
    for(i=0;i<s.size();i++){
        if(s[i]=='['){
            st.push(s[i]);
            i++;
            while (!st.empty())
            {
                if(s[i]=='['){
                    st.push('[');
                    next.push_back('[');
                }
                else if(s[i]==']'){
                    st.pop();
                    if(st.size()>=1)
                        next.push_back(']');
                }else{
                    next.push_back(s[i]);
                }
                i++;
            }

            break;
        }
        if(s[i]>='0' and s[i]<='9'){
            sum = sum*pre + (s[i]-'0');
        }else{
            pre_str.push_back(s[i]);
        }
    }

    string pre_str2 = "";
    string temp = decodeString(next);


    for(int i=0;i<sum;i++){
        pre_str2 += temp;
    }


    return (pre_str + pre_str2) + decodeString(s.substr(i));



}

int main(){
    
    string s;
    cin >> s;


    cout << decodeString(s);



    
    
    return 0;
}