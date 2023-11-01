#include<iostream>
#include<set>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    set<int> Set;
    long long target = -1;
    for(int i = 0;i< n; i++){
        for(int j = 0;j<n;j++)
        Set.insert(i * j);
    }
    for(auto itr : Set ){
        if(itr >= m){
            target = itr;
            break;
        }
    }
    cout << target << endl;
    return 0;
}