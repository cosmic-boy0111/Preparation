#include <iostream>
using namespace std;


int main(){

    int n;
    cin >> n;
    while (true){
        if(n < 100 || n>200 ){

            cout << "INVALID INPUT" << endl;
            break;
        }

        if(n % 2 == 0){

            cout << n/4 << endl;
            cout << n/4 << endl;
            cout << n/4 << endl;
            cout << n/4 << endl;
            
        }else {
            int sum = n/4 + n/4 + n/4;
            cout << n/4 << endl;
            cout << n/4 << endl;
            cout << n/4 << endl;
            cout << n - sum << endl;
        }




        break;
    }
    

    return 0;
}