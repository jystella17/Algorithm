#include <iostream>
#define n_ 55
using namespace std;

int n;
int arr[n_];
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	if (n == 1) {
		printf("A\n");
		return 0;
	}

	if (n == 2) {
		if (arr[0] == arr[1]) {
			printf("%d\n", arr[0]);
			return 0;
		}
		else {
			printf("A\n");
			return 0;
		}
	}

	if (arr[0] == arr[1]) {
		bool chk = true;
		for (int i = 0; i < n; i++) {
			if (arr[i] != arr[0]) {
				chk = false;
			}
		}
		if (chk) {
			printf("%d\n", arr[0]);
			return 0;
		}
		else {
			printf("B\n");
			return 0;
		}
	}

	if ((arr[2] - arr[1]) % (arr[1] - arr[0]) != 0) {
		printf("B\n");
		return 0;
	}
	int a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
	int b = arr[1] - arr[0] * a;
	//cout << a << " " << b << endl;

	for (int i = 0; i < n - 1; i++) {
		if (arr[i] * a + b != arr[i + 1]) {
			printf("B\n");
			return 0;
		}
	}

	printf("%d\n", a * arr[n - 1] + b);
	return 0;
}
