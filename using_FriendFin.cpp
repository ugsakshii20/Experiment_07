#include <iostream>

using namespace std;

class Data {
private:
    int value;

public:
    Data(int value) : value(value) {}

    friend void validateData(Data& data) {
        if (data.value < 0) {
            throw invalid_argument("Data value cannot be negative");
        }
    }

    void print() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    try {
        Data data(-10); // Data value is negative
        validateData(data);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
