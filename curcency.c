#include <stdio.h>

int main() {
    double usd_amount, eur_amount;
    const double usd_to_eur_rate = 0.85;

    printf("Enter amount in USD: ");
    scanf("%lf", &usd_amount);

    eur_amount = usd_amount * usd_to_eur_rate;

    printf("%.2lf USD = %.2lf EUR\n", usd_amount, eur_amount);

    return 0;
}
