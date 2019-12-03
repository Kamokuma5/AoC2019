#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
	ifstream puzzle_input("input.txt");
	unsigned mass;
	unsigned total_fuel = 0;
	while(puzzle_input >> mass){
		total_fuel += mass/3-2;
	}
	cout << setprecision(10) << total_fuel << "\n";
	return 0;
}
