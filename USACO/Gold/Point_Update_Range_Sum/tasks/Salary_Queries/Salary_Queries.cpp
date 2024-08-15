#include<bits/stdc++.h>

using namespace std ;

const int Size = 6e5 + 1 ;
char mode ;
int n , q , val , k , x , a , b ;

int salaries [Size] ;

vector<int>vec ;

struct event {
    char mode ;
    int k , x ;
    int a , b ;

    event (char Mode , int K , int X , int A , int B) {
        mode = Mode ;
        k = K ;
        x = X ;
        a = A ;
        b = B ;
    }
};

vector<event>events ;

int get_idx (int val){
    int idx = lower_bound(vec.begin() , vec.end() , val) - vec.begin() ;
    return idx + 1 ;
};

struct Fenwick {
    
    int fw [Size] ;

    void set (int idx , int val) {
        for(;idx < Size ; idx += (idx & -idx))fw[idx] += val ;
        return ;
    }

    int get (int idx) {
        int res = 0 ;
        for(; idx > 0 ; idx -= (idx & -idx))res += fw[idx] ;
        return res ;
    }

}fw;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> salaries[i] ;
        vec.push_back(salaries[i]) ;
    }

    for(int i = 1 ; i <= q ; i ++ ){

        cin >> mode ;

        k = 0 , x = 0 , a = 0 , b = 0 ;

        if(mode == '!'){
            cin >> k >> x ;
            vec.push_back(x) ;
        }
        else {
            cin >> a >> b ;
            vec.push_back(a) ;
            vec.push_back(b) ;
        }

        events.push_back({mode , k , x , a , b}) ;
    }

    sort(vec.begin() , vec.end()) ;
    vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ;
    
    for(int i = 1 ; i <= n ; i ++ ){
        fw.set(get_idx(salaries[i]) , 1) ;
    }

    for(event e : events){

        if(e.mode == '!'){
            
            int previous_val = salaries[e.k] ;
            salaries[e.k] = e.x ;

            fw.set(get_idx(previous_val) , -1) ;
            fw.set(get_idx(e.x) , 1) ;

        }
        else {
            cout << fw.get(get_idx(e.b)) - fw.get(get_idx(e.a) - 1) << '\n';
        }
    }

    return 0 ;
}