#include<iostream>
int add(int a, int b) {
	while (b) {
		int temp = a ^ b;
		b = (a & b) << 1;
		a = temp;
	}
	return a;
}
int subs(int a, int b) {
	return add(a, add(~b, 1));
}

int negative(int a) {
	return add(~a, 1);
}

int multi(int a, int b) {
	int res = 0;
	int x = a < 0 ? negative(a) : a;
	int y = b < 0 ? negative(b) : b;
	while (y) {
		if ((y & 1) == 1) {
			res = add(res, x);
		}
		x = x << 1;
		y = y >> 1;
	}
	return res;
}
int main() {
	int a = 1;
	int c = 11;
	int d = 13;
	int ans = add(a, c);
	int ans1 = subs(d, c);
	printf("%d", multi(c, d));
	printf("%d %d", ans, ans1);
	return 0;
}