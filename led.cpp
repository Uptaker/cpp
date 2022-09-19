#include <iostream>
using namespace std;

int valjundeid, dioode;

int main (void){
	// sisestan väljundite arvu ja dioodide arvu
	cout << "Sisesta valjundite arv ja dioodide arv: "<< endl;
	cin >> valjundeid >> dioode;
	//loon väljundite array mis on 2kohta pikem kui sisestatud väljundite arv
	int v[valjundeid+1];
	
	//loon dioodide maatrixi milles on dioodide arv veerge ja 2 tulpa
	//esimene tulp anood teine tulp katood
	int d[dioode][2];
	
	//sisestan iga dioodi anoodi ja katoodi andmed
	for(int i=0; i<dioode; i++){
		cout << "Siseste dioodi "<< i+1 << " anood ja katood:"<<endl;
		cin >> d[i][0] >> d[i][1];
	}
	//cout << d[1][0];
	
	//prindin maatrixi välja
	cout<< "Sisestatud anoodide ja katoodi maatrixi printout: " <<endl;
	for(int i=0; i<dioode; i++){
		cout<< d[i][0]<< " " << d[i][1] <<endl;
	}
	
	//algseadistan väljundite array nullidega
	for(int i=0; i<valjundeid+1; i++){v[i]=0;}
	
	cout << " algseadistatud väljundite array:"<<endl;
	for(int i=0; i<valjundeid+1; i++){
		cout << v[i] << " "; 
	}
	cout<<endl;
	
	//loop 8 korda
	for(int j=0; j<8; j++){
		// vätan kasutusele abimuutuja viimane ja algseadistan selle väljundite arvuga
		int viimane = valjundeid;
		
		//kui väljundi arrays viimasel positsioonil on 1 mine äks positsioon väiksemaks  
		while(v[viimane]==1){viimane--;}
		
		// kui positsioon viimane pole 0
		
		if(viimane>0){
			//kui valjund positsoonil viimane on 0 muuda väljund positsoonil viimane äheks;
			if(v[viimane]==0){v[viimane]=1;}
			//cout<< "yheks" <<endl;
			//kuni array v positsioon viimane on väiksem väljundite arvust 
			while(viimane < valjundeid){
				//suurendan positsiooni viimane ähe värra ja määran väljundi sel positsiooni 0ks.
				viimane++;
				v[viimane]=0;
			}	
		}
		cout << "väljundite array "<< j+1 << " ringil"<<endl;
		for(int i=0; i<=valjundeid; i++){
			cout << v[i] << " ";
		}
		cout<<endl;
		
		cout << "viimane printout:" <<endl;
		for(int i=0; i<dioode; i++){
			
			cout << v[d[i][0]] << " " << v[d[i][1]] << endl;
			if(v[d[i][0]]==1 &&  v[d[i][1]]==0){
				cout << "d " << i << endl;
				
			}
		}
	}
}

/*
Sisend
3 3
1 2
2 3
1 3
Väljund
JAH
JAH
EI

Sisend
3 4
1 2
2 1
2 3
3 2
Väljund
JAH
JAH
JAH
JAH
*/
