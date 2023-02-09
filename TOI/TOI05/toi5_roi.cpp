#include<bits/stdc++.h>
using namespace std ;
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0);
	
	double paid ; cin >> paid ;
	int book , price ; 
	double MIN = INT_MAX ; 
	
	for(int i = 1000 ;  i <= 15000 ; i += 500 ){
		double allpaid = paid + i * (100 -  (  (i - 1000 ) / 500  ));
		
		for(int j = 74 ; j <= 144 ; j ++){
			double money = j *  ( ((100 - (0.8569 * exp(0.09*(j - 100)))) * i ) / 100 ) ;
			if(money - allpaid >= 0 && money - allpaid < MIN){
				book = i ;
				price = j ;
				MIN = money - allpaid ;
			}
		}
		
	}
	printf("%d\n%d\n%.2lf" , book , price , MIN );
	return 0 ;
}