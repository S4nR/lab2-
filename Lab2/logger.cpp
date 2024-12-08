#include "logger.hpp"
Operation_logger::Operation_logger() = default;
Operation_logger::~Operation_logger() = default;
void Console_logger::log(std::fstream &logging_file,const std::string& message) 
{
    std::cout <<"Console        logger            called" << std::endl;
    std::cout << message << std::endl;
    logging_file << message << std::endl << std::endl;
}

void File_logger::log(std::fstream &logging_file,const std::string& message) 
{
    std::cout <<"File        logger         called" << std::endl;
    logging_file << message << std::endl << std::endl;
}