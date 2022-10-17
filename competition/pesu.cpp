#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;

enum Task {
    FLIP, FRONT, BACK, RED, GREEN, BLUE
};

void colorCounter(int start, int end, char *arr, char color, int size) {
    start = start - 1;
    end = end - 1;
    int count = 0;
    for (int i = start; i <= end; i++) {
        char col = arr[i];
        if (arr[i] == color) count++;
    }
    cout << count << endl;
}

void flip(int shirtL, int shirtR, char *arr, int size) {
    int start = shirtL - 1;
    int end = shirtR - 1;
 
    for (int i = 0; i < (size - (shirtR - shirtL - 2)) / 2; i++) {
        int temp = arr[start + i];
        arr[start + i] = arr[end - i];
        arr[end - i] = temp;
    }
}

constexpr int getAmount(int amount) {
  return amount;
}
	
int main(void) {
    int shirtAmount, queryAmount;
	cin >> shirtAmount >> queryAmount;

    char shirts[shirtAmount];
    cin >> shirts;

    const int n = sizeof(shirts) / sizeof(shirts[0]);
 
    std::array<int, n> first, second;

    // would be cool to have something like a map of <string, function()>.. if I could figure it out
    map<string, Task> mappedTask = {
        {"POORA", FLIP},
        {"ETTE", FRONT},
        {"TAHA", BACK},
        {"PUNASEID", RED},
        {"ROHELISI", GREEN},
        {"SINISEID", BLUE},
    };
    
    for (int i = 0; i < queryAmount; i++) {
    	string command;
    	int shirtL;
    	int shirtR;
		cin >> command  >> shirtL >> shirtR;


        switch(mappedTask[command]) {
            case FLIP:
                flip(shirtL, shirtR, shirts, shirtAmount);

                break;
            case FRONT:
                for (int i = 0; i < shirtAmount; i++) {
                    int start = shirtL - 1;
                    int end = shirtR - 1;
                    char temp = shirts[i];
                    shirts[i] = shirts[start + i];
                    shirts[start + i] = temp;
                    if (i == (end - start)) break;

                }
                break;
            case BACK:
                std::rotate(std::begin(shirts) + shirtL - shirtR, begin(shirts) + shirtR, end(shirts));	
                break;
            case RED:
                colorCounter(shirtL, shirtR, shirts, 'P', shirtAmount);
                break;
            case GREEN:
                colorCounter(shirtL, shirtR, shirts, 'R', shirtAmount);
                break;
            case BLUE:
                colorCounter(shirtL, shirtR, shirts, 'B', shirtAmount);
                break;
        };
    }
}