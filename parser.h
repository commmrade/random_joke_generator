#pragma once 

#include <exception>
#include<iostream>
#include<chrono>
#include<thread>


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

    void print_joke(Joke &joke);

};