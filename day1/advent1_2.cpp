#include <iostream>
#include <fstream>

using namespace std;

int get_fuel(int total_fuel, unsigned mass){
	int fuel = mass/3-2;
	if(fuel <= 0){
		return total_fuel;	
	}
	
	total_fuel += fuel;
	return get_fuel(total_fuel, fuel);
}

int main(){
	ifstream puzzle_input("input.txt");
	unsigned mass;
	unsigned total_fuel = 0;
	while(puzzle_input >> mass){
		total_fuel += get_fuel(0, mass);
	}
	cout << total_fuel << "\n";
	return 0;
}
