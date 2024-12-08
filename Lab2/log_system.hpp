#include "faculty.hpp"
#include "logger.hpp"
#ifndef LOG_SYSTEM_HPP
#define LOG_SYSTEM_HPP
class Logging_system
{
    public:
        static Operation_logger * logger;
        static bool has_changes;
        static void log_student(std::fstream &logging_file,Students &student);
        static void log_faculty(std::fstream &logging_file,Faculty &faculty);
        static void log_graduation(std::fstream &logging_file,std::string email, int year_study);
        static void log_error_graduation(std::fstream &logging_file,std::string email);
        static void log_error_searching_student(std::fstream &logging_file,std::string email);
        static void log_found_student(std::fstream &logging_file,std::string email_to_search);
        static void delete_logger();
        static void execute_logging(std::fstream &logging_file,std::string &message);
        static Operation_logger *choose_logger();
};

#endif