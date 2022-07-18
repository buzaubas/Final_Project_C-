#include <iostream>
#include <fstream>
#include "entry.h"
#include "logs.h"

using namespace std;

int main()
{
	logs my_site;

	ifstream ifs("C:\\Users\\talga.LAPTOP-85HJFNU6\\Downloads\\logs.txt", ios::in);
	if (!ifs.bad())
	{
		std::cout << "Processing: ";
		int i = 0;
		char buffer[2048];
		while (!ifs.eof())
		{
			ifs.getline(buffer, 2048);
			my_site.add_log(entry(buffer));
			switch (i) {
			case 0:
				std::cout << "\\";
				break;
			case 1:
				std::cout << "|";
				break;
			case 2:
				std::cout << "/";
				break;
			case 3:
				std::cout << "-";
				break;
			}
			if (i == 4)
			{
				i = 0;
				std::cout << " ";
			}
			std::cout << "\b";
			i++;
		}
		ifs.close();
	}
	my_site.get_popular_request();
	std::cout << std::endl;
	my_site.get_load_time();
	return 0;
}
