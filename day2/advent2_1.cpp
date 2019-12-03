#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void print_memory(const vector <int> &memory){
	cout << "\n";
	for(int i = 0; i < memory.size(); ++i){
		cout << memory[i] << " ";
	}
	cout << "\n";
	return;
}

// Populate memory (vector) with the contents of the file
void fill_memory(istream &file, vector <int> &mem){
	int reg;
	char comma;

	while(file >> reg >> comma){
		mem.push_back(reg);
	}
	
	// Last number
	file >> reg;
	mem.push_back(reg);

	return;
}

//Execute the instructions in memory
void execute_program(vector <int> &mem){
	int pc = 0;

	for(int pc = 0; pc < mem.size() ;pc += 4){
		switch(mem[pc]){
			case 99:
				return;
			case 1:
				mem[mem[pc+3]] = mem[mem[pc+1]] + mem[mem[pc+2]];
				break;
			case 2:
				mem[mem[pc+3]] = mem[mem[pc+1]] * mem[mem[pc+2]];
	       			break;	
			default:
				cout << "Oh noes! Something Went wrong. PC is at "
				       	<< pc << " with mem " << mem[pc] << "\n"; 
		}
	}
}

int main(){
	ifstream von_neumann("input2.txt");
	vector <int> memory;
	
	fill_memory(von_neumann, memory);
	print_memory(memory); 

	memory[1] = 12;
	memory[2] = 2;
	execute_program(memory);
	
	print_memory(memory);
	return 0;
}
