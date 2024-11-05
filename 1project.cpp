#include <iostream>
#include <string>
#include <cctype>

using namespace std;


bool isValidCreditCard(const string& cardNumber) {
    int sum = 0;
    bool alternate = false;

    
    for (int i = cardNumber.length() - 1; i >= 0; --i) {
    
        if (!isdigit(cardNumber[i])) {
            return false;
        }

        int digit = cardNumber[i] - '0';

        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9; 
            }
        }

        sum += digit;
        alternate = !alternate;
    }

 
    return (sum % 10 == 0);
}

int main() {
    string cardNumber;

    
    cout << "==============================\n";
    cout << "  Credit Card Validator Tool  \n";
    cout << "==============================\n\n";

    
    cout << "Please enter your credit card number: ";
    cin >> cardNumber;

    cout << "\nValidating your credit card number...\n\n";

    
    if (isValidCreditCard(cardNumber)) {
        cout << "-----------------------------------\n";
        cout << "  Result: Valid credit card number \n";
        cout << "-----------------------------------\n";
    } else {
        cout << "-------------------------------------\n";
        cout << "  Result: Invalid credit card number \n";
        cout << "-------------------------------------\n";
    }

   
    cout << "\nThank you for using the Credit Card Validator Tool.\n";
    cout << "===============================================\n";

    return 0;
}
