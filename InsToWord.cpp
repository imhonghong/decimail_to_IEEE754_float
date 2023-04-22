#include <iostream>
#include <cmath>
using namespace std;

int main(){
	cout<<"transfer signed integer into 32bit two's complement"<<endl;
	
	while(1){
		int A;
		cin>>A;
		

		int B[32];
		
		//A>0
		if(A>=0){
			B[31]=0;
			for(int e=30; e>=0 ; e--){
				int b=A-pow(2,e);
				if(b<0)
					B[e]=0;
				else{
					B[e]=1;
					A=b;
				}
			}
		}
		
		//A<0
		else{
			A=-A;
			B[31]=1;
				for(int e=30; e>=0 ; e--){
					int b=A-pow(2,e);
					if(b<0)
						B[e]=0;
					else{
						B[e]=1;
						A=b;
					}
				}
			
			//2's complement
			int j;
			for(j=0 ; j<31 ; j++){
				if(B[j])
					break;
			}
			for(j=j+1 ; j<31 ; j++){
				if(B[j])
					B[j]=0;
				else
					B[j]=1;
			}
		}

		//print B
		for(int i=31 ; i>=0 ; i--){
			cout<<B[i];
			if(i%4==0)
				cout<<" ";
			}
		
		cout<<endl<<"----------"<<endl;	
	}
	return 0;
}
