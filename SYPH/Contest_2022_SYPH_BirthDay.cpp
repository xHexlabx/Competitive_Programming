#include<bits/stdc++.h>

using namespace std ;

long long line[500001] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    int n , m , w , s , p; cin >> n >> m ;
    while(m -- ){
        cin >> w >> s >> p ;
        line[s] += w ;
        line[p + 1] -= w ;
    }
    for(int i = 1 ; i <= 500000 ; i ++ ){
        line[i] += line[i - 1];
    }
    while(n -- ){
        int idx ; cin >> idx ;
        cout << line[idx] << '\n' ;
    }
    return 0 ;
}