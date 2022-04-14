#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "Airgead.h"

using namespace std;

int main() {

	Investment invest;
	invest.inputData();
	system("pause");
	invest.printReport();
	system("pause");

	return 0;
}