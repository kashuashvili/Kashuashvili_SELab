#include <iostream>
#include <cmath>
#include <limits>
#include <sstream>
using namespace std;

void checkValidInput() {
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        throw runtime_error("Invalid input! Please enter valid numbers.");
    }
}
int checkValidN(int n) {
    
    if (n <= 2) {
        throw runtime_error("Invalid input! Please enter valid numbers.");
    }
    return n;
}
double checkH(double h) {
    if (h <= 0) {
        throw runtime_error("Invalid input! Please enter positive value");
    }
    return h;
}
void checkRerun(char rerun) {
    if (!isalpha(rerun)) {
        throw runtime_error("Invalid input! Please enter 'y' or 'n'.");
    }
    if ( (rerun != 'y' && rerun != 'n' && rerun != 'Y' && rerun != 'N')) {
        throw runtime_error("Invalid input! Please enter 'y' or 'n'.");
    }
}
double checkRange(double a, double b) {
    if (b <= a) {
        throw runtime_error("Invalid input! Please enter positive value");
    }
    return b;
}
double calculateNoRange(int n, double x) {
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
double calculateWithRange(int n, double a, double b, double h) {
    double y, result = 0;
    for (double x = a; x <= b; x += h) {
        y = 0;
        if (x < 0) {
            for (int i = 1; i <= n; i++) {
                y += pow((x + i), 2);
            }
            y += 5 * x;
        }
        else {
            double p = 1;
            for (int i = 0; i <= n; i++) {
                for (int j = 1; j <= n - 1; j++) {
                    p *= (i + (pow(x, 2) / (i + j)) - 3 * j);
                }
                y += p;
            }
        }
        cout << " x = " << x << "; y = " << y << endl;
        result += y;
    }
    return result;
} 

int main() {
    bool repeat_program = true;
    while (repeat_program) {
        try {
            int n, range;
            double x, y = 0;
            string input_n;
            cout << "Do you want to use range? (1 if yes / 0 if no): ";
            cin >> range;
            checkValidInput();

            if (range == 0) {
                cout << "Enter the value of n (>2), n = ";
                cin >> n;
                checkValidN(n);

                cout << "Enter the value of x, x = ";
                cin >> x;
                checkValidInput();

                y = calculateNoRange(n, x);
                cout << "y = " << y << endl;
            }
            else if (range == 1) {
                double a, b, h;

                cout << "Enter the value of n (>2), n = ";
                cin >> n;

                try {
                    n = checkValidN(n);
                }
                catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << endl;
                    continue;
                }

                cout << "Enter the value of starting x (a): ";
                cin >> a;
                checkValidInput();

                cout << "Enter the value of last x (b): ";
                cin >> b;
                checkRange(a, b);

                cout << "Enter the value of step (h): ";
                cin >> h;
                checkH(h);

                calculateWithRange(n, a, b, h);
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
        try {
            checkRerun(rerun);
            if (rerun == 'n' || rerun == 'N') {
                repeat_program = false;
                cout << "THE END" << endl;
            }
            else if (rerun == 'y' || rerun == 'Y') {
                repeat_program = true;
            }
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            repeat_program = false; 
        }
        }
        return 0;
   
}