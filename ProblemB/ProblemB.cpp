#include <iostream>

using namespace std;

int main()
{

	int q, n;

	cin >> q;

	while (q--) {

		cin >> n;

		char z;

		char **a = new char *[n];
		for (int i = 0; i < n; i++) {
			a[i] = new char[n];
		}

		char **b = new char *[n];
		for (int i = 0; i < n; i++) {
			b[i] = new char[n];
		}

		for (int i = 0; i < n; i++) {
			for (int x = 0; x < n; x++) {
				cin >> z;
				a[i][x] = z;
			}
		}

		char v;

		while (true) {

			cin >> v;

			if (v == '&') {
				break;
			}

			if (v == 'T') { //transpozycja wzgledem glownej przekatnej
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						b[x][i] = a[i][x];
					}
				}
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						a[i][x] = b[i][x];
					}
				}
			}
			else if (v == 'D') { //transpozycja wzgledem drugiej przekatnej
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						b[n - x - 1][n - i - 1] = a[i][x];
					}
				}
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						a[i][x] = b[i][x];
					}
				}
			}
			else if (v == 'H') { //odbicie poziome
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						b[i][n - x - 1] = a[i][x];
					}
				}
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						a[i][x] = b[i][x];
					}
				}
			}
			else if (v == 'V') { //odbicie pionowe
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						b[n - i - 1][x] = a[i][x];
					}
				}
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						a[i][x] = b[i][x];
					}
				}
			}
			else if (v == 'A' || v == 'Z') { //obrót o 90 stopni w prawo || obrót o 270 stopni w lewo
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						b[x][n - i - 1] = a[i][x];
					}
				}
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						a[i][x] = b[i][x];
					}
				}
			}
			else if (v == 'B' || v == 'Y') { //obrot w prawo o 180 stopni || obrot w lewo o 180 stopni
				for (int k = 0; k < 2; k++) {
					for (int i = 0; i < n; i++) {
						for (int x = 0; x < n; x++) {
							b[x][n - i - 1] = a[i][x];
						}
					}
					for (int i = 0; i < n; i++) {
						for (int x = 0; x < n; x++) {
							a[i][x] = b[i][x];
						}
					}
				}
			}
			else if (v == 'C' || v == 'X') { //obrót w prawo o 270 stopni || obrot w lewo o 90 stopni
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						b[n - x - 1][i] = a[i][x];
					}
				}
				for (int i = 0; i < n; i++) {
					for (int x = 0; x < n; x++) {
						a[i][x] = b[i][x];
					}
				}
			}

		}

		for (int i = 0; i < n; i++) {
			for (int x = 0; x < n; x++) {
				cout << a[i][x];
			}
			cout << endl;
		}

	}

}