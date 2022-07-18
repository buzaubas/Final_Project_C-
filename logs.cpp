#include "logs.h"

logs::logs()
{
}

logs::logs(entry log)
{
	this->entries.push_back(log);

	analyz.add_request(popular_request(log.get_request_line()));
	analyz.add_date(load_time(log.get_request_date()));
}

void logs::add_log(entry log)
{
	this->entries.push_back(log);

	analyz.add_request(popular_request(log.get_request_line())); // нужно что бы при созданий лога он также загружался в статистику
	analyz.add_date(load_time(log.get_request_date()));
}

void logs::get_popular_request()
{
	analyz.show_popular_request();
}

void logs::get_load_time()
{
	analyz.show_load_time();
}
