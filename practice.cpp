// #include <bits/stdc++.h>
// using namespace std;

// int findNumber(int n){
//     int ans = INT_MIN;
//     int index = 0;
//     for(int i=1;i<n;i++){
//         if((i*i)%n >= ans){
//             index = i;
//             ans = max(ans,(i*i)%n);
//         }
//     }

//     return index;

// }

// int main(){
    
//     int n;
//     cin >> n;

//     cout << findNumber(n);
    
    
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
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;


// void convertArray(int start,int end,int A[],int &cnt){

//     if(start==end){
//         return;
//     }

//     if(A[start]>=A[start+1]){
//         cnt++;
//         convertArray(++start,end,A,cnt);
//     }

//     if(A[end]<=A[end-1]){
//         cnt++;
//         convertArray(start,--end,A,cnt);
//     }

//     convertArray(++start,--end,A,cnt);


// }

// int ascendingorder(int N,int A[]){
//     int result = -404;

//     int start = 0;
//     int end = N-1;
//     int cnt = 0;
//     convertArray(start,end,A,cnt);
//     // cout << cnt << endl;
//     result = cnt;
//     return result;
// }

// int main(){
    
//     int n;
//     cin >> n;
//     int A[n];
//     for(int i=0;i<n;i++){
//         cin >> A[i];
//     }

//     cout << ascendingorder(n,A);

    
    
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
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;



// int main(){
    
//     int arr[] = {0,0, 1, 0, 1, 1, 1, 0, 1, 1 };
//     int n = 10;


//     int pervious_zero = -1;
//     int max_cnt = 0;
//     int ans_idx = -1;
//     for(int i=0;i<n;i++){
//         if(arr[i]==0){
//             int cnt = i - pervious_zero;
//             if(cnt > max_cnt){
//                 max_cnt = cnt;
//                 ans_idx = i;
//             }
//             pervious_zero = i;
//         }
//     }

//     cout << ans_idx << endl;






    
    
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
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;

// map<int,int> mp;
// vector<vector<int>> v;
// vector<pair<int,int>> vp;
// pair<int,int> p;

// void find(vector<int> t,int start,int end,vector<int> arr){

//     if(start>=end){
//         p.second = start;
//         vp.push_back(p);
//         t.push_back(arr[start]);
//         v.push_back(t);
//         return;
//     }

//     else if(mp.find(arr[start]) != mp.end()){
//         p.second = start - 1;
//         vp.push_back(p);
//         v.push_back(t);
//         t.clear();
//         start = mp[arr[start]];
//         p.first = start;
//         mp.clear();
//         find(t,start,end,arr);
//     }else{

//         t.push_back(arr[start]);
//         mp[arr[start]] = start+1;
//         find(t,start+1,end,arr);

//     }
// }

// int main(){
    
//     vector<int> arr = { 2, 0, 2, 1, 4, 3, 1, 0 };
//     int n = 8;

//     vector<int> t;
//     p.first = 0;
//     find(t,0,n-1,arr);

//     int size = 0;

//     vector<int> ans;

//     for(auto &x:v){
//         // if(x.size() > size){
//         //     ans = x;
//         //     size = x.size();
//         // }
//         for(auto &y:x){
//             cout << y << " ";
//         }cout << endl;
//     }cout << endl;

//     for(auto x:vp){
//         cout << x.first << " " << x.second << endl;
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
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;



// int main(){
    
//     vector<int> v = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 };

//     bool check_pre;
//     bool check;

//     for(int i=0;i<v.size();i++){
//         if(i==0){
//             check_pre = true;
//             check = true;

//         }else{

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
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;



// int main(){
    
//     vector<int> v = {2, 6, 3, 4, 1, 2, 9, 5, 8};

//     vector<int> forward(v.size(),1);
//     for(int i=0;i<v.size();i++){
//         for(int j=0;j<i;j++){
//             if(v[i] > v[j])
//                 forward[i] = max(forward[i],1+forward[j]);
//         }
//     }

