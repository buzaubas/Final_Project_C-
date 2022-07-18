#pragma once
#include <string>

class popular_request
{
private:
	std::string request;
	size_t request_number = 1;
public:
	popular_request();
	popular_request(std::string request);

	std::string get_request();
	size_t get_request_number();

	bool operator<(const popular_request& obj);

	void add_one();
};
