#include "io.h"

int main()
{
	int firstNumber{ readNumber() };
	int secondNumber{ readNumber() };

	writeAnswer(firstNumber + secondNumber);

	return 0;
}
