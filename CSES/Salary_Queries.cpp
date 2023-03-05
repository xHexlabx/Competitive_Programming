#include<bits/stdc++.h>

using namespace std;

class Fenwick {

    public : 
        
        long long fw[400001] ;

        void update(int idx , int val){
            for(; idx < 400001 ; idx += (idx & -idx)){
                fw[idx] += val;
            }
        }
        long long query(int idx){
            long long res = 0 ;
            for(; idx > 0 ; idx -= (idx & -idx)){
                res += fw[idx] ;
            }
            return res ;
        }
}fw;

array<int , 200001>arr;
int n , q , k , x , a , b ; 
char cmd ;

vector<array<int , 3>>query ;
vector<int>numlist ;

int find_idx(int val){
    return lower_bound(numlist.begin(), numlist.end(),val) - numlist.begin() ;
}

int find_idx_query(int val){
    
    int l = 0 , r = numlist.size() - 1 ;

    while(l < r){

        int mid = (l + r + 1) >> 1 ;
        if(numlist[mid] <= val)l = mid ;
        else r = mid - 1 ;
    }

    return l ;
}

int find_idx_query2(int val){
    
    int l = 0 , r = numlist.size() - 1 ;

    while(l < r){

        int mid = (l + r + 1) >> 1 ;
        if(numlist[mid] < val)l = mid ;
        else r = mid - 1 ;
    }

    return l ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n >> q ;

    numlist.push_back(0) ;
    numlist.push_back(INT_MAX) ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
        numlist.push_back(arr[i]) ;
    }

    for(int i = 1 ; i <= q ; i ++ ){
        cin >> cmd ;
        if(cmd == '!'){
            cin >> k >> x ;
            query.push_back({0 , k , x}) ;
            numlist.push_back(x) ;
        }
        else {
            cin >> a >> b ;
            query.push_back({1 , a , b}) ;
        }
    }   
    
    sort(numlist.begin(), numlist.end());
	numlist.erase(unique(numlist.begin(), numlist.end()), numlist.end());

    for(int i = 1 ; i <= n ; i ++ ){
        fw.update(find_idx(arr[i]) , 1) ;
    }

    for(int i = 0 ; i < q ; i ++ ){

        array<int , 3>now = query[i] ;
        if(now[0] == 0){
            int pre = arr[now[1]] ;
            int current = now[2] ;
            fw.update(find_idx(pre) , -1) ;
            fw.update(find_idx(current) , 1) ;
            arr[now[1]] = current ;
        }
        else {
            int a = now[1] , b = now[2] ;
            cout << fw.query(find_idx_query(b)) - fw.query(find_idx_query2(a)) << '\n' ;
        }
    }


    return 0 ;
}