#include <chrono>
#include <iostream>
#include<curl/curl.h>
#include<string>
#include <thread>
#include "api.h"
#include "parser.h"



void print_joke(Joke &joke)
{
    std::cout << joke.setup << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << joke.punchline << std::endl;
}


int main(int, char**){
    
    Request req("https://official-joke-api.appspot.com/jokes/random");
    std::string buf = req.get();

    Joke j = Parser::Get().Parse(buf);

    print_joke(j);


    return 0;
}
