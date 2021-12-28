#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ios>
#include <limits>
#include <utility>

void clearInputBuffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char mainMenu() {
	char input;
	std::cout << "Enter 'a' to enter arithmetic mode, 's' to enter statistical average (mean/median/mode) mode, "
		"'e' to enter equation solver mode, or 'q' to quit : ";

	while(!(std::cin >> input) || (input != 'a' && input != 's' && input != 'q' && input != 'e')) {
		std::cout << "Please enter 'a', 's', 'q', or 'e'.\n";
		clearInputBuffer();
	}
	return input;
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
		std::cout << "Please enter a valid operator.\n";
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
		std::cout << "Please enter a valid statistical average.\n";
		clearInputBuffer();
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return static_cast <char>(std::tolower(c)); });
	}
	return input;
}

std::string getEquationType() {
	std::string input;
	std::cout << "Enter the equation type: ";
	std::cin >> input;
	std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return static_cast <char>(std::tolower(c)); });

	while(input != "quadratic") {
		std::cout << "Please enter a valid equation type.\n";
		clearInputBuffer();
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return static_cast <char>(std::tolower(c)); });
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

std::pair <double, double> calculateRootsOfQuadratic(double a, double b, double discriminant) {
	if(discriminant > 0) {
		return std::make_pair((-b + sqrt(discriminant)) / (2 * a), (-b - sqrt(discriminant)) / (2 * a));
	} else if(!discriminant) {
		return std::make_pair(- b / (2 * a), 0);
	} else {
		return std::make_pair(-b / (2 * a), sqrt(-discriminant) / (2 * a));
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
		} else if(function == 's') {
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
		} else {
			std::string equationType{ getEquationType() };

			std::cout << "Make sure the equation is in the form ax^2 + bx + c = 0\n";
			std::cout << "Enter a, b, and c:\n";
			double a, b, c;

			while(!(std::cin >> a >> b >> c)) {
				std::cout << "Please enter numbers for a, b, and c\n";
				clearInputBuffer();
			}
			double discriminant{ b * b - 4 * a * c };
			std::pair <double, double> x = { calculateRootsOfQuadratic(a, b, discriminant).first, calculateRootsOfQuadratic(a, b, discriminant).second };

			if(discriminant > 0) {
				std::cout << "x1 = " << x.first << " x2 = " << x.second << '\n';
			} else if(!discriminant) {
				std::cout << "x = " << x.first << '\n';
			} else {
				std::cout << "x1 = " << x.first << " + " << x.second << "i\n";
				std::cout << "x2 = " << x.first << " - " << x.second << "i\n";
			}
		}
	}
}