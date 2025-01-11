#include <stdio.h>
void displayStatement(int balance) {
    printf("Transaction Statement:\n");
    printf("Account No: 2400044\n");
    printf("Total Balance: %d\n", balance);
}
void checkBalance(int balance) {
    printf("Current Balance: %d\n", balance);
}
void creditAmount(int *balance, int *amount) {
    *balance += *amount;
    printf("Credited: %d\n", *amount);
    displayStatement(*balance);
}
void debitAmount(int *balance, int *amount) {
    if (*balance >= *amount) {
        *balance -= *amount;
        printf("Debited: %d\n", *amount);
        displayStatement(*balance);
    } else {
        printf("Insufficient balance.\n");
    }
}
int main() {
    int newAmount;
    printf("Enter amount: ");
    scanf("%d", &newAmount);
    int initialAmount = 100;
    int accountNo = 2400044;
    int choose;
    printf("1. Credit\n");
    printf("2. Debit\n");
    printf("3. Check Balance\n");
    printf("4. Display Statement\n");
    printf("Enter your choice: ");
    scanf("%d", &choose);
    switch (choose) {
        case 1:
            printf("Amount will credit\n");
            creditAmount(&initialAmount, &newAmount);
            break;
        case 2:
            printf("Amount will debit\n");
            debitAmount(&initialAmount, &newAmount);
            break;
        case 3:
            printf("You want to check balance\n");
            checkBalance(initialAmount);
            break;
        case 4:
            displayStatement(initialAmount);
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}