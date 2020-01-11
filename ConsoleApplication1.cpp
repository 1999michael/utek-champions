// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
int main()
{
	
	std::vector<std::vector<std::string>> output;
	std::vector<std::string> s = { "Insert","2","2","book"};
	if (output.size() != 0) {
		if (output[output.size() - 1][0] == s[0]) {
			if (s[0] == "Insert") {
				int idx1 = std::stoi(output[output.size() - 1][2]);
				int idx2 = std::stoi(s[1]);
				if (idx1 + 1 == idx2) {
					output[output.size() - 1][2] = s[1];
					output[output.size() - 1][3] = output[output.size() - 1][3] +" "+ s[3];
				}
			}
			else if (s[0] == "Replace") {
				int idx1 = std::stoi(output[output.size() - 1][2]);
				int idx2 = std::stoi(s[1]);
				if (idx1 + 1 == idx2) {
					output[output.size() - 1][2] = s[1];
					output[output.size() - 1][3] = output[output.size() - 1][3] + " " + s[3];
				}
			}
			else if (s[0] == "Delete") {
				int idx1 = std::stoi(output[output.size() - 1][2]);
				int idx2 = std::stoi(s[1]);
				if (idx1 == idx2) {
					idx1 = idx1 + 1;
					output[output.size() - 1][2] = std::to_string(idx1);
				}
			}
			else {
				output.push_back(s);
			}
		}
		else {
			output.push_back(s);
		}
	}
	else {
		output.push_back(s);
	}
	
	std::ofstream myfile;
	myfile.open("output.out");
	

	std::string final_output;
	for (int i = 0; i < output.size(); i++) {
		final_output = final_output + output[i][0] + " " + output[i][1] + "-" + output[i][2] + ", " + output[i][3] + "\n";
	}
	myfile << final_output;
	myfile.close();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
