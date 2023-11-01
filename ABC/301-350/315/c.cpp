#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int> > X(0);
    vector<int> F(N),S(N);
    int satis1 = 0;
    int satis2 = 0;
    int ans = 0;
    for(int i=0;i<N;i++) cin >> F.at(i) >> S.at(i);
    for(int i=0;i<N;i++){
        X.push_back(make_pair(S.at(i),F.at(i)));
    }
    sort(X.begin(),X.end());
    if(X.at(N-1).second == X.at(N-2).second){
        satis1 = X.at(N-1).first + X.at(N-2).first / 2;
        int i = N-3;
        while(true){
            if(i < 0) break;
            if(X.at(N-1).second != X.at(i).second){
                satis2 = X.at(N-1).first + X.at(i).first;
                ans = max(satis1,satis2);
                break;
            }
            i--;
        }
    }

    else{
        satis1 = X.at(N-1).first + X.at(N-2).first;
        int i = N-3;
        while(true){
            if(i<0) break;
            if(X.at(N-1).second == X.at(i).second){
                satis2 = X.at(N-1).second + X.at(i).second/2;
                ans = max(satis1,satis2);
                break;
            }
            
            i--;
        }
    }
    cout << ans << endl;
}