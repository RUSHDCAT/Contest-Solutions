#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
string name1, name2;
int inc0, inc1;
double f;
int main() {
	cin >> name1 >> inc0 >> name2 >> f >> inc1;
	double x = inc0 * f;
	if (abs(x - inc1) < 1e-8) {
		cout << "Whatever" << endl;
	} else if (x + 1e-8 < inc1) {
		cout << "Evolve, Power up" << endl;
	} else {
		cout << "Power up, Evolve" << endl;
	}
}