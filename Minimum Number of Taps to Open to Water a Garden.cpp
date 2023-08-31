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