/*
Cooper Ring
CS-210
2/11/24
 */

#include <iostream>
#include <iomanip>
#include "InvestmentData.hpp"
#include "UserDataCalculations.hpp"

void dataInterface() {
    InvestmentData userInvestment;
    UserDataCalculations dataCalculations;

    double initialAmount, monthlyDeposit, interest;
    int years;
    char choice;
    bool contRunning = true;

    do {
        std::cout << std::setfill('*') << std::setw(36) << '*' << '\n';
        std::cout << "  " << "*\t" << "         Data Input        " << "\t *" << '\n';
        std::cout << std::setfill('-') << std::setw(36) << '-' << '\n';

        std::cout << "Initial Investment Amount: $";
        std::cin >> initialAmount;
        std::cout << "Monthly Deposit: $";
        std::cin >> monthlyDeposit;
        std::cout << "Annual Interest: %";
        std::cin >> interest;
        std::cout << "Number of years: ";
        std::cin >> years;

        userInvestment.setInitialInvestment(initialAmount);
        userInvestment.setMonthlyDeposit(monthlyDeposit);
        userInvestment.setAnnualInterest(interest);
        userInvestment.setNumOfYears(years);
        
        std::cout << "\nInitial Investment Amount: $" << userInvestment.getInitialInvestment() << std::endl;
        std::cout << "\nMonthly Deposit: $" << userInvestment.getMonthlyDeposit() << std::endl;
        std::cout << "\nAnnual Interest: %" << userInvestment.getAnnualInterest() << std::endl;
        std::cout << "\nNumber of years: " << userInvestment.getNumOfYears() << "y" << std::endl;


        std::cout << '\n';

        try {
            dataCalculations.dataWithoutDeposits(userInvestment);
        } catch (const std::exception& exc) {
            std::cerr << exc.what() << '\n';
            std::cerr << "error occurred with dataWithoutDeposits\n";
            contRunning = false;
        }

        try {
            dataCalculations.dataWithDeposits(userInvestment);
        } catch (const std::exception& exc) {
            std::cerr << exc.what() << '\n';
            std::cerr << "error occurred with dataWithDeposits\n";
            contRunning = false;
        }

        std::cout << '\n';

        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
        contRunning = (choice == 'y');

    } while (contRunning);
}

int main() {
    try {
        dataInterface();
        std::cout << "Goodbye!\n";
    } catch (const std::exception& exc) {
        std::cerr << exc.what() << '\n';
        std::cerr << "error occurred with dataInterface\n";
        std::system("pause");
    }
}

