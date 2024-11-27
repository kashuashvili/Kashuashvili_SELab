#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

void checkValidInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        throw runtime_error("Invalid input detected! Please enter valid numbers.");
    }
}
void checkValidParams(int n) {
    if (n <= 2) {
        throw runtime_error("Invalid value for n. It must be greater than 2.");
    }
}
double calculate(int n, double x) {
    double y = 0;
    if (x < 0) {
        for (int i = 1; i <= n; i++) {
            y += pow((x + i), 2);
        }
        y += 5 * x;
    }
    else {
        y = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= n - 1; j++) {
                y *= (i + (pow(x, 2) / (i + j)) - 3 * j);
            }
        }
    }
    return y;
}

int main() {
    bool repeat_program = true;
    while (repeat_program) {
        try {
            int n, range;
            double x, y = 0;

            cout << "Do you want to use range? (1 if yes / 0 if no): ";
            cin >> range;
            checkValidInput();

            if (range == 0) {
                cout << "Enter the value of n (>2), n = ";
                cin >> n;
                checkValidInput();
                checkValidParams(n);

                cout << "Enter the value of x, x = ";
                cin >> x;
                checkValidInput();

                y = calculate(n, x);
                cout << "y = " << y << endl;
            }
            else if (range == 1) {
                double a, b, h;

                cout << "Enter the value of n (>2), n = ";
                cin >> n;
                checkValidInput();
                checkValidParams(n);

                cout << "Enter the value of starting x (a): ";
                cin >> a;
                checkValidInput();

                cout << "Enter the value of last x (b): ";
                cin >> b;
                checkValidInput();
                if (b <= a) throw runtime_error("Value of b must be greater than a.");

                cout << "Enter the value of step (h): ";
                cin >> h;
                checkValidInput();
                if (h <= 0) throw runtime_error("Step size h must be positive.");

                for (double x = a; x <= b; x += h) {
                    y = calculate(n, x);
                    cout << "x = " << x << ", y = " << y << endl;
                }
            }
            else {
                throw runtime_error("Invalid option for range! Please enter 1 or 0.");
            }
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        char rerun;
        cout << "Do you want to run the program again? (y/n): ";
        cin >> rerun;

        if (rerun == 'n' || rerun == 'N') {
            repeat_program = false;
            cout << "THE END" << endl;
        }
        else if (rerun != 'y' && rerun != 'Y') {
            cout << "Invalid input. THE END" << endl;
            repeat_program = false;
        }
    }
    return 0;
}
