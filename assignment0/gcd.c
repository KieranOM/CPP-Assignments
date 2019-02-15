// A function to return the greatest common divisor
int gcd(int a, int b) {
	// Makes the input values positive using the ternary operator for Task 2
	a = a > 0 ? a : -a;
	b = b > 0 ? b : -b;
	// Input checks
	if (a == 0 && b == 0)
		return 0;
	else if (a == 0)
		return b;
	else if (b == 0)
		return a;
	// Euclidean  algorithm
	while(a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
