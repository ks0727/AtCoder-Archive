#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,P,Q;
    cin >> N >> P >> Q;
    vector<int> D(N);
    for(int i=0;i<N;i++) cin >> D[i];
    int min = *min_element(D.begin(),D.end());
    if(Q+min < P) cout << min + Q << endl;
    else cout << P << endl;

}