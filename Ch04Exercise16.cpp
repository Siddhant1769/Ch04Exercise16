#include <iostream>
#include <iomanip>
using namespace std;

// Constants for royalty options
const double FIXED_DELIVERY_PAYMENT = 5000.0;
const double FIXED_PUBLICATION_PAYMENT = 20000.0;
const double ROYALTY_RATE_OPTION2 = 0.125;
const double ROYALTY_RATE_OPTION3_FIRST = 0.10;
const double ROYALTY_RATE_OPTION3_SECOND = 0.14;
const int OPTION3_THRESHOLD = 4000;

double calculateOption1() {
    return FIXED_DELIVERY_PAYMENT + FIXED_PUBLICATION_PAYMENT;
}

double calculateOption2(double netPrice, int copiesSold) {
    return ROYALTY_RATE_OPTION2 * netPrice * copiesSold;
}

double calculateOption3(double netPrice, int copiesSold) {
    if (copiesSold <= OPTION3_THRESHOLD) {
        return ROYALTY_RATE_OPTION3_FIRST * netPrice * copiesSold;
    } else {
        double firstPart = ROYALTY_RATE_OPTION3_FIRST * netPrice * OPTION3_THRESHOLD;
        double secondPart = ROYALTY_RATE_OPTION3_SECOND * netPrice * (copiesSold - OPTION3_THRESHOLD);
        return firstPart + secondPart;
    }
}

int main() {
    double netPrice;
    int copiesSold;

    // Prompt user for input
    cout << "Enter the net price of each copy of the novel: $";
    cin >> netPrice;
    cout << "Enter the estimated number of copies that will be sold: ";
    cin >> copiesSold;

    // Calculate royalties
    double royalty1 = calculateOption1();
    double royalty2 = calculateOption2(netPrice, copiesSold);
    double royalty3 = calculateOption3(netPrice, copiesSold);

    // Display results
    cout << fixed << setprecision(2);
    cout << "\nEstimated Royalties:\n";
    cout << "Option 1: $" << royalty1 << endl;
    cout << "Option 2: $" << royalty2 << endl;
    cout << "Option 3: $" << royalty3 << endl;

    // Determine best option
    double bestRoyalty = max(royalty1, max(royalty2, royalty3));
    string bestOption;

    if (bestRoyalty == royalty1) {
        bestOption = "Option 1";
    } else if (bestRoyalty == royalty2) {
        bestOption = "Option 2";
    } else {
        bestOption = "Option 3";
    }

    cout << "\nThe best option for the author is: " << bestOption << endl;

    return 0;
}

