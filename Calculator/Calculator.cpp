#include <iostream>
#include <cmath>

double getInputFromUser() {
	double input{};
	std::cout << "Enter a number: ";
	std::cin >> input;

	return input;

}

char getOperationFromUser() {
	char input{};
	do {
		std::cout << "Enter an operator (+, -, *, /, ^, !, or %): ";
		std::cin >> input;

		if (input != '+' && input != '-' && input != '*' && input != '/' && input != '^' && input != '!' && input != '%') {
			std::cout << "Please enter a valid operator\n";
		}
	} while (input != '+' && input != '-' && input != '*' && input != '/' && input != '^' && input != '!' && input != '%');

	return input;
}

double add(double a, double b) {
	return a + b;
}

double subtract(double a, double b) {
	return a - b;
}

double multiply(double a, double b) {
	return a * b;
}

double divide(double a, double b) {
	if (b != 0) {
		return a / b;
	} else {
		std::cout << "Illegal operation! Cannont divide by 0.\n\n";
		return 0;
	}
}

double exponent(double a, double b) {
	return pow(a, b);
}

double factorial(double a) {
	if (a == 0) {
		return 1;
	} else if (a == 1) {
		return 1;
	} else {
		return factorial(a - 1) * a;
	}
}

double percent(double a) {
	return a / 100;
}

double percentof(double a, double b) {
	return a / 100 * b;
} 

int main() {

	for (;;) {

		double firstNumber{ getInputFromUser() };
		char operation{ getOperationFromUser() };
		double secondNumber{ 0 };
		if (operation != '!') {
			secondNumber = getInputFromUser();
		}

		switch (operation) {
		case '+':
			std::cout << firstNumber << " + " << secondNumber << " = " << add(firstNumber, secondNumber) << "\n\n";
			break;
		case '-':
			std::cout << firstNumber << " - " << secondNumber << " = " << subtract(firstNumber, secondNumber) << "\n\n";
			break;
		case '*':
			std::cout << firstNumber << " * " << secondNumber << " = " << multiply(firstNumber, secondNumber) << "\n\n";
			break;
		case '/':
			if (secondNumber) {
				std::cout << firstNumber << " / " << secondNumber << " = " << divide(firstNumber, secondNumber) << "\n\n";
				break;
			} else {
				divide(firstNumber, secondNumber);
				break;
			}
		case '^':
			std::cout << firstNumber << " ^ " << secondNumber << " = " << exponent(firstNumber, secondNumber) << "\n\n";
			break;
		case '!':
			std::cout << firstNumber << "! = " << factorial(firstNumber) << "\n\n";
			break;
		case '%':
			if (secondNumber) {
				std::cout << firstNumber << "% of " << secondNumber << " = " << percentof(firstNumber, secondNumber) << "\n\n";
				break;
			} else {
				std::cout << firstNumber << "% = " << percent(firstNumber) << "\n\n";
			}
		} 
	}
}
