#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class StringChangeCalculator {
    int _total_bc_values = 12;
    string _bc_names[12] = {
        "ONE HUNDRED",
        "FIFTY",
        "TWENTY",
        "TEN",
        "FIVE",
        "TWO",
        "ONE",
        "HALF DOLLAR",
        "QUARTER",
        "DIME",
        "NICKEL",
        "PENNY"
    };
    
    // the values were multiplied by one hundred to avoid using floating
	// point numbers, they were causing various approximation errors.
    int _bc_values[12] = {
        10000, 
        5000, 
        2000, 
        1000, 
        500, 
        200, 
        100, 
        50, 
        25, 
        10, 
        5, 
        1 
    };
    
public:
    string run(double, double);
};

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            size_t sc_pos = line.find(';');
            double price = atof(line.substr(0, sc_pos).c_str());
            double cash = atof(line.substr(sc_pos + 1, line.size() - sc_pos - 1).c_str());
            
            StringChangeCalculator calc;
            cout << calc.run(price, cash) << endl;
        }
    }
    
    return 0;
}

string StringChangeCalculator::run(double price, double cash) {
	// real values were multiplied by a hundred to avoid the
	// approximation errors caused by floating point numbers.
    int p = price * 100;
    int c = cash * 100;
    int change = c - p;
    
    if (change == 0) return "ZERO";
    else if (change < 0) return "ERROR";
    
    string result;
    
	// for each bill/coin value, the total quantity needed of that bill/coin is calculated,
	// appended to the result string and the remaining change recalculated until all the bill/coin
	// values have been checked or there's no more change, whatever happens first.
    for (int i = 0; i < _total_bc_values; i++) {
        int total_bc = change / _bc_values[i];
		
        for (int j = 0; j < total_bc; j++) {
            result.append(_bc_names[i]);
            result.push_back(',');
        }
        
        change %= _bc_values[i];
		if (change == 0) break;
    }
    
	// the last comma is removed from the result string
    result.erase(result.size() - 1, 1);
    
    return result;
}
