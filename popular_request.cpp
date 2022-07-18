#include "popular_request.h"

popular_request::popular_request()
{
}

popular_request::popular_request(std::string request)
{
    this->request = request;
}

std::string popular_request::get_request()
{
    return this->request;
}

size_t popular_request::get_request_number()
{
    return this->request_number;
}

bool popular_request::operator<(const popular_request& obj)
{
    return request_number < obj.request_number;
}

void popular_request::add_one()
{
    this->request_number++;
}
