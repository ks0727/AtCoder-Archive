#include<bits/stdc++.h>
using namespace std;

int main(){
    int N ;
    set<int> Set;
    cin >> N;
    for(int i=0;i<N;i++){
        int d;
        cin >> d;
        Set.insert(d);
    }
    cout << Set.size() << endl;
}