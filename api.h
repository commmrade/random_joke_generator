#pragma once

#include<iostream>
#include<curl/curl.h>


class Request
{
private:
    //std::string url;
    CURL* curl;
    CURLcode res;
    std::string buffer;
    static size_t writeData(void *data, size_t size, size_t n, std::string *str);
public:
    Request(std::string url);
    std::string get();
    ~Request();
};