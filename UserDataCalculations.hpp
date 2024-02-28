#pragma once

#ifndef AIRGEADBANKING_USERDATACALCULATIONS_HPP_
#define AIRGEADBANKING_USERDATACALCULATIONS_HPP_

#include "InvestmentData.hpp"

class UserDataCalculations {
public:
    void dataWithoutDeposits(InvestmentData t_userInvestment);
    void dataWithDeposits(InvestmentData t_userInvestment);
};

#endif
