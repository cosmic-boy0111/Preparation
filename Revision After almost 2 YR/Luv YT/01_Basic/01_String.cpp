#include <bits/stdc++.h>

using namespace std;

// main topic
// 1. getline
// 2. reverse string

int main(){

    // string str = "Hello";
    // cout << str << endl;

    // string str2;
    // cin >> str2;
    // cout << str2 << endl;

    // string result = str + str2;
    // cout << result << endl;

    // cin.ignore();
    // string str3;
    // getline(cin, str3);
    // cout << str3 << endl;

    // if(str == str2){
    //     cout << "Equal" << endl;
    // }else{
    //     cout << "Not equal" << endl;
    // }

    // str[0] = 'a';

    // cout << str[0] << endl;
    // cout << str.size() << endl;

    // for(int i=0; i<str.size(); i++){
    //     cout << str[i];
    // }
    
    string str;
    cin >> str;
    string str_rev;
    for(int i = str.size()-1; i>=0; i--){
        str_rev.push_back(str[i]);
    }

    cout << str_rev << endl;
    if(str == str_rev){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}