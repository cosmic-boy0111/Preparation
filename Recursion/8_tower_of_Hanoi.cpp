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


void solve(int n,int s,int d,int h){

    if(n==1){
        cout << "moving " << n << " from " << s <<" to " << d << endl;
        return;
    }
    solve(n-1,s,h,d);

    cout << "moving " << n << " from " << s <<" to " << d << endl;

    solve(n-1,h,d,s);

    return;

}


#include <bits/stdc++.h>
using namespace std;
 
// To return char for a value. For example '2'
// is returned for 2. 'A' is returned for 10. 'B'
// for 11
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
  
// Utility function to reverse a string
void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
  
// Function to convert a given decimal number
// to a base 'base' and
char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;  // Initialize index of result
  
    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
  
    // Reverse the result
    strev(res);
  
    return res;
}
 
// Driver Code
int main()
{
    int inputNum = 282, base = 16;
    char res[100];
    cout << fromDeci(res, base, inputNum);
 
    return 0;
}


// int main(){


//     int n;
//     cin >> n;
//     int s = 1;
//     int h = 2;
//     int d = 3;


//     solve(n,s,d,h);

    
    
    
//     return 0;
// }