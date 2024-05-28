#pragma once 

#include <exception>
#include<iostream>
#include<nlohmann/json.hpp>
using json = nlohmann::json;


struct Joke
{
    std::string setup;
    std::string punchline;
};


class Parser
{
public:
    static Parser &Get();

    Joke Parse(std::string &buf);

};