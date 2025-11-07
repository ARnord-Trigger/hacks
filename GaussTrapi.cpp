#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
int n = 3;
double h = 0.5;
vector<double> x = {0.0, 0.5, 1.0};
auto g = [](double val) {
return (1.5 * val) - (5.0 / 6.0);
};
vector<vector<double>> A(n, vector<double>(n, 0.0));
vector<double> b(n);
for (int i = 0; i < n; i++) {
A[i][i] = 1.0;
A[i][0] -= (h / 2.0) * (x[i] + x[0]);
A[i][1] -= h * (x[i] + x[1]);
A[i][2] -= (h / 2.0) * (x[i] + x[2]);
b[i] = g(x[i]);
}
// Forward elimination
for (int i = 0; i < n; i++) {
double pivot = A[i][i];
for (int j = i; j < n; j++) A[i][j] /= pivot;
b[i] /= pivot;
for (int k = i + 1; k < n; k++) {
double factor = A[k][i];
for (int j = i; j < n; j++) A[k][j] -= factor * A[i][j];
b[k] -= factor * b[i];
}
}
// Backward substitution
vector<double> f(n);
for (int i = n - 1; i >= 0; i--) {
f[i] = b[i];
for (int j = i + 1; j < n; j++)
f[i] -= A[i][j] * f[j];
}
cout << fixed << setprecision(6);
for (int i = 0; i < n; i++)
cout << "f(t" << i << ") = " << f[i] << endl;
return 0;
}
