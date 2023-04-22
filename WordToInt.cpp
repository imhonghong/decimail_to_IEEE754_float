#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
	while(1){
		cout<<"input with 32bits: "<<endl;
		cout<<"31-----------------------------0"<<endl;
		
		string A;
		cin>>A;
		
		if(A.length()<=32){
		//convert string to int-array
		int Arr[32];
		for(int i=0; i<32 ; i++){
			Arr[i]=(A.at(i)-48);
			if(Arr[i]>1||Arr[i]<0){
				cout<<"invalid input"<<endl;
				return 0;
			}
		}
		
		int sum=0;
		//A>0
		if(Arr[0]==0){
			for(int e=0 ; e<31 ; e++){
				if(Arr[31-e])
					sum=sum+pow(2,e);
			}
		}
		//A<0
		else{
		//2's complement
		int j;
		for(j=31 ; j>=0 ; j--){
			if(Arr[j])
				break;
		}
		for(j=j-1 ; j>=0 ; j--){
			if(Arr[j])
				Arr[j]=0;
			else
				Arr[j]=1;
		}
		//summing part
		for(int e=0 ; e<31 ; e++){
			if(Arr[31-e])
				sum=sum-pow(2,e);
		}
		}
		
		//print
		cout<<"output:"<<endl<<sum<<endl<<endl;
		}
		
		else{
			cout<<"invalid input"<<endl;
			return 0;
		}
	}
	return 0;
}

