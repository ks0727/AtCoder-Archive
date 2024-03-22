#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct V{
    double x,y;
    V(double x=0,double y=0):x(x),y(y){}
    V& operator+=(const V& v){
        x += v.x; y+= v.y;
        return *this;
    }
    V operator+(const V& v) const {return V(*this) += v;}
    V& operator-=(const V& v){
        x -= v.x; y -= v.y;
        return *this;
    }
    V operator-(const V& v)const{return V(*this) -= v;}
    V& operator*=(double s){
        x *= s; y *= s;
        return *this;
    }
    V operator*(double s){return V(*this) *=s;}
    V& operator/=(double s){
        x /= s; y /= s;
        return *this;
    }
    V operator/(double s){return V(*this) /=s;}
    double dot(const V& v)const{return x*v.x + y*v.y;} //内積
    double cross(const V& v)const {return x*v.y-v.x*y;} //外積
    double norm2()const{return x*x+y*y;} //ベクトルの絶対値
    double norm()const{return sqrt(norm2());} //ベクトルの絶対値のルート
    V rotate90() const{return V(y,-x);}
    int ort()const{ //orthant 第何象限にあるか
        if(y > 0) return x>0 ? 1 : 2;
        else return x<0 ? 3 : 4;
    }
    bool operator<(const V& v)const{ //ベクトル同士の比較
        int o = ort(), vo = v.ort();
        if(o != vo) return o < vo;
        return cross(v) > 0; //外積が正かどうか
    }
};
istream& operator>>(istream& is, V & v){//入力 cinで入力できるようになる
    is >> v.x >> v.y;
    return is;
}
ostream& operator>>(ostream& os, V & v){//出力 coutが使えるようになる
    os << "("<< v.x << ","  << v.y << ")";
    return os;
}
void chmin(double &a, double &b){a = min(a,b);}
int main(){
    int n,m;
    cin >> n >> m;
    int w = n+m+1;
    vector<V> p(w);
    rep(i,w-1) cin >> p[i];
    int w2 = 1<<w;
    vector<double> sp(w2,1); //0~wまでのbit列のそれぞれのスピードを入れておく
    rep(s,w2){ //0~wまでの2進数のbit列を全て作る
        rep(i,m) if(s>>(n+i)&1) sp[s] /=2; //bit列のうち宝箱は何個かを数えて速度を求める
    }
    vector dist(w,vector<double>(w));
    rep(i,w)rep(j,w) dist[i][j] = (p[i]-p[j]).norm();
    const double INF = 1e18;
    vector dp(w2,vector<double>(w,INF));
    dp[0][n+m] = 0;
    rep(s,w2)rep(v,w){
        if(dp[s][v] == INF) continue;
        rep(u,w){
            if(~s>>u&1){ //sのuビット目が立っていないならば
                dp[s|1<<u][u] = min(dp[s|1<<u][u],dp[s][v]+dist[v][u]*sp[s]);
            }
        } 
    }
    double ans = INF;
    int t = (1<<n)-1 | 1<<(n+m); //tは原点と街にbitをたてたもの
    rep(s,w2){
        if((s&t)==t) chmin(ans,dp[s][n+m]); //tがsの部分集合であれば
    }
    printf("%.10f\n",ans);
    return 0;
}