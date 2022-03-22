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
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};
class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> map; // key, {value, timestamp}
    
    string searchVal(vector<pair<string, int>> &vec, const int &timestamp) {
        int low = 0;
        int high = vec.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (vec[mid].second > timestamp) {
                high = mid - 1;
            } else if (vec[mid].second < timestamp) {
                low = mid + 1;
            } else {
                return vec[mid].first;
            }
        }
        
        return high >= 0 ? vec[high].first : "";
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }
        return searchVal(map[key], timestamp);
    }
};

int main(){
    
    TimeMap timeMap ;
    cout << timeMap.get("foo", 1) << endl;
    timeMap.set("foo", "bar", 1); 
    cout << timeMap.get("foo", 1) << endl;
    cout << timeMap.get("foo", 3) << endl;  
    timeMap.set("foo", "bar2", 4); 
    cout << timeMap.get("foo", 4) << endl;
    timeMap.set("foo1", "bar3", 5); 
    cout << timeMap.get("foo1", 5) << endl;

    
    return 0;
}