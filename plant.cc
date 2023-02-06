/*************************************************************************
    This is the implementation file for the Plant class. For more 
		information about the class see plant.h.
    Students are expected to implement the input and output functions
		below.

	Patricia Lindner	Ohio University EECS	January 2023
*************************************************************************/
#include "plant.h"
#include <iostream>
using namespace std;

Plant::Plant(string n, string c, Date i, int s){
	name = n;
	color = c;
	cameIn = i;
	stock = s;
}

// Input and output functions
void Plant::input(std::istream& ins){
	/* You are to write the implementation of this function to read 
	from the keyboard or a file. Remember to use getline to read the 
	pay to.  */

	// if the input stream matches cin, then get input from the input stream (with prompts)
	if(&ins == &std::cin){
		cout << "Enter the plant name: " << endl;
		while(ins.peek()=='\n'){
			ins.ignore();
		}
		getline(ins, name);

		cout << "Enter the plant color: " << endl;
		getline(ins, color);

		cout << "Enter the date the plant came in: " << endl;
		while(ins.peek()=='\n'){
			ins.ignore();
		}
		ins >> cameIn;

		cout << "Enter the plant stock: " << endl;
		ins >> stock;

	}

	// if the input stream does not match cin, the get input from the input stream (without prompts)
	else{
		while(ins.peek()=='\n'){
			ins.ignore();
		}
		getline(ins, name);
		getline(ins, color);
		while(ins.peek()=='\n'){
			ins.ignore();
		}
		ins >> cameIn;
		ins >> stock;
				while(ins.peek()=='\n'){
			ins.ignore();
		}
	}
}

void Plant::output(std::ostream& outs)const{
	/* You are to write the implementation of this function to write 
	to the monitor or to a file. Remember not to put labels into the 
	file.*/

	// if the output stream matches cout, then output with labels
	if(&outs == &std::cout){
		outs << "Plant name: " << name << endl;
		outs << "Plant color: " << color << endl;
		outs << "Date the plant came in: " << cameIn << endl;
		outs << "Stock: " << stock << endl << endl;

	}

	// if the output stream does not match cout, then output without prompts
	else{
		outs << name << endl;
		outs << color << endl;
		outs << cameIn << endl;
		outs << stock << endl << endl;
	}
}

ostream& operator << (ostream& outs, const Plant& p){
	p.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Plant& p){
	p.input(ins);
	return ins;
}