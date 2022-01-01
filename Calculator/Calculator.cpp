#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ios>
#include <limits>
#include <utility>

void clearInputBuffer();
int mainMenu();
double getNumber();
void getNumbers(std::vector <double>& nums);
char getOperation();
int getStatisticalAverage();
int getEquationType();
double factorial(double a);
std::pair <double, double> calculateRootsOfQuadratic(double a, double b, double discriminant);

int main() {
	std::cout << "Welcome to my calculator!\n";
	while(true) {
		int function{ mainMenu() };
		if(function == 1) {
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
		} else if(function == 2) {
			int statisticalAverage{ getStatisticalAverage() };
			if(statisticalAverage == 1) {
				std::vector <double> nums;
				getNumbers(nums);
				double sum{ 0 };

				for(double x : nums) {
					sum += x;
				}
				std::cout << "The mean is " << sum / nums.size() << '\n';
			} else if(statisticalAverage == 2) {
				std::vector <double> nums;
				getNumbers(nums);
				sort(nums.begin(), nums.end());
				if(nums.size() % 2) {
					std::cout << "The median is: " << nums[nums.size() / 2] << '\n';
				} else {
					std::cout << "The median is: " << (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2 << '\n';
				}
			} else if(statisticalAverage == 3) {
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
			} else {
				return 0;
			}
			clearInputBuffer();
		} else {
			int equationType{ getEquationType() };
			if(equationType == 1) {
				std::cout << "Make sure the equation is in the form ax^2 + bx + c = 0\n";
				std::cout << "Enter a, b, and c:\n";
				double a, b, c;

				while(!(std::cin >> a >> b >> c)) {
					std::cout << "Please enter numbers for a, b, and c.\n";
					clearInputBuffer();
				}
				double discriminant{ b * b - 4 * a * c };
				std::pair <double, double> x{ calculateRootsOfQuadratic(a, b, discriminant).first, calculateRootsOfQuadratic(a, b, discriminant).second };
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
}

void clearInputBuffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int mainMenu() {
	int input;
	std::cout << "\n1. Arithmetic mode\n2. Statistical average mode\n3. Equation solver mode\n4. Quit\n\n";
	std::cout << "Enter your choice: ";

	while(!(std::cin >> input) || (input != 1 && input != 2 && input != 3 && input != 4)) {
		std::cout << "Invalid Input! Please try again: ";
		clearInputBuffer();
	}
	return input;
}

double getNumber() {
	double input;
	std::cout << "Enter a number: ";

	while(!(std::cin >> input)) {
		std::cout << "Invalid Input! Please try again: ";
		clearInputBuffer();
	}
	return input;
}

void getNumbers(std::vector <double>& nums) {
	char input;
	double num;
	std::cout << "Enter the numbers (q to stop entering numbers):\n";
	
	while(true) {
		std::cin >> input;
		if(input == 'q') {
			break;
		} else {
			std::cin.putback(input);
			if(!(std::cin >> num)) {
				std::cout << "Invalid Input! Please try again:\n";
				clearInputBuffer();
			} else {
				nums.push_back(num);
			}
		}
	}
}

char getOperation() {
	char input;
	std::cout << "Enter an operator (+, -, *, /, ^, !, or %): ";

	while(std::cin >> input && (input != '+' && input != '-' && input != '*' && input != '/' && input != '^' && input != '!' && input != '%')) {
		std::cout << "Invalid Input! Please try again: ";
		clearInputBuffer();
	}
	return input;
}

int getStatisticalAverage() {
	int input;
	std::cout << "\n1. Mean\n2. Median\n3. Mode\n\n";
	std::cout << "Enter your choice: ";

	while(!(std::cin >> input) || (input != 1 && input != 2 && input != 3)) {
		std::cout << "Invalid Input! Please try again: ";
		clearInputBuffer();
	}
	return input;
}

int getEquationType() {
	int input;
	std::cout << "\n1. Quadratic\n\n";
	std::cout << "Enter your choice: ";

	while(!(std::cin >> input) || (input != 1)) {
		std::cout << "Invalid Input! Please try again: ";
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

std::pair <double, double> calculateRootsOfQuadratic(double a, double b, double discriminant) {
	if(discriminant > 0) {
		return std::make_pair((-b + sqrt(discriminant)) / (2 * a), (-b - sqrt(discriminant)) / (2 * a));
	} else if(!discriminant) {
		return std::make_pair(-b / (2 * a), 0);
	} else {
		return std::make_pair(-b / (2 * a), sqrt(-discriminant) / (2 * a));
	}
}