struct{
    #define lowbit(x) (x & -x)
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n + 5;
        bit = vector<int>(n, 0);
    }
    int query(int x){
        int ans = 0;
        for(; x > 0 ; x -= lowbit(x)) ans += bit[x];
        return ans;
    }
    int query(int l, int r) {
        if(l > r) return 0;
        return query(r) - query(l - 1);}
    void update(int x, int v){ for(; x < n ; x += lowbit(x)) bit[x] += v;}
    void range_update(int l,int r,int v){ // f[n]
        update(l,v);
        update(r+1,-v);
    }}BIT;