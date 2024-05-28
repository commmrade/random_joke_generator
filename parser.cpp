#include "parser.h"



Parser & Parser::Get()
{
    static Parser instance;
    return instance;
}

Joke Parser::Parse(std::string &buf)
{
    
    json js = json::parse(buf);
    
    if(js["setup"].empty())
    {
        return {"Something went wrong...", "Something went wrong..."};
    }    

    return {js["setup"], js["punchline"]};
}
void Parser::print_joke(Joke &joke)
{
    std::cout << joke.setup << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << joke.punchline << std::endl;
}