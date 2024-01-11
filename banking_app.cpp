// Purpose: Banking app to deposit, withdraw and show balance.




#include<iostream>
#include <iomanip>


double deposit();
void showBalance(double balance);
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;
    do
    {
    std::cout << "******************\n";
    std::cout << "Enter your choice: \n";
    std::cout << "******************\n";
    std::cout << "1. Show Money\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Exit!\n";
    std::cin >> choice;
    
    std::cin.clear();       // comment and type characters
    fflush(stdin);

    switch (choice)
    {
    case 1:
        showBalance(balance);
        break;
    
    case 2:
        balance += deposit();
        showBalance(balance);
        break;

    case 3:
        balance -= withdraw(balance);
        showBalance(balance);
        break;

    case 4:
        std::cout << "Thank you for visiting!\n";
        break;

    default:
        std::cout << "Invalid choice\n";
        break;
    }
    } while (choice!=4);
    
    
    return 0;
}

double deposit(){
    double amount = 0;
    std::cout << "How much you want to deposit? \n";
    std::cin >> amount;
    if(amount > 0){
        return amount;
    }else{
        std::cout << "That's not the valid amount.\n";
        return 0;
    }
}
void showBalance(double balance){
    std::cout << "Your balance is $" << std::setprecision(2) << std::fixed << balance << std::endl;
}
double withdraw(double balance){
    double amount = 0;
    std::cout << "How much you want to withdraw? \n";
    std::cin >> amount;
    if(amount > balance){
        std::cout << "Error! Insufficient funds.\n";
        return 0;
    }else if(amount < 0){
        std::cout << "Invalid amount.\n";
        return 0;
    }else{
        return amount;
    }
}