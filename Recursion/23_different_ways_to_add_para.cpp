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


int toInt(string s){
    int sum = 0;
    for(auto &t:s){
        sum = sum*10 + (t-'0');
    }

    return sum;
}

vector<int> diffWaysToCompute(string expression) {
    vector<int> ans;

    

    for(int i=0;i<expression.size();i++){
        if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
            string part1 = expression.substr(0,i);
            string part2 = expression.substr(i+1);

            vector<int> part1Data = diffWaysToCompute(part1);
            vector<int> part2Data = diffWaysToCompute(part2);

            for(auto &x:part1Data){
                for(auto &y:part2Data){
                    int sum = 0;
                    switch (expression[i])
                    {
                        case '+':
                            sum = x + y;
                            break;
                        
                        case '-':
                            sum = x - y;
                            break;
                        
                        case '*':
                            sum = x * y;
                            break;
                        
                        default:
                            break;
                    }

                    ans.push_back(sum);
                }
            }
        }
    }

    if(ans.size()==0){
        ans.push_back(toInt(expression));
    }

    sort(ans.begin(),ans.end());

    return ans;


}

int main(){
    

    string expression = "2*3-4*5";

    vector<int> ans  = diffWaysToCompute(expression);
    for(auto &x:ans){
        cout << x << " ";
    }

    
    return 0;
}