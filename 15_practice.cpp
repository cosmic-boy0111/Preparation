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
//     // long long T;
//     // cin >> T;
//     // while(T--){
//     //     string s;
//     //     cin >> s;
//     //     int arr[26];
//     //     inc(i,0,26){
//     //         arr[i] = 0;
//     //     }
//     //     for(int i=0;i<s.size();i++){
//     //         arr[s[i]-'a'] ++;
//     //     }
//     //     for(int i=0;i<26;i++){
//     //         if(arr[i]==1){
//     //             arr[i] = 0;
//     //         }
//     //     }
//     //     bool check = false;
//     //     for(int i=0;i<26;i++){
//     //         if(arr[i]!=0) check=true;
//     //     }

//     //     check?cout<<"Yes"<<endl:cout<<"No"<<endl;

//     // }
    
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
    
// const int N = 1e6+10;
// int ar[N]   ;
    
// int main(){
    
    
//     int n , k;
//     cin >> n >> k;
//     // map<int,int> mp;
//     unordered_map<int,int> mp;

//     for(int i=1;i<=n;i++){
//         cin>> ar[i];
//     }

//     for(int i=1;i<=n;i++){
//         mp[ar[i]] = i;
//     }

//     bool flag = false;
    
//     for(int i=0;i<=n;i++){
//         if(mp[k-ar[i]] && i!=mp[k-ar[i]]) { 
//             // cout << ar[i] <<" "<<k-ar[i]<< endl;
//             flag = true;
//             break;
//         }else{
//             mp[k-ar[i]]=0;
//         }
//     }

//     if(flag) cout<< "YES" <<endl;
//     else cout<< "NO" << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
    
//     int n,k;
//     cin >> n >> k;
//     int arr[n];
//     int sum = 0;
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//         if(i<k){
//             sum+=arr[i];
//         }
//     }


//     int ans = INT_MIN;
//     ans = max(ans,sum);

//     for(int i=k;i<n;i++){
//         sum = sum + arr[i] - arr[i-k];
//         ans = max(ans,sum);
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
//     long long T;
//     cin >> T;
//     while(T--){
//         int N,A;
//         cin >> N >> A;
//         int C[N+1],D[N+1],hsh[N+1];
//         hsh[0] = 0;
//         inc(i,1,N+1){
//             cin >> C[i] >> D[i];
//             hsh[i] = hsh[i-1]+C[i];
//         }

//         int ans=0;
//        inc(l,1,N+1){
//            int x=D[l];
//            int y=D[l];
//            inc(r,l,N+1){
//               x=max(x,D[r]);
//               y=min(y,D[r]);
//               ans=max(ans,(r-l+1)*A-(hsh[r]-hsh[l-1])-((x-y)*(x-y)));
//            }
//        }cout<<ans<<endl;
//     }
    
    
    
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     long long T;
//     cin >> T;
//     while(T--){
//         string s;
//         string t;
//         cin >> s >> t;
//         int s_arr[26];
//         // int t_arr[26];

//         for(int i=0;i<26;i++){
//             s_arr[i] = 0;
//         }

//         for(int i=0;i<s.size();i++){
//             s_arr[s[i]-'a'] +=1;
//         }
//         for(int i=0;i<t.size();i++){
//             s_arr[t[i]-'a'] -=1;
//         }

//         int ans  = 0;

//         for(int i=0;i<26;i++){
//             ans+=abs(s_arr[i]);
//         }

//         cout << ans << endl;

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
    
//     string s,t;
//     cin >> s >> t;
    
//     int arr[26];
//     for(int i=0;i<26;i++){
//         arr[i] = 0;
//     }

//     for(int i=0;i<s.size();i++){
//         arr[s[i]-'a']++;
//     }

//     for(int i=0;i<t.size();i++){
//         arr[t[i]-'a']--;
//     }

//     for(int i=0;i<26;i++){
//         if(arr[i]!=0) cout << false << endl;
//     }

