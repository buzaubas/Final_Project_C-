#pragma once
#include <list>
#include <string>
#include <iostream>
#include "popular_request.h"
#include "load_time.h"


class statistics
{
private:
	std::list<popular_request> requests;
	std::list<load_time> dates;
public:
	statistics();
	statistics(popular_request request, load_time date);
	statistics(std::string request, std::string date);

	void add_request(popular_request request);
	void add_date(load_time date);

	void show_popular_request();
	void show_load_time();
};
