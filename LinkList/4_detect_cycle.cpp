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


void insertAtTail(node* &head,int data){
    node* n = new node(data);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    
}

void display(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
    
}

void makeCycle(node* &head,int pos){
    node* temp = head;
    node* startNode;

    int count = 1;

    while (temp->next != NULL)
    {
        if(count == pos){
            startNode = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startNode;
    

}


bool detectCycle(node* head){
    unordered_set<node*> s;
    if(head == NULL || head->next == NULL){
        return true;
    }

    node *temp = head;

    while (temp != NULL)
    {
        if(s.find(temp) != s.end())
            return true;
        s.insert(temp);
        temp = temp->next;
    }

    return false;
    
}

bool detectCycle2(node* &head){
    
    if(head == NULL || head->next == NULL){
        return true;
    }

    node* slow = head;
    node* fast = head;

    while (fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
    
}

void removeCycle(node* &head){


    node* slow = head;
    node* fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
    

    
}



int main(){

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    makeCycle(head,3);

    cout << detectCycle2(head) << endl;

    removeCycle(head);
    cout << detectCycle2(head) << endl;
    display(head);


    
    
    
    return 0;
}