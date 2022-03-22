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


//  A U B  = A + B - A n B
// A U B U C = A + B + C - AnB - BnC - CnA + AnBnC

bool isVowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

vector<string> subsets(string s){
    int sz = 1<<s.size();

    vector<string> ans;
    for(int mask=0;mask<sz;mask++){
        string subset = "";
        for(int bit = 0;bit<s.size();bit++){
            if(mask & (1<<bit)) subset.push_back(s[bit]);
        }
        if(subset.size())
            ans.push_back(subset);
    }

    return ans;

}

int main(){
    long long T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string str[n];
        for(int i=0;i<n;i++){
            cin >> str[i];
        }
        unordered_map<string, int> hsh;
        for(int i=0;i<n;i++){
            set<char> distinct_vw;
            for(auto &c:str[i]){
                if(isVowel(c)){
                    distinct_vw.insert(c);
                }
            }
            string vowel_str;
            for(auto &ch: distinct_vw){
                vowel_str.push_back(ch);
            }

            vector<string> all_subsets = subsets(vowel_str);

            for(auto &x:all_subsets){
                hsh[x] ++;
            }


        }

        long long ans = 0;
        for(auto &pr:hsh){
            if(pr.second < 3) continue;
            long long ct = pr.second;
            long long ways = ct * (ct - 1) * (ct - 2) / 6;
            if(pr.first.size()%2 == 0) ans-=ways;
            else ans += ways;
        }

        cout << ans << endl;
    }
    
    
    
    return 0;
}