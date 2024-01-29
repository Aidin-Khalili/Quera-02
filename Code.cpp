#include<iostream>

bool prime(long int);
using namespace std;
int main()
{
	long int n, k, i, j;
	long int a[100];
	long int b[100][2];
	for (i = 0; i < 100; i++) {
		b[i][0] = 0;
		b[i][1] = 0;
	}
	cin >> n;
	k = 0;
	i = 2;
	if (n <= 1)
		return 0;
	if (prime(n)) {
		cout << n;
		return 0;
	}
	while (n > 0 && i <= n) {
		if (n % i == 0 && prime(i)) {
			n = n / i;
			a[k] = i;
			k++;
		}
		else
			i++;
	}

	j = 0;
	b[j][1] = a[0];
	b[j][0] = 0;
	for (i = 0; i < k; i++) {
		if (b[j][1] == a[i])
			b[j][0] += 1;
		else {
			j++;
			b[j][1] = a[i];
			b[j][0] = 1;
		}
	}
	/*	for (i = j; i > 0; i--){
			if (b[i][0] > 1)
				cout << b[i][0] << "^";
			cout << b[i][1] << "*";
		}
		if (b[0][0] > 1)
			cout << b[0][0] << "^";
		cout << b[0][1] ;*/
	cout << b[0][1];
	if (b[0][0] > 1)
		cout << "^" << b[0][0];

	for (i = 1; i <= j; i++) {
		cout << "*";
		cout << b[i][1];
		if (b[i][0] > 1)
			cout << "^" << b[i][0];
	}

	return 0;
}
bool prime(long int a)
{
	long int i;
	for (i = 2; i <= a / 2; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}