#include "api.h"




Request::Request(std::string url)
{
    curl = curl_easy_init();
    if(curl)
    {

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Request::writeData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

    }
}
Request::~Request()
{
    curl_easy_cleanup(curl);
}

size_t Request::writeData(void *data, size_t size, size_t n, std::string *str)
{
    str->append((char*)data, size * n);

    return size * n;
}

std::string Request::get()
{
    res = curl_easy_perform(curl);

    return buffer;
}


