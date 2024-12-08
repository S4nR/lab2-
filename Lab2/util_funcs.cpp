#include <iostream>
#include "util_funcs.hpp"
#include "faculty.hpp"

void show_menu()
{
    std::cout << "Choose one option:" << std::endl;
    std::cout << "1.Add a student to a faculty" << std::endl;
    std::cout << "2.Graduate a student from a faculty" << std::endl;
    std::cout << "3.Display all enrolled students" << std::endl;
    std::cout << "4.Display graduates" << std::endl;
    std::cout << "5.Verify belonging of a student" << std::endl;
    std::cout << "6.Search a student by email" << std::endl;
    std::cout << "7.Add a faculty" << std::endl;
    std::cout << "8.Display all faculties" << std::endl;
    std::cout << "9.Display all faculties belonging to a field" << std::endl;
    std::cout << "10.Load all previous changes" << std::endl;  
    std::cout << "0.Exit" << std::endl;
}
std::string get_study_field()
{
    int field;
    std::string studField;
        jump:
    std::cout << "Choose a field:" << std::endl;
    std::cout << "1.MECHANICAL_ENGINEER" << std::endl;
    std::cout << "2.SOFTWARE_ENGINEERING" << std::endl;
    std::cout << "3.FOOD_TECHNOLOGY" << std::endl;
    std::cout << "4.URBANISM_ARCHITECTURE" << std::endl;
    std::cout << "5.VETERINARY_MEDICINE" << std::endl;
    std::cin >> field;
    std::cin.ignore();
    if(field == 1)
    {
        studField = "MECHANICAL_ENGINEER";
    }
    if(field == 2)
    {
        studField = "SOFTWARE_ENGINEERING";
    }
    if(field == 3)
    {
        studField = "FOOD_TECHNOLOGY";
    }
    if(field == 4)
    {
        studField = "URBANISM_ARCHITECTURE";
    }
    if(field == 5)
    {
        studField = "VETERINARY_MEDICINE";
    }
    if(field > 5 || field < 1)
    {
        goto jump;
    }
    return studField;
}
void display_all_faculties(std::vector<Faculty> * faculties)
{
    if(faculties->size() == 0)
    {
        std::cout << "There are no faculties" << std::endl;
        return;
    }
    std::cout << "All the faculties are:" << std::endl;
    int i = 0;
    for(auto iter = faculties->begin(); iter != faculties->end(); iter++)
    {
        std::cout << i + 1 <<". " << iter->faculty_name << std::endl;
        i++;
    }
}
void search_student_by_email(std::vector<Faculty> * faculties,std::fstream &logging_file)
{
    if(faculties->size() == 0)
    {
        std::cout << "There are no faculties" << std::endl;
        return;
    }

    std::string email_to_search;
    std::cout << "Enter student's email" << std::endl;
    std::cin >> email_to_search;

    for(unsigned int i = 0; i < faculties->size(); i++)
    {
        for(auto students_iter = faculties->at(i).students.begin(); students_iter != faculties->at(i).students.end(); students_iter++)
        {
            if(students_iter->email == email_to_search)
            {
                std::cout << "Student with email '" << email_to_search <<"' stands in faculty '" <<
                faculties->at(i).faculty_name  << "'"<< std::endl;
                Logging_system::log_found_student(logging_file,email_to_search);
                return;
            }
        }
    }
    Logging_system::log_error_searching_student(logging_file,email_to_search);
    std::cout << "Student with email '" << email_to_search << "' was not found" << std::endl;
}
void add_faculty(std::vector<Faculty> * faculties,std::fstream &logging_file)
{
    std::string faculty_name;
    std::string faculty_abrv;
    std::string studField;
    studField = get_study_field();
    std::cout << "Enter faculty's name: " << std::endl;
    getline(std::cin,faculty_name);
    std::cout << "Enter faculty's abreviation: " << std::endl;
    getline(std::cin,faculty_abrv);
    faculties->emplace_back(Faculty(faculty_name,faculty_abrv,studField));
    Faculty faculty = Faculty(faculty_name,faculty_abrv,studField);
    Logging_system::log_faculty(logging_file,faculty);
}
void show_all_faculties_belonging_to_a_field(std::vector<Faculty> * faculties,std::string faculty_field)
{
    if(faculties->size() == 0)
    {
        std::cout << "There are no faculties" << std::endl;
        return;
    }

    int val;
    for(auto iter = faculties->begin(); iter != faculties->end(); iter++)
    {
        if(iter->study_field == faculty_field)
        {
            val = 1;
            std::cout << "Faculty " << iter->faculty_name << " belongs to field " << faculty_field << std::endl; 
        }
    }
    if(val == 0)
    {
        std::cout <<"No faculty belongs to this field" << std::endl;
    }
}

int get_faculty_choice(std::vector<Faculty> * faculties)
{
    if(faculties->size() == 0)
    {
        std::cout << "There are no faculties" << std::endl;
        return -1;
    }

    unsigned int faculty_choice;
    
    jump:
    std::cout << "Choose a faculty:" << std::endl;
    display_all_faculties(faculties);
    std::cin >> faculty_choice;
    if(faculty_choice <= 0 || faculty_choice > faculties->size())
    {
        goto jump;
    }
    std::cin.ignore();

    return faculty_choice - 1;
}
