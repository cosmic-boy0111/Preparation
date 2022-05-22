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
// // const int N = 1e6, MOD = 1e9+7;

// const int N = 1e7+10;
// vector<bool> isPrime(N,1);


// int main(){
    

//     isPrime[0] = isPrime[1] = false;
//     inc(i,2,N){
//         if(isPrime[i] == true){
//             for(int j=2*i;j<N;j+=i){
//                 isPrime[j] = false;
//             }
//         }
//     }

//     // n(log(log(n)))

//     // for(int i=1;i<=100;i++){
//     //     cout << isPrime[i] << endl;
//     // }

//     int q;
//     cin >> q;
//     while (q--){
//         int num;
//         cin >> num;
//         if(isPrime[num]){
//             cout << "prime" << endl;
//         }else{
//             cout << "not Prime" << endl;
//         }
//     }
    
    
    
//     return 0;
// }




// const int N = 1e7+10;
// vector<bool> isPrime(N,1);


//     isPrime[0] = isPrime[1] = false;
//     for(int i=2;i<N;i++){
//         if(isPrime[i] == true){
//             for(int j=2*i;j<N;j+=i){
//                 isPrime[j] = false;
//             }
//         }
//     }


#include <bits/stdc++.h>
using namespace std;



const int N = 1e7+10;
vector<bool> isPrime(N,1);

vector<int> cal(int num){
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<=num;i++){
        if(isPrime[i] == true){
            for(int j=2*i;j<=num;j+=i){
                isPrime[j] = false;
            }
        }
    }
    vector<int> ans;
    for(int i=2;i<=num;i++){
        if(isPrime[i])
            ans.push_back(i);
            
    }

    return ans;
    
}


int32_t main(){


    for(auto& x:cal(11)){
        cout << x << " ";
    }
    
    
    return 0;
}
