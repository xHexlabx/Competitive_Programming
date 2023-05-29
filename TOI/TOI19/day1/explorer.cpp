#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7 ;

int n , x , y ;

long long poss[500001] ;
long long fac[500001] ;
vector<int>adj[500001] ;

void dfs1(int curr , int prev){

    long long cnt = 0 ;
    poss[curr] = 1 ;

    for(auto i : adj[curr]){
        if(i == prev)continue ;
        cnt ++ ;
        dfs1(i , curr) ;
        poss[curr] *= poss[i] ;
        poss[curr] %= mod ;
    }

    poss[curr] *= fac[cnt] ;
    poss[curr] %= mod ;

}


int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;
    int entry ;

    for(int i = 0 ; i < 2 * n - 2 ; i ++ ){

        if(i == 0){
            cin >> x >> y ;
            adj[x].push_back(y) ;
            entry = x ;
        }
        else {
            cin >> y ;
            adj[x].push_back(y) ;
        }
        x = y ;
    }

    fac[0] = 1 , fac[1] = 1 ;

    for(long long i = 2 ; i <= n ; i ++ ){
        fac[i] = i * fac[i - 1] ;
        fac[i] %= mod ;
    }

    dfs1(entry , -1) ;

    cout << poss[entry] ;

    return 0 ;
}
