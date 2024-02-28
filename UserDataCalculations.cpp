#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "UserDataCalculations.hpp"

void UserDataCalculations::dataWithoutDeposits(InvestmentData t_userInvestment) {

    double initialInvestment = t_userInvestment.getInitialInvestment();
    int years = t_userInvestment.getNumOfYears();

    int screenWidth = 80;
    string balanceMsg = "Balance and Interest Without Additional Monthly Deposits";
    int centerScreen = screenWidth / 2 - balanceMsg.length() / 2;

    int halfWidth = screenWidth / 2;
    int sizeToCenter = halfWidth + centerScreen;

    cout << endl;

    cout << setfill(' ') << setw(sizeToCenter) << balanceMsg << setfill(' ') << setw(sizeToCenter) << endl;
    cout << setfill('=') << setw(82) << '=' << endl;
    cout << setfill(' ') << left << setw(26) << "Year" << "Year End Balance" << right << setw(40) << "Year End Earned Interest" << endl;
    cout << setfill('-') << setw(82) << '-' << endl;

    t_userInvestment.setTotalWithoutDeposits(initialInvestment);
    double interestYTD = 0;

    unsigned int yearCount, monthCount;

    for (yearCount = 1; yearCount <= years; yearCount++) {
        for (monthCount = 1; monthCount <= 12; monthCount++) {
            interestYTD += t_userInvestment.calcInterestWithoutDeposits();
        }
        t_userInvestment.setTotalWithoutDeposits(interestYTD);
        
        cout << setfill(' ') << left << setw(30) << yearCount;
        cout << "$" << fixed << setprecision(2) << t_userInvestment.getTotalWithoutDeposits();
        cout << right << setw(35) << "$" << fixed << setprecision(2) << interestYTD << endl;

        interestYTD = 0;
    }
}

void UserDataCalculations::dataWithDeposits(InvestmentData t_userInvestment) {

    double initialInvestment = t_userInvestment.getInitialInvestment();
    double monthlyDeposit = t_userInvestment.getMonthlyDeposit();
    int years = t_userInvestment.getNumOfYears();

    string balanceMsg = "Balance and Interest With Additional Monthly Deposits";
    int screenWidth = 80;

    int centerScreen = balanceMsg.length() / 2;
    int halfWidth = screenWidth / 2;
    int sizeToCenter = halfWidth + centerScreen;

    cout << endl;

    cout << setfill(' ') << setw(sizeToCenter) << balanceMsg << setfill(' ') << setw(sizeToCenter) << endl;
    cout << setfill('=') << setw(82) << '=' << endl;
    cout << setfill(' ') << left << setw(26) << "Year" << "Year End Balance" << right << setw(40) << "Year End Earned Interest" << endl;
    cout << setfill('-') << setw(82) << '-' << endl;

    t_userInvestment.setTotalWithDeposits(initialInvestment);

    double interestYTD = 0;

    unsigned int yearCount, monthCount;

    for (yearCount = 1; yearCount <= years; yearCount++) {
        for (monthCount = 1; monthCount <= 12; monthCount++) {
            t_userInvestment.setTotalWithDeposits(monthlyDeposit);
            double interest = t_userInvestment.calcInterestWithDeposits();
            t_userInvestment.setTotalWithDeposits(interest);
            interestYTD += interest;
        }

        cout << setfill(' ') << left << setw(26) << yearCount;
        cout << "$" << fixed << setw(37) << setprecision(2) << t_userInvestment.getTotalWithDeposits();
        cout << left << "$" << fixed << setprecision(2) << interestYTD << endl;

        interestYTD = 0;
    }
}
