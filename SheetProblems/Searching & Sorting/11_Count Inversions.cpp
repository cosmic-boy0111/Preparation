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

class node
{
public:
    int val;
    node *left;
    node *right;

    node(int data = 0)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Node
{
public:
    int val;
    Node *next;

    Node(int data = 0)
    {
        val = data;
        next = NULL;
    }
};

void insertAtTail(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    Node *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new Node(val);
}

void display(Node *root)
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

long long Count = 0; 
void merge(long long int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long int left_arr[n1], right_arr[n2];

    for (int i = 0; i < n1; i++)
    {
        left_arr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        right_arr[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k++] = (long long)left_arr[i++];
        }
        else if (left_arr[i] > right_arr[j])
        {
            arr[k++] = (long long)right_arr[j++];
            Count = Count + (long long)(n1 - i);
        }
    }
    while (i < n1)
    {
        arr[k++] = (long long)left_arr[i++];
    }

    while (j < n2)
    {
        arr[k++] = (long long)right_arr[j++];
    }
}

void merge_sort(long long int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    long long int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
long long int inversionCount(long long arr[], long long N)
{
    merge_sort(arr, 0, N - 1);
    return Count;
}

int32_t main()
{

    long long N;
    cin >> N;
    long long arr[N];
    for (long long i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << inversionCount(arr, N);

    return 0;
}