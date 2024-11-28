#include <stdio.h>
#include <math.h>

void generateLoanRepaymentSchedule(double principalAmount, double annualRate, int termInYears)
{

    double monthlyRate = annualRate / 100 / 12;
    int totalMonths = termInYears * 12;

    double monthlyInstallment = principalAmount * monthlyRate /
                                (1 - pow(1 + monthlyRate, -totalMonths));

    printf("Monthly Installment: %.2f\n\n", monthlyInstallment);
    printf("Repayment Details:\n");
    printf("Month No - Principal Paid - Interest Paid - Monthly Installment - Remaining Debt\n");

    double balanceLeft = principalAmount;

    for (int month = 1; month <= totalMonths; month++)
    {

        double interestPayment = balanceLeft * monthlyRate;

        double principalPayment = monthlyInstallment - interestPayment;

        balanceLeft -= principalPayment;

        if (balanceLeft < 0)
        {
            balanceLeft = 0;
        }

        printf("%9d - %14.2f - %13.2f - %18.2f - %14.2f\n",
               month,
               principalPayment,
               interestPayment,
               monthlyInstallment,
               balanceLeft);
    }
}

int main()
{
    double principalAmount;
    double annualInterestRate;
    int repaymentTermInYears;

   
    printf("Enter the loan principal amount: ");
    scanf("%lf", &principalAmount);
    printf("Enter the annual interest rate (%%): ");
    scanf("%lf", &annualInterestRate);
    printf("Enter the number of years to repay: ");
    scanf("%d", &repaymentTermInYears);

    generateLoanRepaymentSchedule(principalAmount, annualInterestRate, repaymentTermInYears);

    return 0;
}
