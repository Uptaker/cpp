#include <iostream>

using namespace std;

class Logger {
    static inline Logger* instance;
    string prevMessage;

    Logger() {}

    public:
    static Logger* getLogger() {
        if (instance == NULL) instance = new Logger();
        return instance;
    }

    void log(string message) {
        prevMessage = message;
        cout << message << endl;
    }

    string getPrev() {
        return prevMessage;
    }

};


int main(void) {
    Logger* logger1 = Logger::getLogger();
    logger1->log("Test");

    cout << "Should have two 'Test' logs" << endl;
    cout << logger1->getPrev() << endl;

    Logger* logger2 = Logger::getLogger();
    cout << logger2->getPrev() << endl;


}
