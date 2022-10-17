#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

long squares;
long specials;
int main(void) {
    cin >> squares >> specials;
    map<int, int> specialMap;

    int key, value;
    for (int i = 0; i < specials; i++) {
        cin >> key >> value;
        specialMap.insert(pair<int, int>(key, value));
    }

    // TODO graph
}