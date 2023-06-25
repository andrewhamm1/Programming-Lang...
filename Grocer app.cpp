#include <iostream> 
#include <fstream> 
#include <string> 
#include <map> 

using namespace std;

class FrequencyData {
public:
	// Reading the file data then storing it in the object
	void readDataFromFile(const string& fileName) {
		ifstream inputFile(fileName); // Open the input file

		string itemName;
		int itemCount;

		// Reading input file and store the item names and counts in the map
		while (inputFile >> itemName >> itemCount) {
			data[itemName] += itemCount;
		}

		inputFile.close(); // Close the input file
	}

	int getItemFrequency(const string& itemName) {
		return data[itemName];
	}

	void printAllItems() {
		for (auto& item : data) {
			cout << item.first << " " << item.second << endl;
		}
	}

	void printHistogram() {
		for (auto& item : data) {
			cout << item.first << " ";
			for (int i = 0; i < item.second; i++) {
				cout << "*";
			}
			cout << endl;
		}
	}

	void writeDataToFile(const string& fileName) {
		ofstream outputFile(fileName); // Open the output file
		for (auto& item : data) {
			outputFile << item.first << " " << item.second << endl;
		}

		outputFile.close(); // Close the output file
	}

private:
	map<string, int> data; // Store the item names and counts in a map
};

// Function to display the menu options and get user input
int displayMenuAndGetInput() {
	int input;
	cout << "\nMenu Options:" << endl;
	cout << "1. Get the frequency of a specific item" << endl;
	cout << "2. Print the frequency of all items" << endl;
	cout << "3. Print a histogram of item frequency" << endl;
	cout << "4. Exit the program" << endl;
	cout << "Enter your choice: ";
	cin >> input; // Get the user input
	return input;
}

int main() {
	FrequencyData frequencyData;

	frequencyData.readDataFromFile("InventoryList.txt");

	int input = displayMenuAndGetInput();

	// Loop until the user selects the "Exit" option
	while (input != 4) {
		switch (input) {
		case 1: {

			// Get the name of the item and display its frequency
			string itemName;
			cout << "Enter the name of the item: ";
			cin >> itemName;
			int frequency = frequencyData.getItemFrequency(itemName);
			cout << "Frequency of " << itemName << ": " << frequency << endl;
			break;
		}

		case 2: {
			// Print the frequency of all items
			frequencyData.printAllItems();
			break;
		}
		case 3: {
			// Print a histogram of item frequency
			frequencyData.printHistogram();
			break;
		}
		default: {
			cout << "Invalid choice" << endl;
			break;
		}
		}

		// Display the menu and get user input again
		input = displayMenuAndGetInput();
	}

	frequencyData.writeDataToFile("frequency.dat");

	return 0;
}

