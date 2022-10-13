#include <iostream>
#include <string>
#include <map>

using namespace std;

enum Task {
    FLIP, FRONT, BACK, RED, GREEN, BLUE
};

void colorCounter(int start, int end, char *arr, char color, int size) {
    int count = 0;
    for (int i = start; i < end + 1; i++) {
        if (arr[i] == color) count++;
    }
    cout << count << endl;
}

void flip(int start, int end, char *arr) {
    char temp;
    for (int low = start, high = end; low < high; low++, high--) {
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
}
	
int main(void) {
    int shirtAmount, queryAmount;
	cin >> shirtAmount >> queryAmount;

    char shirts[shirtAmount];
    
    cin >> shirts;

    // would be cool to have something like a map of <string, function()>.. if I could figure it out
    map<string, Task> mappedTask = {
        {"POORA", FLIP},
        {"ETTE", FRONT},
        {"TAHA", BACK},
        {"PUNASEID", RED},
        {"ROHELISI", GREEN},
        {"SINISEID", BLUE},
    };
    
    string command;
    char temp;
    int shirtL, shirtR, start, end, i;
    for (int j = 0; j < queryAmount; j++) {
		cin >> command  >> shirtL >> shirtR;
        start = shirtL - 1;
        end = shirtR - 1;

        switch(mappedTask[command]) {
            case FLIP:
                flip(start, end, shirts);
                break;
            case FRONT:
                for (i = 0; i < end - start + 1; i++) {
                    temp = shirts[i];
                    shirts[i] = shirts[start + i];
                    shirts[start + i] = temp;
                }
                break;
            case BACK:
                for (i = 0; i < end - start + 1; i++) {
                    temp = shirts[start + i];
                    shirts[start + i] = shirts[start + i + (shirtAmount - shirtR)];
                    shirts[start + i + (shirtAmount - shirtR)] = temp;
                }
                break;
            case RED:
                colorCounter(start, end, shirts, 'P', shirtAmount);
                break;
            case GREEN:
                colorCounter(start, end, shirts, 'R', shirtAmount);
                break;
            case BLUE:
                colorCounter(start, end, shirts, 'S', shirtAmount);
                break;
        };
    }
}