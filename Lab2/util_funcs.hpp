#ifndef UTIL_FUNCS_HPP   
#define UTIL_FUNCS_HPP
#include "faculty.hpp"
#include "log_system.hpp" 

void show_menu();
void display_all_faculties(std::vector<Faculty> * faculties);
void search_student_by_email(std::vector<Faculty> * faculties,std::fstream &logging_file);
void add_faculty(std::vector<Faculty> * faculties,std::fstream &logging_file);
std::string get_study_field();
void show_all_faculties_belonging_to_a_field(std::vector<Faculty> * faculties,std::string faculty_field);
int get_faculty_choice(std::vector<Faculty> * faculties);

#endif
