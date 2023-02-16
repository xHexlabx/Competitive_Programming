#include<bits/stdc++.h>
using namespace std;
int pa[3001] ;
int fp(int x){
    if(pa[x] == x)return x ;
    return pa[x] = fp(pa[x]);
}
struct path {
    int x , y , w ;
    bool operator < (const path & rhs)const {
        return w < rhs.w;
    }
};
struct pro {
    int cost , dis ;
    bool operator < (const pro & rhs)const {
        return cost < rhs.cost ;
    }
};
int n , m , p , x , y , w , stat , cost , dis  ;
long long ans = 0;
int main(){
    
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    vector<path>vec ;
    vector<pro>pro ;
    cin >> n >> m ;
    for(int i = 0 ; i <= n ; i ++ )pa[i] = i ;
    for(int i = 0 ; i < m ; i ++ ){
    
        cin >> x >> y >> w >> stat ;
        if(stat){
            int rootx = fp(x) , rooty = fp(y) ;
            pa[rootx] = rooty ;
        }
        else {
            vec.push_back({x , y , w});
        }
    }
    cin >> p ;
    for(int i = 0 ; i < p ; i ++ ){
        cin >> dis >> cost ;
        pro.push_back({cost , dis});
    }
    sort(vec.begin(),vec.end());
    sort(pro.begin(),pro.end());
    for(auto temp : vec){
        int rootx = fp(temp.x) , rooty = fp(temp.y) ;
        if(rootx == rooty)continue ;
        pa[rootx] = rooty ;
        for(auto pr : pro){
            if(pr.dis >= temp.w){
                ans += pr.cost ;
                break ;
            }
        }
    }
    
    cout << ans ;
    return 0 ;
}