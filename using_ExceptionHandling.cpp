#include <iostream>

using namespace std;

int divide(int x, int y) {
    if (y == 0) {
        throw exception(); // Throw an exception if y is 0
    }

    return x / y;
}

int main() {
    try {
        int result = divide(10, 0); // Will throw an exception
        cout << "Result: " << result << endl;
    } catch (exception& e) {
        cout << "Error: Division by zero" << endl;
    }

    return 0;
}

//friend function
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
