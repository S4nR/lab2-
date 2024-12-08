#include "faculty.hpp"
#ifndef LOGGER_HPP     
#define LOGGER_HPP   

class Operation_logger
{
    public:
        virtual void log(std::fstream &logging_file,const std::string& message) = 0;
        Operation_logger();
        virtual ~Operation_logger();
};

class Console_logger : public Operation_logger
{   
    public:
        void log(std::fstream &logging_file,const std::string& message) override;
};

class File_logger : public Operation_logger
{
    public:
        void log(std::fstream &logging_file,const std::string& message) override;
};

#endif