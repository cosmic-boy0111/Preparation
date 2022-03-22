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

unordered_set<string> s;


void generate(string input,string output){
    if(input.size()==0){
        cout << output << endl;
        s.insert(output);
        return;
    }

    // string op1 = output;
    // string op2 = output;
    // op2.push_back(input[0]);

    // input.erase(input.begin()+0);

    // generate(input,op1);
    // generate(input,op2);

    output.push_back(input[0]);
    input.erase(input.begin()+0);

    generate(input,output);
    output.pop_back();
    generate(input,output);



}


int main(){
    
    string input;
    cin >> input ;

    string output = "";

    generate(input,output);

    cout << "unique subsets" << endl;
    for(auto &x:s){
        cout << x << endl;
    }
    
    
    return 0;
}