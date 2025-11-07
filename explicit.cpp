#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n = 5; // Number of grid points
    double alpha = 0.01, dx = 1.0, dt = 0.25;
    double r = alpha * dt / (dx * dx);

    double T[5], Tnew[5];

    // Initial condition: rod at 0°C, left end = 100°C, right end = 0°C
    for (int i = 0; i < n; i++) T[i] = 0;
    T[0] = 100; T[n - 1] = 0;

    cout << "Initial Temp:\n";
    for (int i = 0; i < n; i++) cout << T[i] << " ";
    cout << "\n\n";

    // Time iterations
    for (int step = 1; step <= 10; step++) {
        for (int i = 1; i < n - 1; i++) {
            Tnew[i] = T[i] + r * (T[i + 1] - 2 * T[i] + T[i - 1]);
        }

        // Boundary conditions remain same
        Tnew[0] = 100;
        Tnew[n - 1] = 0;

        // Update temperature
        for (int i = 0; i < n; i++) T[i] = Tnew[i];

        cout << "Step " << step << ": ";
        for (int i = 0; i < n; i++) cout << fixed << setprecision(2) << T[i] << " ";
        cout << endl;
    }
}
