# Preparation
 
# font
"Source Code Pro Regular",

# cpp snippets 
{
	// Place your snippets for csharp here. Each snippet is defined under a snippet name and has a prefix, body and 
	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	// Example:
	"cpp 01 snippets": {
		"prefix": "cpp 01 snippets",
		"body": [
			"#include <bits/stdc++.h>",	
			"using namespace std;",
			"",
			"#define vi vector<int>",
			"#define vs vector<string>",
			"#define vb vector<bool>",
			"#define pi pair<int,int>",
			"#define mi map<int,int>",
			"#define umi unordered_map<int,int>",
			"#define qi queue<int>",
			"#define vpi vector<pi>",
			"#define vvi vector<vi>",
			"#define ff first",
			"#define ss second ",
			"#define inc(i,a,b) for(int i=a;i<b;i++)",
			"#define dec(i,a,b) for(int i=a;i>=b;i--)",
			"#define each(x,target) for(auto &x:target)",
			"const int N = 1e6, MOD = 1e9+7;",
			"",
			"void printBinary(int n){",
			"    for(int i=10;i>=0;i--){",
			"        if((n>>i) & 1) cout << 1;",
			"        else cout << 0;",
			"    }cout << endl;",
			"}",
			"",
			"class node{",
			"    public:",
			"        int val;",
			"        node* left;",
			"        node* right;",
			"",
			"        node(int data = 0){",
			"            val = data;",
			"            left = NULL;",
			"            right = NULL;",
			"        }",
			"};",
			"",
			"#define minHeapInt priority_queue<int,vector<int>,greater<int>>",
			"#define maxHeapInt priority_queue<int,vector<int>>",
			"#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>",
			"#define maxHeapPair priority_queue<pi,vector<pi>>",
			"",
			"",
			"vector<int> adj[N];",
			"bool vis[N];",
			"",
			"",
			"int32_t main(){",
			"",
			"    $0",
			"",
			"}",
		],
		"description": "Log output to console"
	},
	"cpp 02 array int snippets": {
		"prefix": "cpp 02 int array snippets",
		"body": [
			"int n;",
			"cin >> n;",
			"int arr[n];",
			"for(int i = 0; i < n; i++){",
			"    cin >> arr[i];",
			"}",
			"$0"
		],
		"description": "Log output to console"
	},
	"cpp 03 array char snippets": {
		"prefix": "cpp 03 char array snippets",
		"body": [
			"int n;",
			"cin >> n;",
			"char arr[n];",
			"for(int i = 0; i < n; i++){",
			"    cin >> arr[i];",
			"}",
			"$0"
		],
		"description": "Log output to console"
	}
}