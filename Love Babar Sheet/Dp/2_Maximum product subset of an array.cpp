#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pi pair<int, int>
#define mi map<int, int>
#define umi unordered_map<int, int>
#define qi queue<int>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff first
#define ss second
#define inc(i, a, b) for (int i = a; i < b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)
#define each(x, target) for (auto &x : target)
const int N = 1e6, MOD = 1e9 + 7;

void printBinary(int n)
{
    for (int i = 10; i >= 0; i--)
    {
        if ((n >> i) & 1)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
}

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data = 0)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data = 0)
    {
        val = data;
        next = NULL;
    }
};

void insertAtTail(ListNode *&root, int val)
{
    if (root == NULL)
    {
        root = new ListNode(val);
        return;
    }
    ListNode *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

void display(ListNode *root)
{
    while (root != NULL)
    {
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;
}

#define minHeapInt priority_queue<int, vector<int>, greater<int>>
#define maxHeapInt priority_queue<int, vector<int>>
#define minHeapPair priority_queue<pi, vector<pi>, greater<pi>>
#define maxHeapPair priority_queue<pi, vector<pi>>
vector<int> adj[N];
vector<bool> visited(N, false);

vector<pair<int, int>> pos = {
    {0, -1}, {-1, 0}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

const int mod = 1e9 + 7;

long long solve(vector<int> &a, int n, long long mult)
{
    if (n == 0)
        return 1;
    return max(solve(a, n - 1, (mult * a[n - 1]) % mod), solve(a, n - 1, mult)) % mod;
}

long long int findMaxProduct(vector<int> &a, int n)
{
    return solve(a, n, 1);
}

float roundoff(float value, unsigned char prec)
{
  float pow_10 = pow(10.0f, (float)prec);
  return round(value * pow_10) / pow_10;
}

long double intersectionArea(int X1, int Y1,
                               int R1, int X2,
                               int Y2, int R2)
{
    long double Pi = 3.14;
    long double d, alpha, beta, a1, a2;
    double ans;
    d = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));

    if (d > R1 + R2)
        ans = 0;
    else if (d <= abs(R2 - R1) && R1 >= R2)
        ans = Pi * R2 * R2;

    else if (d <= abs(R2 - R1) && R2 >= R1)
        ans = Pi * R1 * R1;

    else
    {
        alpha = acos((R1 * R1 + d * d - R2 * R2) / (2 * R1 * d)) * 2;
        beta = acos((R2 * R2 + d * d - R1 * R1) / (2 * R2 * d)) * 2;
        a1 = 0.5 * beta * R2 * R2 - 0.5 * R2 * R2 * sin(beta);
        a2 = 0.5 * alpha * R1 * R1 - 0.5 * R1 * R1 * sin(alpha);
        ans = a1 + a2;
    }



    return  ans;
}

int32_t main()
{

    cout.precision(7);
    cout <<  intersectionArea(0, 0, 2, 3, 0, 2);

    return 0;
}