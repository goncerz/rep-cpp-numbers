#include <iostream>
using namespace std;

int main(void) {
	const int k = 9;
	int n;
	int nmax = pow(10, k);
	int tmp;
	int r;
	int holes = 0;
	bool firstZero = true;

	cout << "Program liczy ile dziur jest w liczbie." << endl;
	cout << "Cyfra 8 ma 2 dziury, cyfry 0, 4, 6 i 9 maja po jednej dziurze, a cyfry 1, 2, 3, 5 i 7 nie maja dziur." << endl << endl;

	do {
		cout << "Podaj liczbe n ( n >= 1 oraz n <= " << nmax << " ): ";
		cin >> n;
	} while (n < 1 || n > nmax);

	tmp = n;

	for (int i = 0; i <= k; i++) {
		r = tmp / pow(10, k - i);

		if (firstZero && r == 0) {
			continue;
		}
		else {
			firstZero = false;
		}

		if (r == 8) {
			holes += 2;
		}
		else if (r == 0 || r == 4 || r == 6 || r == 9) {
			holes++;
		}

		tmp -= r * pow(10, k - i);
	}

	cout << "W liczbie " << n << " jest " << holes << " dziur." << endl;

	return 0;
}