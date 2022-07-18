#include "load_time.h"

load_time::load_time()
{
}

load_time::load_time(std::string date, std::string time)
{
	this->date = date;
	this->time = time;
}
	
load_time::load_time(const std::string str)
{
	std::string tmp;

	std::string word(str);
	auto len = word.find_first_of(':');
	this->date = word.substr(0, len);
	tmp = word.substr(len + 1);
	len = tmp.find_first_of(':');
	this->time = tmp.substr(0, len);
}

std::string load_time::get_date()
{
	return this->date;
}

std::string load_time::get_time()
{
	return this->time;
}

size_t load_time::get_number()
{
	return this->number;
}

bool load_time::operator<(const load_time& obj)
{
	return number < obj.number;
}

void load_time::add_one()
{
	this->number++;
}
