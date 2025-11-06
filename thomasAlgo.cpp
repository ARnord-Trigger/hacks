#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double lower[4], mainD[4], upper[4], rhs[4], sol[4];

    cout << "Enter the coefficients for the tridiagonal system:\n";

    // Equation 1
    lower[1] = 0;
    cout << "Equation 1 (b1 c1 d1): ";
    cin >> mainD[1] >> upper[1] >> rhs[1];

    // Equation 2
    cout << "Equation 2 (a2 b2 c2 d2): ";
    cin >> lower[2] >> mainD[2] >> upper[2] >> rhs[2];

    // Equation 3
    cout << "Equation 3 (a3 b3 d3): ";
    cin >> lower[3] >> mainD[3] >> rhs[3];
    upper[3] = 0;

    // Forward elimination
    for (int i = 2; i <= 3; i++) {
        double ratio = lower[i] / mainD[i - 1];
        mainD[i] -= ratio * upper[i - 1];
        rhs[i] -= ratio * rhs[i - 1];
    }

    // Back substitution
    sol[3] = rhs[3] / mainD[3];
    for (int i = 2; i >= 1; i--) {
        sol[i] = (rhs[i] - upper[i] * sol[i + 1]) / mainD[i];
    }

    // Display result
    cout << fixed << setprecision(3);
    cout << "\nSolution:\n";
    cout << "x1 = " << sol[1] << endl;
    cout << "x2 = " << sol[2] << endl;
    cout << "x3 = " << sol[3] << endl;

    return 0;
}
