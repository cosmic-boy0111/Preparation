#include <bits/stdc++.h>
using namespace std;

unordered_map<int,bool> mp;
bool isPalindrome(int n) {
    if(mp.find(n) != mp.end()) return mp[n];
    string s = to_string(n);
    int i = 0;
    int j = s.length() - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            mp[n] = false;
            return false;
        }
        i++;
        j--;
    }
    mp[n] = true;
    return true;
    
}

string solve(int N) {
    int current = 7;

    while (true) {
        if (to_string(current).size() == N && current % 7 == 0 && isPalindrome(current)) {
            return to_string(current);
        }
        current += 7;
    }
    return "";
}

int main(){
    
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;

        cout << solve(N) << endl;
    }

}