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

// void solve(){
//     int m,n;
//     cin >> m >> n;
    
//     unordered_map<int,int> mp;
//     for(int i=0;i<m;i++){
//         int x,y;
//         cin >> x >> y;
//         mp[y] = x;
//     }

//     for(int i=0;i<n;i++){
//         int x;
//         cin >> x;
//         if(mp.find(x) == mp.end()){
//             cout << "NO" << endl;
//             return;
//         }
//     }

//     cout << "YES" << endl;
 
// }

// int main(){
    
       
//     solve();

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

// const int N = 1e3+10;
// int pre[N][N];

// int main(){
    
//     int n,m;
//     cin >> n >> m;

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             int x ;
//             cin >> x;
//             x = x%2;
//             pre[i][j] = x + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
//         }
//     }

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int x1,y1,x2,y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         cout << pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1] << endl;
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

// unordered_map<int,int> mp;
// unordered_map<int,int> cnt;

// void solve(int i,int price){
//     if(price == mp[i]){
//         cout << 0 << endl;
//         return;
//     }

//     long long ans = 0;

//     // for(auto &x:mp){
//     //     if(x.first != i and (x.second == price-mp[i] || x.second == price)){
//     //         ans +=1;
//     //     }
//     // }

//     int val1 = price - mp[i];
//     int val2 = price;

//     ans = cnt[val1] + cnt[val2];
//     if(mp[i] == val1){
//         ans -= 1;
//     }

//     if(mp[i] == val2){
//         ans -= 1;
//     }


//     if(ans){
//         cout << ans << endl;
//     }else{
//         cout << -1 << endl;
//     }

// }

// int main(){
    
//     long long n;
//     cin >> n;
    
//     for(int i=1;i<=n;i++){
//         int x;
//         cin >> x;
//         mp[i] = x;
//         cnt[x] +=1;
//     }

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int i,price;
//         cin >> i >> price;
//         solve(i,price);
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
    
    
//     int n,k;
//     cin >> n >> k;
    
//     unordered_map<int,int> mp;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int x;
//         cin >> x;
//         mp[x] ++;
//     }

//     for(auto &x:mp){
//         if(x.second>k) ans++;
//     }

//     cout << ans << endl;


    
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
    

//     string s;
//     cin >> s;

//     unordered_map<char,int> mp;
//     for(int i=0;i<s.size();i++){
//         mp[s[i]] ++;
//     }

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int t;
//         cin >> t;
//         set<char> s;
//         int ans = 0;
//         int odd_cnt = 0;

//         for(int i=0;i<t;i++){
//             char c;
//             cin >> c;
//             s.insert(c);
//         }

//         for(auto &c:s){

//             if(mp[c]%2==0){
//                 ans += mp[c];
//             }else{
//                 ans += mp[c];
//                 odd_cnt++;
//             }

//         }

//         if(odd_cnt){
//             cout << ans - (odd_cnt-1) << endl;
//         }else{
//             cout << ans << endl;
//         }
//     }
    
    
    
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int n;
    cin >> n;
    int arr[n+1];
    arr[0] = 0;
    int pre[n+2];
    pre[0] = 0;
    pre[n+1] = 0;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
        pre[i] = arr[i];
    }

    
    int q;
    cin >> q;
    while (q--)
    {
        int X,l,r;
        cin >> X >> l >> r;
        l = l+1;
        r = r+1;

        pre[l] += X;
        pre[r+1] -= X;

    }

    for(int i=1;i<=n;i++){
        pre[i] += pre[i-1] - arr[i-1];
    }

    int ans = INT_MIN;
    for(int i=1;i<=n;i++){
        ans = max(ans,pre[i]);
    }
    
    cout << ans << endl;
    
    
    return 0;
}