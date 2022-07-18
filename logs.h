#pragma once
#include <list>
#include "entry.h"
#include "statistics.h"

class logs
{
private:
	std::list<entry> entries;
	statistics analyz;
public:
	logs();
	logs(entry log);

	void add_log(entry log);

	void get_popular_request();
	void get_load_time();
};
