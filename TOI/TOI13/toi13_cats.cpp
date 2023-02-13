#include<bits/stdc++.h>
#define endll '\n'
#define vec vector
#define umap unordered_map
#define ll unsigned long long 
using namespace std;
ll arr[20000001];
int main(){
	
	ll n ; scanf("%lld" , &n);
	for(ll i = 0 ; i < n ; i ++)scanf("%lld" , &arr[i]) ;
	ll l = 0 , r = 1e10 , mid; 
	bool can ; deque<ll>dq ;
	
	while(l < r){
		dq.clear();
		mid = (l + r) >> 1 ;
		for(int i = 0 ; i < n ; i ++ ){
			if(arr[i] > mid){
				if(dq.empty())dq.push_back(arr[i]);
				else {
					if(dq.back() == arr[i])dq.pop_back();
					else  break;
				}
			}
		}
		if(dq.empty())r = mid ;
		else l = mid  + 1; 
	}
	printf("%lld" , l) ;
	return 0;
}
