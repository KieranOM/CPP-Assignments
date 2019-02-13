// A function to return the greatest common divisor
int gcd(int a, int b) {
	// Makes the input values positive using the ternary operator for Task 2
	a = a > 0 ? a : -a;
	b = b > 0 ? b : -b;
	// Euclidean  algorithm
	while(a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
