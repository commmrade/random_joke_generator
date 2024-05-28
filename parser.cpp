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