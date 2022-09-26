#include <iostream>
#include <string>
using namespace std;
 
 
int main(void){
	int paevi;
//cout << "Sisesta paevade arv" << endl;
	cin >> paevi;
 
	// 	paev1  esimene +1
	//paev2	 esimene+1  teine+2
	//paev3 esimene+1 teine+2 kolmas+3
	//paev4 esimene+1 teine+2 kolmas+3 neljas+4
	//paev5 esimene1 teine+2 kolams +3 neljas+4 
 
	int kingitused [paevi];
 
	for(int i= 0; i < paevi; i++){
		kingitused[i]= 0;
	}
 
	for(int i= 1; i <= paevi; i++){
		//siit saab päev 1  päev 2
		//cout<< "päev nr: "<< i << endl;
		for (int j=1; j <=i; j++){
			//cout<< "päev nr: "<< i << "kord"<< j<< endl;
 
 
 
 
			kingitused[j-1] += j; 
			//cout<< "kingitused " << j << "on kingitusi: "<<kingitused[j-1]<<endl;  
 
		}
	}
 
	for(int j=0;j<paevi;j++){
		cout<<kingitused[j]<<endl;;
	}
}