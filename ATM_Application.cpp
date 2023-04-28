#include <iostream>
using namespace std;

/* 
Our ATM application must be able to:  
1. Check the balance
2. Deposit money
3. Withdraw money
4. Transfer money
5 - Exit
*/
void showMenu(){
    cout << "---------- MENU ----------" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Make a deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Transfer Money" << endl;
    cout << "5. Exit" << endl;
    cout << "--------------------------" << endl;
}
int main()
{
    int option;
    double balance = 5000;
    cout << "Hello! Welcome to the ATM!" << endl;
    showMenu();
    do {
        cout << "What do you want to do? ";
        cin >> option;
        while (option > 5 || option < 1){
            cout << "Invalid! Please try again... ";
            cin >> option;
        }
        // system("cls");
        switch (option)
        {
        case 1:
            cout << "Your balance is: $" << balance << endl;
            break;
        case 2:
            double depositAmount;
            cout << "Please enter how much you want to deposit: $";
            cin >> depositAmount;
            balance += depositAmount; cout << "You deposited $" << depositAmount <<". Your balance is $" << balance << endl; break;
        case 3:
            double withdrawAmount;
            cout << "Please enter how much you want to withdraw: $";
            cin >> withdrawAmount;
            if (withdrawAmount <= balance){
                balance -= withdrawAmount;
                cout << "You withdrew $" << withdrawAmount <<". Your balance is $" << balance << endl; break;
            }
            else
                cout << "Not enough money!" << endl;
// I could have initiated a while loop to keep asking for withdraw amount even after displaying "Not enough money!"
// By initiating an if-else statement, I stop asking again after displaying "Not enough money!" remark once.
        case 4:
            double balance1;
            double balance2;
            double transferAmount;
            cout << "How much do you want to transfer? ";
            cin >> transferAmount;
            if (true){
                balance1 = balance;
                balance1 -= transferAmount;
                balance2+= transferAmount;
                cout << "Account 1 has transferred $" << transferAmount << " to Account 2." << endl;
                cout << "Account 1 balance is $" << balance1 << endl; 
                cout << "Account 2 balance is $" << balance2 << endl; break;
            }else{
                balance2 = balance;
                balance1 += transferAmount;
                balance2 -= transferAmount;
                cout << "Account 2 has transferred $" << transferAmount << " to Account 1." << endl;
                cout << "Account 2 balance is $" << balance2 << endl;
                cout << "Account 1 balance is $" << balance1 << endl; break;
            }
        /*case 5:
            exit(0);        
        default:
            break; */
        }
    } while (option != 5);
    if (option == 5){
        cout << "Thank you!" << endl;
        exit(0);
    }
    return 0;
}
