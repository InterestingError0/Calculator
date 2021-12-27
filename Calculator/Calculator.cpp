#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ios>
#include <limits>

void clearInputBuffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getNumberFromUser() {
	double input{};
	std::cout << "Enter a number: ";

	while(!(std::cin >> input)) {
		std::cout << "Please enter a number.\n";
		clearInputBuffer();
	}
	return input;
}

char getOperationFromUser() {
	char input{};
	std::cout << "Enter an operator (+, -, *, /, ^, !, or %): ";

	while(std::cin >> input && (input != '+' && input != '-' && input != '*' && input != '/' && input != '^' && input != '!' && input != '%')) {
		std::cout << "Please enter a valid operator\n";
		clearInputBuffer();
	}
	return input;
}

std::string getStatisticalAverageFromUser() {
	std::string input{};
	std::cout << "Enter a statistical average (e.g., mean, median): ";

	while(std::cin >> input && (input != "mean" && input != "median")) {
		std::cout << "Please enter a valid statistical average\n";
		clearInputBuffer();
	}
	return input;
}

double factorial(double a) {
	if(a == 0) {
		return 1;
	} else {
		return factorial(a - 1) * a;
	}
}

int main() {
	for(;;) {
		int mode{};
		std::cout << "Enter 1 to enter arithmetic mode. Enter 2 to enter statistical average (mean/median) mode: ";

		while(!(std::cin >> mode) || (mode != 1 && mode != 2)) {
			std::cout << "Please enter either 1 or 2.\n";
			clearInputBuffer();
		}

		if(mode == 1) {
			double firstNumber{ getNumberFromUser() };
			char operation{ getOperationFromUser() };
			double secondNumber{ 0 };

			if(operation != '!') {
				secondNumber = getNumberFromUser();
			}
			switch(operation) {
			case '+':
				std::cout << firstNumber << " + " << secondNumber << " = " << firstNumber + secondNumber << "\n\n";
				break;
			case '-':
				std::cout << firstNumber << " - " << secondNumber << " = " << firstNumber - secondNumber << "\n\n";
				break;
			case '*':
				std::cout << firstNumber << " * " << secondNumber << " = " << firstNumber * secondNumber << "\n\n";
				break;
			case '/':
				if(secondNumber) {
					std::cout << firstNumber << " / " << secondNumber << " = " << firstNumber / secondNumber << "\n\n";
				} else {
					std::cout << "Illegal operation! Cannont divide by 0.\n\n";
				}
				break;
			case '^':
				std::cout << firstNumber << " ^ " << secondNumber << " = " << pow(firstNumber, secondNumber) << "\n\n";
				break;
			case '!':
				std::cout << firstNumber << "! = " << factorial(firstNumber) << "\n\n";
				break;
			case '%':
				if(secondNumber) {
					std::cout << firstNumber << "% of " << secondNumber << " = " << firstNumber / 100 * secondNumber << "\n\n";
				} else {
					std::cout << firstNumber << "% = " << firstNumber / 100 << "\n\n";
				}
				break;
			}
		} else {
			std::string statisticalAverage{ getStatisticalAverageFromUser() };

			if(statisticalAverage == "mean" || statisticalAverage == "Mean") {
				std::vector <double> numbers;
				std::cout << "Enter the numbers you would like to find the mean of (q to stop entering numbers): \n";

				for(double number{ 0 }; std::cin >> number;) {
					numbers.push_back(number);
				}
				double sum{ 0 };

				for(double x : numbers) {
					sum += x;
				}
				std::cout << "The mean is " << sum / numbers.size() << '\n';
			} else if(statisticalAverage == "median" || statisticalAverage == "Median") {
				std::vector <double> numbers;
				std::cout << "Enter the numbers you would like to find the mean of (q to stop entering numbers): \n";

				for(double number{ 0 }; std::cin >> number;) {
					numbers.push_back(number);
				}
				sort(numbers.begin(), numbers.end());

				if(numbers.size() % 2) {
					std::cout << "The median is: " << numbers[numbers.size() / 2] << '\n';
				} else {
					std::cout << "The median is: " << (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2 << '\n';
				}
			}
			clearInputBuffer();
		}
	}
}