#include <iostream>
#include <string>
#include <map>

using namespace std;

enum Task {
    FLIP, FRONT, BACK, RED, GREEN, BLUE
};

void colorCounter(int start, int end, char *arr, char color, int size) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        char col = arr[i];
        if (arr[i] == color) count++;
    }
    cout << count << endl;
}

void flip(int start, int end, char *arr) {
    for (int low = start, high = end; low < high; low++, high--) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
}

void shift_left(char arr[], int size, int numTimes) {
    while (numTimes) {
        char temp = arr[0];
        arr[size - 1] = temp;
        for (int i = 0; i < (size - 1); i++) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = temp;
        numTimes--;
    }

}

void shift_right(char arr[], int size, int numTimes) {
    while (numTimes) {
        char temp = arr[size - 1];
        arr[size - 1] = temp;
        for (int i = size - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
        numTimes--;
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
    
    for (int j = 0; j < queryAmount; j++) {
    	string command;
    	int shirtL, shirtR, start, end;
		cin >> command  >> shirtL >> shirtR;
        start = shirtL - 1;
        end = shirtR - 1;


        switch(mappedTask[command]) {
            case FLIP:
                flip(start, end, shirts);
                break;
            case FRONT:
                for (int i = 0; i < end - start + 1; i++) {
                    char temp = shirts[i];
                    shirts[i] = shirts[start + i];
                    shirts[start + i] = temp;
                }
                break;
            case BACK:
                for (int i = 0; i < end - start + 1; i++) {
                    char temp = shirts[start + i];
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