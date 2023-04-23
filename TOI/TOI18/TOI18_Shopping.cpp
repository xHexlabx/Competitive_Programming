#include<bits/stdc++.h>

using namespace std;

int cost[500001] , point[500001] , money , x ; 
int n , q , str , idx , l , r , mid ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> x ;
        if(x < 0){
            cost[i] = -x ;
        }
        else {
            point[i] = x ;
        }
        cost[i] += cost[i - 1] ;
        point[i] += point[i - 1] ;
    }

    while(q -- ){
        cin >> str >> money;
        idx = str + 1 ;
        l = idx , r = n ;
        while(l < r){
            mid = (l + r + 1) >> 1 ;
            if(cost[mid] - cost[idx - 1] < money)l = mid ;
            else r = mid - 1 ;
        }
        cout << point[l] - point[idx - 1] << '\n' ;
    }
    return 0 ;
}