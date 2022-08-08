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

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{
    if (node == NULL)
        return;
    queue<pair<Node *, Node *>> q;
    Node *root = new Node(node->val);
    q.push({root, node});
    unordered_map<int,Node*> mp;
    mp[root->val] = root;
    while (!q.empty())
    {
        pair<Node *, Node *> pr = q.front();
        q.pop();
        Node *first = pr.first;
        Node *second = pr.second;
        for(auto &x :  second->neighbors){

            if(mp.find(x->val) != mp.end()){
                first->neighbors.push_back(mp[x->val]);
                continue;
            }

            Node* n = new Node(x->val);
            mp[x->val] = n;
            first->neighbors.push_back(n);
            q.push({n,x});
        }
    }

    return root;
}

int32_t main()
{

    Node *root = new Node(1);
    Node *root2 = new Node(2);
    Node *root3 = new Node(4);
    root->neighbors = {root2, root3};

    return 0;
}