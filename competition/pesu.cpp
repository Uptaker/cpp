#include <iostream>
#include <string>
#include <map>

using namespace std;

enum Task {
    FLIP, FRONT, BACK, RED, GREEN, BLUE
};

map<string, Task> mappedTask = {
    {"POORA", FLIP},
    {"ETTE", FRONT},
    {"TAHA", BACK},
    {"PUNASEID", RED},
    {"ROHELISI", GREEN},
    {"SINISEID", BLUE},
};

int shirtAmount, queryAmount, startAt, endAt, i;

void colorCounter(char *arr, char color) {
    int count = 0;
    for (int i = startAt; i < endAt + 1; i++) {
        if (arr[i] == color) count++;
    }
    cout << count << endl;
}

void flip(char *arr) {
    char temp;
    for (int low = startAt, high = endAt; low < high; low++, high--) {
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
}
	
int main(void) {
	cin >> shirtAmount >> queryAmount;

    char shirts[shirtAmount];
    
    cin >> shirts;

    // would be cool to have something like a map of <string, function()>.. if I could figure it out

    
    string command;
    char temp;
    int shirtL, shirtR;
    for (int j = 0; j < queryAmount; j++) {
		cin >> command  >> shirtL >> shirtR;
        startAt = shirtL - 1;
        endAt = shirtR - 1;

        switch(mappedTask[command]) {
            case FLIP:
                flip(shirts);
                break;
            case FRONT:
                for (i = 0; i < endAt - startAt + 1; i++) {
                    temp = shirts[i];
                    shirts[i] = shirts[startAt + i];
                    shirts[startAt + i] = temp;
                }
                break;
            case BACK:
                for (i = 0; i < endAt - startAt + 1; i++) {
                    temp = shirts[startAt + i];
                    shirts[startAt + i] = shirts[startAt + i + (shirtAmount - shirtR)];
                    shirts[startAt + i + (shirtAmount - shirtR)] = temp;
                }
                break;
            case RED:
                colorCounter(shirts, 'P');
                break;
            case GREEN:
                colorCounter(shirts, 'R');
                break;
            case BLUE:
                colorCounter(shirts, 'S');
                break;
        };
    }
}