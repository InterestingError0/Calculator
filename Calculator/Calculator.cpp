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
	double input;
	std::cout << "Enter a number: ";

	while(!(std::cin >> input)) {
		std::cout << "Please enter a number.\n";
		clearInputBuffer();
	}
	return input;
}

char getOperationFromUser() {
	char input;
	std::cout << "Enter an operator (+, -, *, /, ^, !, or %): ";

	while(std::cin >> input && (input != '+' && input != '-' && input != '*' && input != '/' && input != '^' && input != '!' && input != '%')) {
		std::cout << "Please enter a valid operator\n";
		clearInputBuffer();
	}
	return input;
}

std::string getStatisticalAverageFromUser() {
	std::string input;
	std::cout << "Enter a statistical average (e.g., mean, median): ";
	std::cin >> input;
	std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return static_cast <char>(std::tolower(c)); });
	while(std::cin && (input != "mean" && input != "median")) {
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
		char mode;
		std::cout << "Enter 'a' to enter arithmetic mode, 's' to enter statistical average (mean/median) mode, or 'q' to quit: ";

		while(!(std::cin >> mode) || (mode != 'a' && mode != 's' && mode != 'q')) {
			std::cout << "Please enter 'a','s', or 'q'.\n";
			clearInputBuffer();
		}
		if(mode == 'q') {
			return 0;
		} else if(mode == 'a') {
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

			if(statisticalAverage == "mean") {
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
			} else if(statisticalAverage == "median") {
				std::vector <double> numbers;
				std::cout << "Enter the numbers you would like to find the median of (q to stop entering numbers): \n";

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