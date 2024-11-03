template<class S,auto op,auto e> struct segtree{
    int n;
    vector<S> d;
    segtree(int n):n(n){
        d.resize(2*n,e());
    }
    void update(int k){
        d[k] = op(d[2*k],d[2*k+1]);
    }
    void set(int p,S x){
        p += n;
        d[p] = x;
        while(p){
            update(p>>1);
            p>>=1;
        }
    }
    S get(int p){
        return d[p+n];
    }
    S prod(int l,int r){
        l += n; r+=n;
        S lb = e(),rb=e();
        while(r>l){
            if(l&1) lb = op(lb,d[l++]);
            if(r&1) rb = op(rb,d[--r]);
            l>>=1;
            r>>=1;
        }
        return op(rb,lb);
    }
    void show(){
        for(int i=0;i<n;i++){
            cout << d[i+n] << ' ';
        }
        cout << endl;
    }
};

