#include<bits/stdc++.h>

#define DEBUG 0

using namespace std ;

int n , m , q , x , y , s , t ; 

long long a , b , k ;

vector<long long>coor_x ;
vector<long long>coor_y ;

vector<long long>qs_x ;
vector<long long>qs_y ;

long long count_x(long long idx){

    int ll = 0 , rr = coor_x.size() - 1 , mm ;

    while(ll < rr){

        mm = (ll + rr + 1) >> 1 ;

        if(coor_x[mm] <= idx)ll = mm ;
        else rr = mm - 1 ;
    }

    return qs_x[ll] ;
}

long long count_y(long long idx){

    int ll = 0 , rr = coor_y.size() - 1 , mm ;

    while(ll < rr){

        mm = (ll + rr + 1) >> 1 ;

        if(coor_y[mm] * a + b <= idx)ll = mm ;
        else rr = mm - 1 ;
    }

    return qs_y[ll] ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m >> q ;

    coor_x.push_back(LLONG_MIN) ;
    coor_y.push_back(LLONG_MIN) ;

    qs_x.push_back(0) ;
    qs_y.push_back(0) ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> x ;
        coor_x.push_back(x) ;
    }

    coor_x.push_back(LLONG_MAX) ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> s ;
        qs_x.push_back(s) ;
    }

    qs_x.push_back(0) ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> y ;
        coor_y.push_back(y) ;
    }

    coor_y.push_back(LLONG_MAX) ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> t ;
        qs_y.push_back(t) ;
    }

    qs_y.push_back(0) ;

    for(int i = 1 ; i < qs_x.size() ; i ++ ){
        qs_x[i] += qs_x[i - 1] ;
    }

    for(int i = 1 ; i < qs_y.size() ; i ++ ){
        qs_y[i] += qs_y[i - 1] ; 
    }

    while(q -- ){

        cin >> a >> b >> k ;

        long long l = - 1e9 , r = 1e9 , mid ;

        while(l < r){

            mid = (l + r) >> 1 ;

            long long cnt_x = count_x(mid) ;
            long long cnt_y = count_y(mid) ;

            if(cnt_x + cnt_y >= k) r = mid ;
            else l = mid + 1 ;
        }

        cout << l << '\n' ;
    }




    if(DEBUG){

        for(int i = 0 ; i < coor_x.size() ; i ++ ){
            cout << coor_x[i] << ' ' ;
        }
        cout << '\n' ;

        for(int i = 0 ; i < qs_x.size() ; i ++ ){
            cout << qs_x[i] << " " ;
        }
        cout << '\n' ;

        for(int i = 0 ; i < coor_y.size() ; i ++ ){
            cout << coor_y[i] << ' ' ;
        }
        cout << '\n' ;
        
        for(int i = 0 ; i < qs_y.size() ; i ++ ){
            cout << qs_y[i] << " " ;
        }
        cout << '\n' ;
    }

    

    return 0 ;
}