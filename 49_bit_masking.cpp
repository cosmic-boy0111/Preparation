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
    for(int i=30;i>=0;i--){
        cout << ((n>>i)&1);
    }cout << endl;
}


int main(){
    // long long T;
    // cin >> T;
    // vector<int> days[T];
    // while(T--){

    //     int num_workers;
    //     cin >> num_workers;
    //     for(int i=0;i<num_workers;i++){

    //         int day;
    //         cin >> day;
    //         days[i].push_back(day);

    //     }
    // }

    // for(int i=0;i<T;i++){
    //     for(int j=i+1;j<T;j++){
    //         // intersection of days[i] and days[j];
    //     }
    // }

    // (N^2 + 30)


    long long n;
    cin >> n;
    vector<int> masks(n);
    for(int j=0;j<n;j++){

        int num_workers;
        cin >> num_workers;
        int mask = 0;
        for(int i=0;i<num_workers;i++){

            int day;
            cin >> day;
            mask = (mask | (1<<day));

        }
        masks[j] = mask;
    }

    int max_days = 0;
    int person1 = -1;
    int person2 = -1;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int intersection = (masks[i] & masks[j]);
            int cnt = __builtin_popcount(intersection);
            if(cnt > max_days){
                person1 = i;
                person2 = j;
                max_days = cnt;
            }
        }
    }

    cout << person1 << " " << person2 << " ";

    cout << max_days << endl;
    

    return 0;
}