#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int> > P(N);
    for(int i=0;i<N;i++){
        cin >> P.at(i).first >> P.at(i).second;
        swap(P.at(i).first,P.at(i).second);
    }
    sort(P.begin(),P.end());
    
    for(int i=0;i<N;i++){
        swap(P.at(i).first,P.at(i).second);
        cout << P.at(i).first << ' ' << P.at(i).second << endl;
    }
}