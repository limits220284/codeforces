#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<set>
#include<map>
#include<vector>
#include<climits>
#include<queue>
using namespace std;


const int N = 100010;
typedef long long ll;

class DSU{
public:
    vector<int> p;
    vector<int> rank;
    int n;
    vector<int> sz;
    DSU(int _n){
        n = _n;
        p.resize(n);
        rank.resize(n, 0);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
    }
    int find(int x){
        if(x != p[x]) 
            p[x] = find(p[x]);
        return p[x];
    }
    bool merge(int a, int b){
        int fa = find(a), fb = find(b);
        if(fa == fb) return false;
        if(rank[fa] < rank[fb]){
            p[fa] = fb;
            sz[fb] += sz[fa];
        }
        else if(rank[fa] > rank[fb]){
            p[fb] = fa;
            sz[fa] += sz[fb];
        }
        else{
            p[fa] = fb;
            rank[fb] += 1;
            sz[fb] += sz[fa];
        }
        return true;
    }
};

void solve(){
    int n;
    cin >> n;
    DSU uf(10000);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        uf.merge(a, b);
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        a = uf.find(a), b = uf.find(b);
        if(a == b) cout << 1 << endl;
        else cout << 0 << endl;        
    }
}

int main(){
    solve();
    return 0;
}