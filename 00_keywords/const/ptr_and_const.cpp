void test() {
	int a = 1;
	int b = 2;

	const int* p1 = &a; // const decorates *p1
	// *p1 = b; // error: *p1 cannot be modified
	p1 = &b;

	int* const p2 = &a; // const decorates p2
	// p2 = &b; // error: p2 cannot be modified
	*p2 = b;
}

int main() {
	test();
	return 0;
}
