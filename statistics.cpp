#include "statistics.h"

statistics::statistics()
{
}

statistics::statistics(popular_request request, load_time date)
{
	requests.push_back(request);
	dates.push_back(date);
}

statistics::statistics(std::string request, std::string date)
{
	requests.push_back(popular_request(request));
	dates.push_back(load_time(date));
}

void statistics::add_request(popular_request request)
{
	for (auto it = requests.begin(); it != requests.end(); it++)
	{
		if ((*it).get_request() == request.get_request())
		{
			(*it).add_one();
			return;
		}
	}
	requests.push_back(request);
}

void statistics::add_date(load_time date)
{
	for (auto it = dates.begin(); it != dates.end(); it++)
	{
		if ((*it).get_date() == date.get_date())
		{
			if ((*it).get_time() == date.get_time())
			{
				(*it).add_one();
				return;
			}
		}
	}
	dates.push_back(date);
}

void statistics::show_popular_request()
{
	requests.sort();

	std::cout << "MOST POPULAR REQUEST ->" << std::endl;
	std::cout << "| ";
	std::cout << requests.back().get_request() << "\t" << requests.back().get_request_number();
	std::cout << " |";
	std::cout << std::endl;
}

void statistics::show_load_time()
{
	dates.sort();

	std::cout << "MOST LOADED TIME->" << std::endl;
	std::cout << "| ";
	std::cout << dates.back().get_date() << "\t" << dates.back().get_time() << ":00 +1 hour" << "\t" << dates.back().get_number();
	std::cout << " |";
	std::cout << std::endl;
}
