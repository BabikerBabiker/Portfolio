// @Author Babiker Babiker
// @Date 01/23/2024
// @Details Currency Converter [Accurate as of 01/23/2024]
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

class CurrencyConverter {
private:
	double sourceRate;
	double resultRate;
	double resultAmt;
	string source;
	string result;
	double amount;
	double CR;

	void computeRates(const string& currency, double& rate, const double defaultRate) {
		if (currency == "USD") {
			rate = defaultRate;
		}
		else if (currency == "EUR") {
			rate = 0.92;
		}
		else if (currency == "JPY") {
			rate = 148.24;
		}
		else if (currency == "GBP") {
			rate = 0.79;
		}
		else if (currency == "AUD") {
			rate = 1.52;
		}
		else if (currency == "CAD") {
			rate = 1.35;
		}
		else if (currency == "CHF") {
			rate = 0.87;
		}
		else if (currency == "CNH") {
			rate = 7.19;
		}
		else if (currency == "HKD") {
			rate = 7.82;
		}
		else {
			rate = 1.64;
		}
	}
public:
	CurrencyConverter() {
		this->resultAmt = 0.00;
		this->amount = 0.00;
		this->sourceRate = 0.00;
		this->resultRate = 0.00;
		this->CR = 0.00;
	}

	void supported() {
		cout << "Supported Currencies"
			<< "\n------------------------"
			<< "\n- USD\n- EUR\n- JPY\n- GBP\n- AUD\n- CAD\n- CHF\n- CNH\n- HKD\n- NZD" << endl;
		cout << "\nPress [ENTER] to go back to main menu.";

		cin.ignore();
		cin.ignore();
	}

	void convertMenu() {
		bool isValidInput = false;
		do {
			cout << "Enter the amount: ";
			cin >> this->amount;

			if (this->amount <= 0) {
				system("cls");
				cout << "[ERROR] Amount cannot be 0 or less." << endl;
				continue;
			}

			cout << "\nEnter the Source Currency [Example: USD]: ";
			cin >> this->source;

			if (checkSupported(source) == false) {
				system("cls");
				cout << "[ERROR] Unsupported Source Currency.\n" << endl;
			}
			else {
				cout << "\nEnter the Target Currency [Example: GBP]: ";
				cin >> this->result;

				if (checkSupported(result) == false) {
					system("cls");
					cout << "[ERROR] Unsupported Target Currency.\n" << endl;
				}
				else {
					isValidInput = true;
					break;
				}
			}
		} while (!isValidInput);

		getRates();
		compute();
		print();

		cin.ignore();
		cin.ignore();
	}

	bool checkSupported(string source) {
		if (source == "USD" || source == "EUR" || source == "JPY" || source == "GBP" || source == "AUD" ||
			source == "CAD" || source == "CHF" || source == "CNH" ||source == "HKD" || source == "NZD")
			return true;
		return false;
	}

	void getRates() {
		this->computeRates(source, sourceRate, 1.0);
		this->computeRates(result, resultRate, 1.0);
		this->CR = this->resultRate / this->sourceRate;
	}

	void compute() {
		this->resultAmt = CR * this->amount;
	}

	void print() const {
		cout << fixed << setprecision(2);
		cout << endl << this->amount << " " << this->source << " = " 
			<< this->resultAmt << " " << this->result << endl << endl;
		cout << "Press [ENTER] to go back to menu.";
	}

	~CurrencyConverter(){
	}
};

int main() {
	CurrencyConverter* converter = new CurrencyConverter();

	int choice = 0;
	do {
		cout << "[DISCLAIMER] ALL INFORMATION IS ACCURATE AS OF 01/23/2024." << endl;
		cout << "[1] View Supported Currencies"
			<< "\n[2] Make A Conversion"
			<< "\n[3] Exit Program"
			<< endl << endl;

		cin >> choice;

		if (choice <= 0 || choice > 3) {
			system("cls");
			cout << "[ERROR] input must be 1, 2, or 3." << endl << endl;
			continue;
		}

		switch (choice) {
		case 1:
			system("cls");
			converter->supported();
			system("cls");
			continue;
		case 2:
			system("cls");
			converter->convertMenu();
			system("cls");
			continue;
		case 3:
			for (int i = 0; i < 3; ++i) {
				system("cls");
				std::cout << "Exiting";

				for (int j = 0; j <= i; ++j) {
					std::cout << ".";
				}

				std::cout.flush();
				Sleep(500);
			}
			exit(3);
		}
	} while (choice != 3);

	delete converter;
	return 0;
}