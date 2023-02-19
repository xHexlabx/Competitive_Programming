#include<bits/stdc++.h>
using namespace std;
int n , m , k ;
priority_queue<long long , vector<long long> , greater<long long>>pq;
long long arr[100001] ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> m >> k ;
    for(int i = 0 ; i < n ; i ++ )cin >> arr[i] ;
    long long l = 0 , r = 5e10 ;
    while(l < r){
        
        int target = 0 , cnt = 0 ; 
        long long mid = (l + r + 1) >> 1 , sum = 0 ;
        while(!pq.empty())pq.pop() ;
        for(int i = 0 ; i < n ; i ++ ){
            
            if(target == m)break ;
            pq.push(arr[i]) ;
            sum += arr[i] ;
            cnt ++ ;
            if(cnt > k){
                sum -= pq.top() ;
                pq.pop() ;
                cnt -- ;
            }
            if(cnt == k){
                if(sum >= mid){
                    target ++ ;
                    sum = 0 ;
                    cnt = 0 ;
                    while(!pq.empty())pq.pop() ;
                }
            }
        }
        if(target == m)l = mid ;
        else r = mid - 1;
    }
    cout << l ;
    
    return 0 ;
}