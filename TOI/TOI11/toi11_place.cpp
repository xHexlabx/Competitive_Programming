#include<bits/stdc++.h>
using namespace std ;
int pa[200001] ;
int rnk[200001] ;
int fp(int x){
    if(pa[x] == x)return x ;
    return pa[x] = fp(pa[x]);
}
struct path {
    int u , v , w ;
    bool operator < (const path & p2)const {
        return w > p2.w ;
    }
};
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0);
    for(int i = 1 ; i <= 200000 ; i ++ ){
        pa[i] = i ;
        rnk[i] = 1;
    }
    int n , m , cnt = 0 ; cin >> n >> m ;
    long long res = 0 ;
    vector<path>graph ;
    for(int i = 0 ; i < m ; i ++ ){
        int U , V , W ;
        cin >> U >> V >> W ;
        graph.push_back({U , V , W - 1});
    }
    sort(graph.begin(), graph.end());
    for(int i = 0 ; i < m ; i ++ ){
        auto temp = graph[i] ;
        int rootx = fp(temp.u);
        int rooty = fp(temp.v);
        if(rootx == rooty)continue ;
        if(rnk[rootx] > rnk[rooty]){
            rnk[rootx] += rnk[rooty];
            rnk[rooty] = 0 ;
            pa[rooty] = rootx ;
        }
        else {
            rnk[rooty] += rnk[rootx];
            pa[rootx] = rooty ;
        }
        res += temp.w ;
        cnt ++ ;
        if(cnt == n - 1)break ;
    }
    cout << res ;
    return 0 ;
}