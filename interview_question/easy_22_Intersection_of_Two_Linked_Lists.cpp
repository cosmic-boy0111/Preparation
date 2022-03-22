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
        node* next;
        node(int data = 0){
            val = data;
            next = NULL;
        }
};


int length(node* head){
    int l = 0;
    node* temp = head;
    while (temp){
        temp = temp->next;
        l++;
    }

    return l;
    
}

node* getIntersectionNode(node *headA, node *headB){

    int l1 = length(headA);
    int l2 = length(headB);

    int d = 0;
    node* ptr1;
    node* ptr2;

    if(l1 > l2){
        d = l1-l2;
        ptr1 = headA;
        ptr2 = headB;
    }else{
        d = l2-l1;
        ptr1 = headA;
        ptr2 = headB;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if(ptr1 == NULL)
            return NULL;
        d--;
    }

    while (ptr1 != NULL and ptr2 != NULL)
    {
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }

    return NULL;

}

int main(){
    


    
    
    return 0;
}