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

int peakIndexInMountainArray(vector<int>& arr) {

    map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]] = i;
    }

    auto it = --mp.end();
    return (*it).second;

}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int,int> mp;
    for(int i=0;i<nums1.size();i++){
        if(mp.find(nums1[i]) == mp.end())
            mp[nums1[i]] ++;
    }
    for(int i=0;i<nums2.size();i++){
        if(mp.find(nums2[i]) != mp.end())
            mp[nums2[i]] --;
    }

    vector<int> v;
    for(auto &x:mp){
        if(x.second<=0){
            v.push_back(x.first);
        }
    }

    return v;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;
    int l = 0;
    int r = 0;
    while (l < nums1.size() and r < nums2.size())
    {
        if(nums1[l] < nums2[r]){
            v.push_back(nums1[l]);
            l++;
        }else{
            v.push_back(nums2[r]);
            r++;
        }
    }
    
    while (l<nums1.size())
    {
        v.push_back(nums1[l]);
        l++;
    }
    while (r<nums2.size())
    {
        v.push_back(nums2[r]);
        r++;
    }


    if(v.size()%2 == 0){
        return (v[v.size()/2] + v[v.size()/2 - 1] )/2.0;
    }else{
        return double(v[v.size()/2]);
    }
    
}

int main(){
    
    // vi arr = {3,4,5,1};
    // cout <<  peakIndexInMountainArray(arr) << endl;

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout << findMedianSortedArrays(nums1,nums2) << endl;

    // each(x,intersection(nums1,nums2)){
    //     cout << x << " ";
    // }


    
    return 0;
}