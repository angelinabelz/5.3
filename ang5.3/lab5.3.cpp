#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double p(const double x);

int main() {
    double gp, gk;
    int n;

    cout << "gp = ";
    cin >> gp;
    cout << "gk = ";
    cin >> gk;
    cout << "n = ";
    cin >> n;

    double dg = (gk - gp) / n;
    double g = gp;

    cout << setw(1) << "|" << setw(3) << "k" << setw(3) << "|"
        << setw(4) << "z" << setw(2) << "|" << endl;
    cout << "-------------" << endl;

    while (g <= gk + dg / 2) {
        double z = p(1 - g * g) + pow(p(1 + g - sqrt(p(g))), 2);
        cout << "|" << setw(5) << fixed << setprecision(3) << g
            << "|" << setw(4) << fixed << setprecision(1) << z << "|" << endl;
        g += dg;
    }

    cout << "-------------" << endl;

    return 0;
}

double p(const double x) {
    if (abs(x) >= 1) {
        return (cos(sin(x)) + 1) / (exp(-x) + 1);
    }
    else {
        double S = 0;
        double a = 1;
        int j = 0;
        S = a;
        do {
            j++;
            double R = -x * x / ((3 * j - 2) * (3 * j - 1) * 3 * j);
            a *= R;
            S += a;
        } while (j < 4);
        return S;
    }
}
