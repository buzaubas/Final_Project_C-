#pragma once
#include <string>

class entry
{
private:
    std::string ip;           // The IP address of the client’s host machine.
    std::string username;     // The authenticated client username. A hyphen (-) means no authentication was required.
    std::string request_date; // The date and time of the client request, enclosed in brackets.
    std::string request_line; // The request line, enclosed in quotes.
    size_t reply_code;        // The proxy response status code (HTTP reply code).
    std::string reply_length;      // The length of the Traffic Server response to the client in bytes.
    std::string request_site; // The site
    std::string device_info;  // Info about device that sent request
public:
    entry();
    entry(std::string ip, std::string username, std::string request_date, std::string request_line, size_t reply_code, std::string reply_length, std::string request_site, std::string device_info);
    entry(const char* str);

    void set_ip(std::string ip);
    void set_username(std::string username);
    void set_request_date(std::string request_date);
    void set_request_line(std::string request_line);
    void set_reply_code(size_t reply_code);
    void set_reply_length(std::string reply_length);
    void set_request_site(std::string request_site);
    void set_device_info(std::string device_info);

    std::string get_ip();
    std::string get_username();
    std::string get_request_date();
    std::string get_request_line();
    size_t get_reply_code();
    std::string get_reply_length();
    std::string get_request_site();
    std::string get_device_info();

};
