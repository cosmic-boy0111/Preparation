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
#define pb push_back
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e6, MOD = 1e9+7;



int main(){

    // stack<int> s;
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);

    // while (!s.empty())
    // {
    //     cout << s.top() << endl;
    //     s.pop();
    // }

    queue<string> q;

    q.push("abc");
    q.push("dfg");
    q.push("ett");
    q.push("ryu");
    

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    
    
    
    
    return 0;
}