//     cout << true << endl;

    
    
    
//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     long long T;
//     cin >> T;
//     while(T--){
//         string s;
//         cin >> s;
//         unordered_map<char,int> mp;
//         mp['r'] = 0;
//         mp['u'] = 0;
//         mp['b'] = 0;
//         mp['y'] = 0;

//         for(int i=0;i<s.size();i++){
//             mp[s[i]] += 1;
//         }

//         cout << min(min(mp['r'],mp['u']),min(mp['b'],mp['y'])) << endl;
//     }
    
    
    
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;


// int main(){

//     string pattern="aaaa",s="dog cat cat dog";

//     vector<string> v;
//     string temp = "";
//     for(int i=0;i<=s.size();i++){
//         if(s[i]==' ' || i==s.size()){
//             v.push_back(temp);
//             // cout << temp << " ";
//             temp = "";
//             continue;
//         }
//         temp.push_back(s[i]);
//     } 

//     if(pattern.size()!=v.size()){
//         cout << false << endl;
//     }
    
//     map<char,string> mp1;
//     map<string,char> mp2;

//     for(int i=0;i<pattern.size();i++){
//         if(mp1.find(pattern[i])==mp1.end() and mp2.find(v[i])==mp2.end()){
//             mp1[pattern[i]] = v[i];
//             mp2[v[i]] = pattern[i];
//         }else if(mp1[pattern[i]]==v[i] and mp2[v[i]]==pattern[i]){

//         }else{
//             cout << false << endl;
//             break;
//         }
//     }

//     cout << true << endl;
    
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
    
//     vector<vector<char>> board{{'8','3','.','.','7','.','.','.','.'}
// ,{'6','.','.','1','9','5','.','.','.'}
// ,{'.','9','8','.','.','.','.','6','.'}
// ,{'8','.','.','.','6','.','.','.','3'}
// ,{'4','.','.','8','.','3','.','.','1'}
// ,{'7','.','.','.','2','.','.','.','6'}
// ,{'.','6','.','.','.','.','2','8','.'}
// ,{'.','.','.','4','1','9','.','.','5'}
// ,{'.','.','.','.','8','.','.','7','9'}};


//     map<pair<int,char>,int> rows;
//     map<pair<int,char>,int> cols;
//     map<pair<pair<int,int>,char>,int> sub_box;

//     for(int i=0;i<board.size();i++){
//         for(int j=0;j<board[0].size();j++){
//             if(board[i][j]!='.'){
//                 if(rows[{i,board[i][j]}] == 1 || cols[{j,board[i][j]}] == 1 || sub_box[{{i/3,j/3},board[i][j]}] == 1){
//                     cout << false << endl;
//                     return 0;
//                 }else{
//                     rows[{i,board[i][j]}] = 1;
//                     cols[{j,board[i][j]}] = 1;
//                     sub_box[{{i/3,j/3},board[i][j]}] = 1;
//                 }
//             }
//         }
//     }

//     cout << true << endl;


    
    
    
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;



// int main(){
    

//     vector<int> v = {0,0,1,1,1};

//     map<int,int> mp;
//     for(int i=0;i<v.size();i++){
//         mp[v[i]] ++ ;
//     }

//     int ans = 0;

//     for(auto &x:mp){
//         if(x.first == 0){
//             ans += x.second;
//         }else if(x.first + 1 < x.second){
//             int p = x.second % (x.first + 1);
//             int q = x.second / (x.first + 1);
//             ans += q*(x.first + 1);
//             if(p!=0){
//                 ans += x.first + 1;
//             }
//         }else{
//             ans += x.first + 1;
//         }
//     }

//     cout << ans << endl;
    
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
    
//     int n;
//     cin >> n;
//     set<long long> s;
//     long long sum = 0;
//     int ans = 0;
//     s.insert(sum);
//     while (n--)
//     {
//         long long x;
//         cin >> x;
//         sum += x;
//         if(s.find(sum) != s.end()){
//             ans ++;
//             s.clear();
//             s.insert(0);
//             sum = x;
//         }
//         s.insert(sum);
//     }

//     cout << ans << endl;
    
//     return 0;
// }