/*here is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

 Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]
*/



#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mini = 0; 
        int maxi = 0;
        int tap = 0;
        while(maxi<n){
            for(int i=0; i<ranges.size(); i++){
                if(i-ranges[i] <= mini && i+ranges[i] > maxi)
                    maxi = i + ranges[i];
            }
            if(mini == maxi)return -1;
            tap++;
            mini = maxi;
        }
        return tap;

    }
};

int main(){
    int n;
    cin>>n;
    vector<int> ranges(n+1);
    for(int i=0; i<=n; i++)
        cin>>ranges[i];
    Solution solve;
    int ans = solve.minTaps(n, ranges);
    cout<<ans;
    return 0;
}