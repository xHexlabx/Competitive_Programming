#include<bits/stdc++.h>

using namespace std;

struct mountain {

    int l , r , idx ;

    bool operator <  (const mountain& rhs) const {

        if(l != rhs.l)return l < rhs.l;
        return r > rhs.r;
    }
};

vector<mountain>mountains ;
vector<int>lnds ;

int n , MAX = 0 ;
int ans[400001] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i++){
        
        mountain temp ;

        cin >> temp.l >> temp.r ;
        temp.idx = i ;

        mountains.push_back(temp);
    }

    sort(mountains.begin(), mountains.end()) ;

    reverse(mountains.begin(),mountains.end()) ;

    for(int i = 0 ; i < n ; i ++ ){
        
        int curr = mountains[i].r;

        auto it = upper_bound(lnds.begin(),lnds.end(),curr);

        if(it == lnds.end()){
            lnds.push_back(curr);
            ans[mountains[i].idx] = lnds.size() ;
        }
        else {
            *it = curr ;
            ans[mountains[i].idx] = int(it - lnds.begin()) + 1 ;
        }

        MAX = max(MAX , ans[mountains[i].idx]) ;
    }

    cout << MAX << '\n' ;
    
    for(int i = 0 ; i < n ; i ++ ){
        cout << ans[i] << ' ' ;
    }

    return 0 ;
}