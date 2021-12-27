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

char mainMenu() {
	char mode;
	std::cout << "Enter 'a' to enter arithmetic mode, 's' to enter statistical average (mean/median/mode) mode, or 'q' to quit: ";

	while(!(std::cin >> mode) || (mode != 'a' && mode != 's' && mode != 'q')) {
		std::cout << "Please enter 'a','s', or 'q'.\n";
		clearInputBuffer();
	}
	return mode;
}

double getNumber() {
	double input;
	std::cout << "Enter a number: ";

	while(!(std::cin >> input)) {
		std::cout << "Please enter a number.\n";
		clearInputBuffer();
	}
	return input;
}

void getNumbers(std::vector <double>& nums) {
	double input;
	std::cout << "Enter the numbers (q to stop entering numbers): \n";
	while(std::cin >> input) {
		nums.push_back(input);
	}
}

char getOperation() {
	char input;
	std::cout << "Enter an operator (+, -, *, /, ^, !, or %): ";

	while(std::cin >> input && (input != '+' && input != '-' && input != '*' && input != '/' && input != '^' && input != '!' && input != '%')) {
		std::cout << "Please enter a valid operator\n";
		clearInputBuffer();
	}
	return input;
}

std::string getStatisticalAverage() {
	std::string input;
	std::cout << "Enter a statistical average (mean, median, or mode): ";
	std::cin >> input;
	std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return static_cast <char>(std::tolower(c)); });
	while(std::cin && (input != "mean" && input != "median" && input != "mode")) {
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
		char function{ mainMenu() };
		if(function == 'q') {
			return 0;
		} else if(function == 'a') {
			double firstNumber{ getNumber() };
			char operation{ getOperation() };
			double secondNumber{ 0 };

			if(operation != '!') {
				secondNumber = getNumber();
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
			std::string statisticalAverage{ getStatisticalAverage() };

			if(statisticalAverage == "mean") {
				std::vector <double> nums;
				getNumbers(nums);
				double sum{ 0 };

				for(double x : nums) {
					sum += x;
				}
				std::cout << "The mean is " << sum / nums.size() << '\n';
			} else if(statisticalAverage == "median") {
				std::vector <double> nums;
				getNumbers(nums);
				sort(nums.begin(), nums.end());

				if(nums.size() % 2) {
					std::cout << "The median is: " << nums[nums.size() / 2] << '\n';
				} else {
					std::cout << "The median is: " << (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2 << '\n';
				}
			} else {
				std::vector <double> nums;
				getNumbers(nums);
				sort(nums.begin(), nums.end());
				double mode{ 0 };
				double element{ nums[0] };
				int noOfOccurrencesOfMode{ 0 };
				int noOfElement{ 0 };

				for(int i{ 0 }; i < nums.size(); i++) {
					if(nums[i] == element) {
						noOfElement++;
					} else {
						if(noOfElement > noOfOccurrencesOfMode) {
							mode = element;
							noOfOccurrencesOfMode = noOfElement;
							noOfElement = 1;
						}
						element = nums[i];
					}
				}
				if(noOfElement > noOfOccurrencesOfMode) {
					mode = element;
				}
				std::cout << "The mode is: " << mode << '\n';
			}
			clearInputBuffer();
		}
	}
}