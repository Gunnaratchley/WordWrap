#include <fstream>
#include <iostream>
#include <string>

#include "text_util.h"

int main()
{
	std::cout << "Please choose alignment preference > " << std::endl;
	std::cout << "For Right Align enter R or r > " << std::endl;
	std::cout << "For Left Align enter L or l > " << std::endl;
	std::cout << "For Justified enter J or j > " << std::endl;
	std::string choice;
	std::cin >> choice;

	//std::cout << "Please enter text > " << std::endl;
	std::string words;
	//std::cin >> words;

	std::ifstream fin;
	fin.open("address.txt");

		if (choice == "R" || choice == "r")
		{
			while (getline(fin, words))
			{
				auto input = nwacc::word_wrap(words, nwacc::max_size);
				nwacc::pad_after_punct(input);

				std::ofstream fout;
				fout.open("formatted_address.txt");
				fout << input << std::endl;
				fout.close();
			}

		}
		else if (choice == "L" || choice == "l")
		{
			while (getline(fin, words))
			{
				auto input = nwacc::word_wrap(words, nwacc::max_size);
				nwacc::pad_after_punct(input);
				
				std::ofstream fout;
				fout.open("formatted_address.txt");
				fout << input << std::endl;
				fout.close();
			}
		}
		else if (choice == "J" || choice == "j")
		{
			while (getline(fin, words))
			{
				auto input = nwacc::word_wrap(words, nwacc::max_size);
				nwacc::pad_after_punct(input);
				
				std::ofstream fout;
				fout.open("formatted_address.txt");
				fout << input << std::endl;
				fout.close();
			}
		}
		else
		{
			std::cout << "Input is invalid please enter valid response > " << std::endl;
			std::cin >> choice;
		}
	return 0;
}