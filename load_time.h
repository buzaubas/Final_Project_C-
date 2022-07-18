#pragma once
#include <string>

class load_time
{
private:
	std::string date;
	std::string time;
	size_t number = 1;
public:
	load_time();
	load_time(std::string date, std::string time);
	load_time(const std::string str);

	std::string get_date();
	std::string get_time();
	size_t get_number();

	bool operator<(const load_time& obj);

	void add_one();
};

