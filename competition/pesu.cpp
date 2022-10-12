#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

enum Task {
    FLIP, FRONT, BACK, RED, GREEN, BLUE
};

vector <char> shirts;

void colorCounter(int shirtL, int shirtR, char color) {
	cout << (std::count (shirts.begin() + shirtL - 1, shirts.begin() + shirtR, color)) << endl;
}
	
int main(void) {
    int shirtAmount, queryAmount;
	cin >> shirtAmount >> queryAmount;

    char shirtInitialOrder[shirtAmount];
    cin >> shirtInitialOrder;

    // would be cool to have something like a map of <string, function()>.. if I could figure it out
    map<string, Task> mappedTask = {
        {"POORA", FLIP},
        {"ETTE", FRONT},
        {"TAHA", BACK},
        {"PUNASEID", RED},
        {"ROHELISI", GREEN},
        {"SINISEID", BLUE},
    };

    
	for (int i = 0; i < shirtAmount; i++){
		shirts.push_back(shirtInitialOrder[i]);
	}
    
    for (int i = 0; i < queryAmount; i++) {
    	string command;
    	int shirtL;
    	int shirtR;
		cin >> command  >> shirtL >> shirtR;

        switch(mappedTask[command]) {
            case FLIP:
                reverse(shirts.begin() + shirtL - 1, shirts.begin() + shirtR);
                break;
            case FRONT:
               rotate(shirts.rbegin() + (shirtAmount - (shirtR)), shirts.rbegin() + (shirtAmount - (shirtL - 1)), shirts.rend());
                break;
            case BACK:
                rotate(shirts.begin() + shirtL - 1, shirts.begin() + shirtR, shirts.end());
                break;
            case RED:
                colorCounter(shirtL, shirtR, 'P');
                break;
            case GREEN:
                colorCounter(shirtL, shirtR, 'R');
                break;
            case BLUE:
                colorCounter(shirtL, shirtR, 'S');
                break;
        };
    }
}