//     int ans  = 0;
//     for(int i=0;i<forward.size();i++){
//         ans = max(ans,forward[i]);
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
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;


// int lower_bound(vector<int> &v,int ele){
//     int lo = 0, hi = v.size()-1;
//     int mid ;
//     while (hi-lo>1)
//     {
//         mid = (hi+lo)/2;
//         if(v[mid]<=ele){
//             lo = mid;
//         }else{
//             hi = mid-1;
//         }
//     }

//     if(v[lo]<=ele){
//         return lo;
//     }else if(v[hi]<=ele){
//         return hi;
//     }


//     return -1;
    
// }

// int main(){
//     long long T;
//     cin >> T;
//     while(T--){
//         int n,x;
//         cin >> n >> x;
//         vector<int> v(n);
//         for(int i=0;i<n;i++){
//             cin >> v[i];
//         }

//         cout << lower_bound(v,x) << endl;

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
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e3+10, MOD = 1e9+7;

// // int arr[N][N];

// string gen(string s,int n){
//     vector<string> v(n);
//     int cnt = 0;
//     char dir = 'd';
//     for(int i=0;i<s.size();i++){
//         v[cnt].push_back(s[i]);
//         if(cnt == 0){
//             dir = 'd';
//         }
//         if(cnt == n-1){
//             dir = 'u';
//         }

//         if(dir == 'u'){
//             cnt -= 1;
//         }else{
//             cnt += 1;
//         }
//     }
//     string ans = "";
//     for(auto &x:v){
//         ans += x;
//     }

//     return ans;
// }

// int main(){

//     cout << gen("ABCDEFGH",2) << endl;
    
//     // int n , k; 
//     // cin >> n >> k;
//     // vector<int> v(n);
//     // for(int i=0;i<n;i++){
//     //     cin >> v[i];
//     // }

//     // for(int i=0;i<n;i++){
//     //     arr[i][i] = v[i];
//     //     for(int j=i+1;j<n;j++){
//     //         arr[i][j] = arr[i][j-1] + v[j];
//     //     }
//     // }

//     // int cnt = 0;

//     // for(int i=0;i<n;i++){
//     //     for(int j=i;j<n;j++){
//     //         if(arr[i][j] == k){
//     //             cnt++;
//     //         }
//     //     }
//     // }

//     // cout << cnt << endl;

    
    
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
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;
// void printBinary(int n){
//     for(int i=10;i>=0;i--){
//         if((n>>i) & 1) cout << 1;
//         else cout << 0;
//     }cout << endl;
// }
// class node{
//     public:
//         int val;
//         node* left;
//         node* right;

//         node(int data = 0){
//             val = data;
//             left = NULL;
//             right = NULL;
//         }
// };



// int main(){
    
//     unordered_map<int,int> mp;
//     unordered_map<int,int> pos;

//     int arr[130];

//     arr[0] = 0;
//     mp[0] = 1;
//     pos[0] = mp[0];

//     arr[1] = 0;
//     mp[0] = 2;
//     pos[1] = mp[0];

//     for(int i=2;i<130;i++){
//         int pre = i-1;
//         bool found = false;
//         int prePre = -1;
//         for(int j=i-2;j>=0;j--){
//             if(arr[j] == arr[pre]){
//                 prePre = j;
//                 found = true;
//                 break;
//             }
//         }
//         if(found){
//             arr[i] = pre - prePre;
//         }else{
//             arr[i] = 0;
//         }

//         mp[arr[i]]++;
//         pos[i] = mp[arr[i]];

//     }

//     int T;
//     cin >> T;

//     while (T--){
//         int n;
//         cin >> n;
//         cout << pos[n-1] << endl;
//     }
    

//     return 0;
// }

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

int mn(int arr[],int n){
    int ans = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] < ans){
            ans = arr[i];
        }
    }

    return ans;
}

int main(){
    long long T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i=0;i<n;i++) {
            int x;
            cin >> x;
            mn = min(mn,x);
            mx = max(mx,x);
        }

        cout << mn << " " << mx << endl;
    }
    
    
    
    return 0;
}

