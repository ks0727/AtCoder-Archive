#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    vector<int> arr;
    for(int i=1;i<(10);i++) arr.push_back(i*5);
    int x = 3;
    int res = upper_bound(arr.begin(),arr.end(),x) - arr.begin() - 1;
    return 0;
}