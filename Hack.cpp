#include <iostream>

bool enableHacks() {
    std::cout << "Enable hacks (type 1 or 0)?\n";
    bool enableHacks;
    std::cin >> enableHacks;

    return enableHacks;
}

bool disableHacks() {
    std::cout << "Disable hacks (type 1 or 0)?\n";
    bool disableHacks;
    std::cin >> disableHacks;

    return disableHacks;
}

int placesToHack() {
    std::cout << "Who would you like to hack?\n";
    std::cout << "Type 1 to hack the CIA\n";
    std::cout << "Type 2 to hack the FBI\n";
    std::cout << "Type 3 to hack the NSA\n";
    std::cout << "Type 4 to hack the Bank of America\n";
    int placeToHack{ 0 };
    std::cin >> placeToHack;

    return placeToHack;
}

void hackCIA() {
    std::cout << "The CIA has been hacked!\n";
}

void hackFBI() {
    std::cout << "The FBI has been hacked!\n";
}

void hackNSA() {
    std::cout << "The NSA has been hacked!\n";
}

void hackBankOfAmerica() {
    std::cout << "The Bank of America has been hacked!\n";
}

int main() {
    bool hacksEnabled{ enableHacks() };

    if(hacksEnabled) {
        int placeToHack{ placesToHack() };
        do {
            switch (placeToHack) {
            case 1:
                hackCIA();
                break;
            case 2:
                hackFBI();
                break;
            case 3:
                hackNSA();
                break;
            case 4:
                hackBankOfAmerica();
                break;
            }

            hacksEnabled = disableHacks();

            if(hacksEnabled == 1) {
                std::cout << "Shutting down hacks...\n";
                break;
            }
            placeToHack = placesToHack();
        } while(!hacksEnabled);
    }

    return 0;
}