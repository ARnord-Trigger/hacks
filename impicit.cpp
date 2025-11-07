#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n = 5;
    double alpha = 0.01, dx = 1.0, dt = 0.25;
    double r = alpha * dt / (dx * dx);

    double a[5], b[5], c[5], d[5], T[5];

    // Initial temperature
    for (int i = 0; i < n; i++) T[i] = 0;
    T[0] = 100; T[n - 1] = 0;

    // Tridiagonal coefficients
    for (int i = 1; i < n - 1; i++) {
        a[i] = -r; b[i] = 1 + 2 * r; c[i] = -r;
    }

    cout << "Implicit Heat Equation Solution:\n";

    // Time steps
    for (int step = 1; step <= 10; step++) {
        // Right-hand side (previous temps)
        for (int i = 1; i < n - 1; i++) d[i] = T[i];

        // Apply boundary conditions
        d[1] += r * T[0];
        d[n - 2] += r * T[n - 1];

        // Thomas Algorithm (Forward elimination)
        for (int i = 2; i < n - 1; i++) {
            double m = a[i] / b[i - 1];
            b[i] -= m * c[i - 1];
            d[i] -= m * d[i - 1];
        }

        // Back substitution
        T[n - 2] = d[n - 2] / b[n - 2];
        for (int i = n - 3; i >= 1; i--) {
            T[i] = (d[i] - c[i] * T[i + 1]) / b[i];
        }

        // Keep boundary conditions
        T[0] = 100; T[n - 1] = 0;

        cout << "Step " << step << ": ";
        for (int i = 0; i < n; i++) cout << fixed << setprecision(2) << T[i] << " ";
        cout << endl;
    }
}
