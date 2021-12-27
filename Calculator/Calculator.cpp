#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ios>
#include <limits>

int mainMenu() {
	int input{ 0 };

	do {
		std::cout << "Enter 1 to enter arithmetic mode. Enter 2 to enter statistical average (e.g., mean, median) mode: ";
		std::cin >> input;

		if(input != 1 && input != 2) {
			std::cout << "Please enter either 1 or 2.\n";
		}
	} while(input != 1 && input != 2);

	return input;
}

double getNumberFromUser() {
	double input{};
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter a number: ";
	std::cin >> input;

	return input;

}

char getOperationFromUser() {
	char input{};
	do {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter an operator (+, -, *, /, ^, !, or %): ";
		std::cin >> input;

		if(input != '+' && input != '-' && input != '*' && input != '/' && input != '^' && input != '!' && input != '%') {
			std::cout << "Please enter a valid operator\n";
		}
	} while(input != '+' && input != '-' && input != '*' && input != '/' && input != '^' && input != '!' && input != '%');

	return input;
}

std::string getStatisticalAverageFromUser() {
	std::string input{ ' ' };
	do {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter a statistical average (e.g., mean, median): ";
		std::cin >> input;

		if(input != "mean" && input != "median") {
			std::cout << "Please enter a valid statistical average\n";
		}
	} while(input != "mean" && input != "median");

	return input;
}

double factorial(double a) {
	if(a == 0) {
		return 1;
	} else if(a == 1) {
		return 1;
	} else {
		return factorial(a - 1) * a;
	}
}

int main() {
	for(;;) {
		int mode{ mainMenu() };

		switch(mode) {
		case 1:
		{
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
					break;
				} else {
					std::cout << "Illegal operation! Cannont divide by 0.\n\n";
					break;
				}
			case '^':
				std::cout << firstNumber << " ^ " << secondNumber << " = " << pow(firstNumber, secondNumber) << "\n\n";
				break;
			case '!':
				std::cout << firstNumber << "! = " << factorial(firstNumber) << "\n\n";
				break;
			case '%':
				if(secondNumber) {
					std::cout << firstNumber << "% of " << secondNumber << " = " << firstNumber / 100 * secondNumber << "\n\n";
					break;
				} else {
					std::cout << firstNumber << "% = " << firstNumber / 100 << "\n\n";
				}
			}
			break;
		}
		case 2:
		{
			std::string statisticalAverage{ getStatisticalAverageFromUser() };
			int statisticalAverageToInt{ 0 };

			if(statisticalAverage == "mean" || statisticalAverage == "Mean") {
				statisticalAverageToInt = 1;
			} else if(statisticalAverage == "median" || statisticalAverage == "Median") {
				statisticalAverageToInt = 2;
			}

			switch(statisticalAverageToInt) {
			case 1:
			{
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
				break;
			}
			case 2:
			{
				std::vector <double> numbers;
				std::cout << "Enter the numbers you would like to find the mean of (q to stop entering numbers): \n";
				for(double number{ 0 }; std::cin >> number;) {
					numbers.push_back(number);
				}

				sort(numbers.begin(), numbers.end());

				if(!(numbers.size() % 2)) {
					std::cout << "The median is: " << (numbers[numbers.size() / 2 - 1 ] + numbers[numbers.size() / 2 ] ) / 2 << '\n';
				} else {
					std::cout << "The median is: " << numbers[numbers.size() / 2] << '\n';
				}
				break;
			}
			}
			break;
		}
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
