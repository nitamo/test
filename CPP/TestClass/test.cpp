#include <iostream>
#include <cwchar>
#include "test.h"

using namespace std;

wchar_t test::message[] = L"Hello World!";

void test::printMessage() {
	wcout << message;
}

void swap_ord(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_point(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_ref(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	test::printMessage();
	
	int a = 3;
	int b = 5;

	cout << "Swapping numbers...\n";
	cout << "a = " << a << ',' << "b = " << b << endl;
	cout << "Swapping ordinary...\n";
	swap_ord(a, b);
	cout << "a = " << a << ',' << "b = " << b << endl;
	cout << "Swappingy using pointers...\n";
	swap_point(&a, &b);
	cout << "a = " << a << ',' << "b = " << b << endl;
	cout << "Swapping using references...\n";
	swap_ref(a, b);
	cout << "a = " << a << ',' << "b = " << b << endl;
	
	return 0;
}
