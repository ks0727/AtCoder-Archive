#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> P(N);
    vector<int> C(N);
    vector<vector<int> > F(N,vector<int>(101));
    bool isBreak = false;
    bool ans = false;
    for(int i=0;i<N;i++){
        cin >> P[i] >> C[i];
        for(int j=0;j<C[i];j++) cin >> F[i][j];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!isBreak){
                if(P[j] < P[i]){
                    for(int k=0;k<F[k].size();k++){
                        if(find(F[j].begin(),F[j].end(),F[i][k]) != F[j].end()){
                            continue;
                        }
                        else{
                            isBreak = true;
                            ans = false;
                            break;
                        }
                        if(k==F[k].size()-1) ans = true;
                    }
                }
                    else{
                        isBreak = true;
                        ans = false;
                        break;
                    }
            }
            
            }
        }
        cout << (ans ? "Yes" : "No") << endl;
    }
