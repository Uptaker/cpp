#include <iostream>
using namespace std;

int valjundeid, dioode;
int main(void){
	cin >> valjundeid >> dioode;
	int v[valjundeid+1];
	int d[dioode][2];
	for(int i=0; i<dioode; i++){
		cin >> d[i][0] >> d[i][1];
	}
	for(int i=0; i<valjundeid+1; i++){v[i]=0;}
   for(int j=0; j<8; j++){
	int viimane=valjundeid;
	while(v[viimane]==1){viimane--;}
	if(viimane>0){
	  if(v[viimane]==0){v[viimane]=1;}
	  while(viimane<valjundeid){
		  viimane++;
		  v[viimane]=0;
	  }
	}
	for(int i=0; i<=valjundeid; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	for(int i=0; i<dioode; i++){
		if(v[d[i][0]]==1 && v[d[i][1]]==0){
			cout << "d " << i << endl;
		}
	}
   }
}