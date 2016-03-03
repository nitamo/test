#include <iostream>
#include <cwchar>
#include "test.h"

using namespace std;

wchar_t test::message[] = L"Hello World!";

void test::printMessage() {
	wcout << message;
}

int main() {
	test::printMessage();
	return 0;
}
