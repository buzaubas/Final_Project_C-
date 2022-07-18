#include "entry.h"

entry::entry()
{
}

entry::entry(std::string ip, std::string username, std::string request_date, std::string request_line, size_t reply_code, std::string reply_length, std::string request_site, std::string device_info)
{
	this->ip = ip;
	this->username = username;
	this->request_date = request_date;
	this->request_line = request_line;
	this->reply_code = reply_code;
	this->reply_length = reply_length;
	this->request_site = request_site;
	this->device_info = device_info;
}

entry::entry(const char* str)
{
	std::string tmp;

	std::string word(str);
	auto len = word.find_first_of('-');
	this->ip = word.substr(0, (len - 1)); //Отнимаем захваченный пробел
	tmp = word.substr(len + 1);
	len = tmp.find_first_of('[');
	this->username = tmp.substr(1, (len - 2));
	tmp = tmp.substr(len + 1);
	len = tmp.find_first_of(']');
	this->request_date = tmp.substr(0, len);
	tmp = tmp.substr(len + 3); //Захватываем пробел и ковычки
	len = tmp.find_first_of('"');
	/*tmp = tmp.substr(len + 1);
	len = tmp.find_first_of('"');*/
	this->request_line = tmp.substr(0, len);
	tmp = tmp.substr(len + 2); // Добавляем пробел, поэтому 2
	len = tmp.find_first_of(' ');
	this->reply_code = std::stoi(tmp.substr(0, len));
	tmp = tmp.substr(len + 1);
	len = tmp.find_first_of(' ');
	this->reply_length = tmp.substr(0, len);
	tmp = tmp.substr(len + 2);
	len = tmp.find_first_of('"');
	/*tmp = tmp.substr(len + 1);
	len = tmp.find_first_of('"');*/
	this->request_site = tmp.substr(0, len);
	tmp = tmp.substr(len + 3); //Захватываем пробел и ковычки
	len = tmp.find_first_of('"');
	this->device_info = tmp.substr(0, len);
}

void entry::set_ip(std::string ip)
{
	this->ip = ip;
}

void entry::set_username(std::string username)
{
	this->username = username;
}

void entry::set_request_date(std::string request_date)
{
	this->request_date = request_date;
}

void entry::set_request_line(std::string request_line)
{
	this->request_line = request_line;
}

void entry::set_reply_code(size_t reply_code)
{
	this->reply_code = reply_code;
}

void entry::set_reply_length(std::string reply_length)
{
	this->reply_length = reply_length;
}

void entry::set_request_site(std::string request_site)
{
	this->request_site = request_site;
}

void entry::set_device_info(std::string device_info)
{
	this->device_info = device_info;
}

std::string entry::get_ip()
{
	return this->ip;
}

std::string entry::get_username()
{
	return this->username;
}

std::string entry::get_request_date()
{
	return this->request_date;
}

std::string entry::get_request_line()
{
	return this->request_line;
}

size_t entry::get_reply_code()
{
	return this->reply_code;
}

std::string entry::get_reply_length()
{
	return this->reply_length;
}

std::string entry::get_request_site()
{
	return this->request_site;
}

std::string entry::get_device_info()
{
	return this->device_info;
}
