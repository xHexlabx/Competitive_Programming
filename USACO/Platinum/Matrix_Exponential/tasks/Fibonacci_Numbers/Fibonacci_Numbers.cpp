#include<bits/stdc++.h>

using namespace std ;

const long long mod = 1e9 + 7 ;
long long n ;

struct Matrix {

    long long vec[2][2] = {0} ;

    Matrix operator * (const Matrix & rhs){

        Matrix res ;

        for(int i = 0 ; i < 2 ; i ++ ){
            for(int j = 0 ; j < 2 ; j ++ ){
                for(int k = 0 ; k < 2 ; k ++ ){
                    res.vec[i][k] = vec[i][j] * rhs.vec[j][k] ;
                    res.vec[i][k] %= mod ;
                }
            }
        }

        return res ;
    }
};

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    eigen = { {1 , 1} , {1 , 0}} ;
    base = { {1} , {0}} ;
    
    // long long diff = n - 1 ;
    // long long bit = 1 ;

    // while(diff != 0){

    //     if(diff & bit){
    //         base = mul(eigen , base) ;
    //         diff ^= bit ;
    //     }

    //     eigen = mul(eigen , eigen) ;
    //     bit <<= 1 ;
    // }

    // cout << base[1][0] ; 

    return 0 ;
}