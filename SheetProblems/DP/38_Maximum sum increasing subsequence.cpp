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

int solve(int i, int arr[], int n, int pre,vector<vector<int>>& dp){

    if (i >= n)
        return 0;

    if(dp[i][pre+1] != -1) return dp[i][pre+1];
    int include = 0;
    if (pre == -1 || arr[i] > arr[pre])
    {
        include = arr[i] + solve(i + 1, arr, n, i,dp);
    }

    int exclude = solve(i + 1, arr, n, pre,dp);
    return  dp[i][pre+1] = max(include,exclude);
}

int maxSumIS(int arr[], int n)
{
    vector<vector<int>>  dp(n,vector<int>(n+1,-1));
    return solve(0, arr, n, -1, dp);
}

int32_t main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxSumIS(arr, n);

    return 0;
}