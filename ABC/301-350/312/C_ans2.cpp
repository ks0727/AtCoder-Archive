#include<bits/stdc++.h>
using namespace std;
//二分探索を用いて解く

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a.at(i);
    for(int i=0;i<m;i++) cin >> b.at(i);
    int wa = 0, ac =1e9;
    while(wa+1 < ac){
        int wj = (wa+ac) / 2;
        int na = 0, nb = 0;
        for(int i = 0;i<n;i++){
            if(a.at(i) <= wj) na++; //naはAi円で売ってもいい人の数
        }
        for(int j=0;j<m;j++){
            if(b.at(j) >= wj) nb++; //nbはBi円で買ってもいい人の数
        }
        if(na >= nb) ac = wj;
        else wa = wj;
    }
    cout << ac << endl;
}