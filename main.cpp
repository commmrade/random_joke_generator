#include <chrono>
#include <iostream>
#include<curl/curl.h>
#include<string>
#include <thread>
#include "api.h"
#include "parser.h"






int main(int, char**){
    
    Request req("https://official-joke-api.appspot.com/jokes/random");
    std::string buf = req.get();

    Joke j = Parser::Get().Parse(buf);

    Parser::Get().print_joke(j);


    return 0;
}
