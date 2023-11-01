#include<bits/stdc++.h>
using namespace std;

vector<string> S(110);
bool check(int i,int j){
    for(int ii =0; ii<3;ii++){
        for(int jj=0;jj<3;jj++){
            if(S.at(i+ii).at(j+jj) != '#') return false;
        }
    }
    for(int ii=0;ii<3;ii++){
        for(int jj=0;jj<3;jj++){
            if(S.at(i+8-ii).at(j+8-jj) != '#') return false;
        }
    }
    for(int ii=0;ii<4;ii++) if(S.at(i+ii).at(j+3) != '.') return false;
    for(int jj=0;jj<4;jj++) if(S.at(i+3).at(j+jj) != '.') return false;
    for(int ii=0;ii<4;ii++) if(S.at(i+8-ii).at(j+8-3) != '.') return false;
    for(int jj=0;jj<4;jj++) if(S.at(i+8-3).at(j+8-jj) != '.') return false;
    return true;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int> > ans;
    for(int i=0;i<N;i++) cin >> S.at(i);
    for(int i=0;i<N-8;i++){
        for(int j=0;j<M-8;j++){
            if(check(i,j)){
                ans.push_back(make_pair(i+1,j+1));
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans.at(i).first << ' ' << ans.at(i).second << endl;
    }
}