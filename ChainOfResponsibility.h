#pragma once
#include <string>
#include <memory>

class Handler
{
public:
	virtual Handler* SetNext(Handler* handler) = 0;
	virtual std::string Handle(std::string request) = 0;
};

class BaseHandler : public Handler 
{
private:
    Handler* NextHandler;
public:
    BaseHandler() 
        : NextHandler(nullptr) {}

    virtual Handler* SetNext(Handler* handler) override 
    {
        NextHandler = handler;
        return handler;
    }

    virtual std::string Handle(std::string request) override 
    {
        if (NextHandler) {
            return NextHandler->Handle(request);
        }
        return "";
    }
};

class LowPriority : public BaseHandler 
{
public:
    virtual std::string Handle(std::string request) override
    {
        if (request == "Low") 
        {
            return "It's low priority for your request\n";
        }
        else {
            return "It's not low " + BaseHandler::Handle(request);
        }
    }
};

class NormalPriority : public BaseHandler 
{
public:
    virtual std::string Handle(std::string request) override
    {
        if (request == "Normal")
        {
            return "- It's normal priority for your request\n";
        }
        else {
            return "and it's not normal " + BaseHandler::Handle(request);
        }
    }
};

class HighPriority : public BaseHandler 
{
public:
    virtual std::string Handle(std::string request) override
    {
        if (request == "High")
        {
            return "- It's high priority for your request\n";
        }
        else {
            return BaseHandler::Handle(request);
        }
    }
};

