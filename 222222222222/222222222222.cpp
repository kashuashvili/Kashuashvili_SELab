#include <iostream>
#include <cmath>  
//yooo
using namespace std;

int main() {
    bool repeat_program = true;
    while (repeat_program) {
        bool start;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Enter  either 1 or 0" << endl;
        }
        while (true) {
            int n, range;
            double x, y = 0;
            cout << "Do you want to use range? (1 if yes / 0 if no): ";
            cin >> range;

            if (cin.fail() || (range != 0 && range != 1)) {
                cout << "Error: Invalid input! Please enter either 1 or 0." << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            if (range == 0) {
                while (true) {
                    cout << "Enter the value of n (>2), n = ";
                    cin >> n;
                    if (cin.fail() || n <= 2) {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input of n. Try again: " << endl;
                    }
                    else {
                        break;
                    }
                }
                while (true) {
                    cout << "Enter the value of x, x = ";
                    cin >> x;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Value of x has to be a number. Try again: " << endl;
                    }
                    else {
                        break;
                    }
                }
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

                cout << "y = " << y << endl;
                break;
            }
            else if (range == 1) {
                double a, b, h;

                while (true) {
                    cout << "Enter the value of n (>2), n = ";
                    cin >> n;
                    if (cin.fail() || n <= 2) {
                        cin.clear();
                        cin.ignore();
                        cout << "Value of n has to be an integer >= 2. Try again: " << endl;
                    }
                    else {
                        break;
                    }
                }

                while (true) {
                    cout << "Enter the value of starting x (a): ";
                    cin >> a;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Value of a has to be a number. Try again: " << endl;
                    }
                    else {
                        break;
                    }
                }
             
                while (true) {
                    cout << "Enter the value of last x (b): ";
                    cin >> b;
                    if (cin.fail() || b <= a) {
                        cin.clear();
                        cin.ignore();
                        cout << "Value of b has to be a number greater than a. Try again " << endl;
                    }
                    else {
                        break;
                    }
                }

                while (true) {
                    cout << "Enter the value of step (h): ";
                    cin >> h;
                    if (cin.fail() || h < 0) {
                        cin.clear();
                        cin.ignore();
                        cout << "Value of h can't be negative. Try again: " << endl;
                    }
                    else {
                        break;
                    }
                }
                if (h > 0) {
                    for (double x = a; x < b; x += h) {
                        if (x < 0) {
                            y = 0;
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
                        cout << "x = " << x << ", y = " << y << endl;
                    } }
                if (h == 0) {
                    if (double x = a)   {
                        if (x < 0) {
                            y = 0;
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
                        cout << "x = " << x << ", y = " << y << endl;
                    }
                }
                break;
            } }

        char rerun;
        cout << "Do you want to run the program again? (y/n): ";
        cin >> rerun;

        if (rerun == 'n' || rerun == 'N') {
            repeat_program = false;
            cout << "THE END" << endl;
        }
        else if (rerun == 'y' || rerun == 'Y') {
            repeat_program = true;
        }
        else {
            cout << "Invalid input. THE END" << endl;
            repeat_program = false;
        }
    }}