// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vs vector<string>
// #define vb vector<bool>
// #define pi pair<int,int>
// #define mi map<int,int>
// #define umi unordered_map<int,int>
// #define qi queue<int>
// #define vpi vector<pi>
// #define vvi vector<vi>
// #define ff first
// #define ss second 
// #define pb push_back
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;



// int main(){
//     long long T;
//     cin >> T;
//     while(T--){
//         int n,k;
//         cin >> n >> k;
//         multiset<long long> bags;
//         for(int i=0;i<n;i++){
//             long long x;
//             cin >> x;
//             bags.insert(x);
//         }

//         long long total_candies = 0;
//         for(int i=0;i<k;i++){
//             auto last_it = (--bags.end());
//             long long candy_cnt = *last_it;
//             total_candies += candy_cnt;
//             bags.erase(last_it);
//             bags.insert(candy_cnt/2);
//         }

//         cout << total_candies << endl;
//     }
    
    
    
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vs vector<string>
// #define vb vector<bool>
// #define pi pair<int,int>
// #define mi map<int,int>
// #define umi unordered_map<int,int>
// #define qi queue<int>
// #define vpi vector<pi>
// #define vvi vector<vi>
// #define ff first
// #define ss second 
// #define pb push_back
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;



// int main(){
//     long long T;
//     cin >> T;

//     set<int> s;
//     while(T--){
//         int q,x;
//         cin >> q >> x;
//         if(q==1){
//             s.insert(x);
//         }else if(q==2){
//             s.erase(x);
//         }else{
//             if(s.find(x) != s.end()){
//                 cout << "Yes" << endl;
//             }else{
//                 cout << "No" << endl;
//             }
//         }
//     }
    
    
    
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vs vector<string>
// #define vb vector<bool>
// #define pi pair<int,int>
// #define mi map<int,int>
// #define umi unordered_map<int,int>
// #define qi queue<int>
// #define vpi vector<pi>
// #define vvi vector<vi>
// #define ff first
// #define ss second 
// #define pb push_back
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;



// int main(){
//     long long T;
//     cin >> T;
//     while(T--){
//         int n,m;
//         cin >> n >> m;
//         unordered_set<long long> s;
//         long long x;
//         for(int i=0;i<n+m;i++){ 
//             cin >> x;
//             if(i<n){
//                 s.insert(x);
//             }else{
//                 if(s.find(x) == s.end()){
//                     cout << "NO" << endl;
//                     s.insert(x);
//                 }else{
//                     cout << "YES" << endl;
//                 }
//             }
//         }

//     }
    
    
    
//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vs vector<string>
// #define vb vector<bool>
// #define pi pair<int,int>
// #define mi map<int,int>
// #define umi unordered_map<int,int>
// #define qi queue<int>
// #define vpi vector<pi>
// #define vvi vector<vi>
// #define ff first
// #define ss second 
// #define pb push_back
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;



// int main(){
//     long long T;
//     cin >> T;
//     while(T--){
//         int n;
//         cin >> n;
//         set<string> list;
//         for(int i=0;i<n;i++){
//             string s;
//             cin >> s;
//             list.insert(s);
//         }

//         each(x,list){
//             cout << x << endl;
//         }

//     }
    
    
    
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vs vector<string>
// #define vb vector<bool>
// #define pi pair<int,int>
// #define mi map<int,int>
// #define umi unordered_map<int,int>
// #define qi queue<int>
// #define vpi vector<pi>
// #define vvi vector<vi>
// #define ff first
// #define ss second 
// #define pb push_back
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;



// int main(){
//     long long T;
//     cin >> T;

//     map<int,multiset<string>> mp;

//     while(T--){
//         string s;
//         int mark;
//         cin >> s >> mark;
//         mp[-mark].insert(s);
//     }

//     each(x,mp){
//         each(y,x.second){
//             cout << y << " " << -x.first << endl;
//         }
//     }
    
    
    
//     return 0;
// }