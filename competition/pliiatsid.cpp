#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "bits/stdc++.h"
#include <cstdlib>  

using namespace std;


int pencils;

vector<tuple<int, int>> test(char pencilsasChar[], char smaller){
	int start;
	int end;
	int prev = -1;
	int count = 0;
	vector<tuple<int, int> > moves;
	for (int i = 0; i < pencils; i++) {
		if(pencilsasChar[i] == smaller){
			if (prev == -1) start = i + 1;	
			prev = i;
		}
		else if (pencilsasChar[i]!=smaller){
			if (prev != -1){
				end = i;
				moves.push_back(make_tuple(start, end));
			}
			prev = -1;
		}
   }
   return moves;	
}

int main(void) {
	cin >> pencils;
	
	string pencilsAsString;
    char pencilsAsChar[pencils];
    cin >> pencilsAsString;
    strcpy(pencilsAsChar, pencilsAsString.c_str());
	
	vector <int> tPos;
	vector <int> nPos;
	
	int tCount=0;
	int nCount=0;
	for (int i = 0; i < pencils; i++) {
		if(pencilsAsChar[i]=='t'){
			tPos.push_back(i);
			tCount++;
		}
		else if(pencilsAsChar[i]=='n'){
			nPos.push_back(i);
			nCount++;
		}
	}
	
	vector<tuple<int, int> > moves;
	char smaller;
	if(tCount > nCount){
		smaller= 'n';
		moves = test(pencilsAsChar,smaller);
		
	}
	else if(tCount < nCount){
		smaller= 't';
        moves = test(pencilsAsChar, smaller);
    }
	else if (tCount == nCount){
		vector<tuple<int, int> > moves1;
		vector<tuple<int, int> > moves2;
		moves1 = test(pencilsAsChar,'t');
		moves2 = test(pencilsAsChar,'n');
		if (moves1.size() > moves2.size()) moves = moves2;
		else if(moves2.size() >= moves1.size()) moves = moves1;
	}	

	cout<<moves.size()<<endl;
	for(int i = 0; i < moves.size(); i++){
 		int a = get<0>(moves[i]);
 		int l = get<1>(moves[i]);
 		cout<< a << "-" << l <<endl;
 	}
}