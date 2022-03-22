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

int counts(string s){
    vector<int> cnt(26,0);
    int mn = INT_MAX;
    for(int i=0;i<s.size();i++){
        cnt[s[i]-'a'] ++;
        mn = min(mn,s[i]-'a');
    }

    return cnt[mn];

}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    int n = queries.size();
    int m = words.size();

    vector<int> ans;
    vector<int> query(n);
    vector<int> word(m);

    for(int i=0;i<n;i++){
        query[i] = counts(queries[i]);
    }
    for(int i=0;i<m;i++){
        word[i] = counts(words[i]);
    }

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<m;j++){
            if(query[i] < word[j])
                cnt++;
        }
        ans.push_back(cnt);
    }

    return ans;
}


int main(){
    


    vector<string> q = {"bbb","cc"};
    vector<string> w = {"a","aa","aaa","aaaa"};

    vector<int> ans = numSmallerByFrequency(q,w);
    for(auto x:ans){
        cout << x << " ";
    }

    
    
    
    return 0;
}