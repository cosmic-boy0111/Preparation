#include <bits/stdc++.h>
using namespace std;

vector<int> largestLand(vector<vector<int>> houses){
    int num = houses.size();
    int house_number[num];
    int position[num];
    for(int i=0;i<num;i++){
        house_number[i] = houses[i][0];
        position[i] = houses[i][1];
    }
    int copy_position[num];
    for (int i = 0; i < num; i++)
    {
        copy_position[i] = position[i]; // Copying the position to another array so that the orginial array won’t be affected
    }
    vector<int> ans;
    sort(copy_position, copy_position + num); // Sorting the copied array
    int temp;
    int x1, x2;
    int position1, position2;
    int maxi = 0;
    for (int i = 0; i < num - 1; i++)
    {
        int temp = abs(copy_position[i + 1] - copy_position[i]); // Difference between two adjacent array elements is calculated
        if (temp > maxi)
        {
            maxi = temp;           // The highest difference is noted
            x1 = copy_position[i]; // The two elements are noted
            x2 = copy_position[i + 1];
        }
    }
    for (int i = 0; i < num; i++) // The elements position are found in the main position array
    {
        if (x1 == position[i])
        {
            position1 = i;
        }
        else if (x2 == position[i])
        {
            position2 = i;
        }
    }
    if (house_number[position1] > house_number[position2]) // The house number is displayed which is matched by the position obtained
    {
        ans.push_back(house_number[position2]);
        ans.push_back(house_number[position1]);
    }
    else
    {
        ans.push_back(house_number[position1]);
        ans.push_back(house_number[position2]);
    }

    return ans;
}

int main()
{
    int n ;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(2));
    for(auto &x : v)
        cin >> x[0] >> x[1];
    
    for(auto &x : largestLand(v))
        cout << x << " ";
}