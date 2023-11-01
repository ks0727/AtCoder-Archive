#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    vector<int> t(N),x(N),y(N);
    vector<pair<int,pair<int,int >>> data;
    for(int i=0;i<N;i++) cin >> t[i] >> x[i] >> y[i];
    int ans = false;
    vector<pair<int,int> > destinations(N);
    for(int i=0;i<N;i++) destinations.push_back(make_pair(x[i],y[i]));
    int x0 = 0, y0 = 0;
    int posX,posY;
    vector<pair<int,int>> positions;
    for(int time =0;time<t[N];time++){
        vector<int> targets;
        for(int i=0;i<data.size();i++){
        }
        if(posX == 0){
            posX++;
            data.push_back(make_pair(time,make_pair(posX,posY)));
        }else{
            posX++;
            data.push_back(make_pair(time,make_pair(posX,posY)));
            posX -= 2;
            data.push_back(make_pair(time,make_pair(posX,posY)));
        }
        if(posY == 0){
            posY++;
            data.push_back(make_pair(time,make_pair(posX,posY)));
        }else{
            posY++;
            data.push_back(make_pair(time,make_pair(posX,posY)));
            posY -= 2;
            data.push_back(make_pair(time,make_pair(posX,posY)));
        }
    }
        

}