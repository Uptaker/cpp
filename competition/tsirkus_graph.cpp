#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main(void){
   map<int, int> seosed;
   map<int, queue<int> > kohal;
   queue<int> hallid;
   int n, m, kust, kuhu;
   cin >> n >> m;
   for(int i=0; i<m; i++){
	   cin >> kust >> kuhu;
	   seosed[kust]=kuhu;
   }
   hallid.push(1);
   kohal[1]=queue<int>{};
   while(hallid.size()>0){
	   int uuritav=hallid.front();
	   hallid.pop();
	   for(int veeretustulemus=1; veeretustulemus<=6; veeretustulemus++){
		   int uus=uuritav+veeretustulemus;
		   if(!kohal.count(uus) && uus<=n){
			   kohal[uus]=kohal[uuritav];
			   kohal[uus].push(veeretustulemus);
			   if(seosed.count(uus)){
				   int sihtkoht=seosed[uus];
				   kohal[sihtkoht]=kohal[uus];
				   hallid.push(sihtkoht);
			   } else {
				   hallid.push(uus);
			   }
		   }	   
	   }
	   if(uuritav != n){
	   
	   		kohal[uuritav]=queue<int>{};
	   }
   }
   //cout << kohal.count(n) << endl;
   if(kohal.count(n)){
	   cout << kohal[n].size() << endl;
       while(kohal[n].size()>0){
		   cout << kohal[n].front() << ((kohal[n].size()>1)?" ":"");
		   kohal[n].pop();
	   }
	   cout<< endl;
   } else {
	   cout << "EI SAA" << endl;
   }
}