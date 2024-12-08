#include <iostream>
#include <fstream>
#include "faculty.hpp"
#include "students.hpp"
#include "util_funcs.hpp"
#include "file_manager.hpp"
// #include "log_system.hpp"
#include <vector>
int main()
{
    std::vector<Faculty> * faculties = new std::vector<Faculty>[5];
    std::map<std::string,int> all_faculty_abreviations;
    std::cout << "I can use an enum!!!" << std::endl;
    std::fstream students_file;
    std::fstream logging_file;
    logging_file.open("C:\\Users\\Capitan\\OneDrive\\Desktop\\logging_file_info.txt",std::ios::out);
    std::string field_choice;
    int iterations = 1;
    int choice2 = 1;
    
    while(choice2 != 0)
    {
        logging_file << "State " << iterations << std::endl;
        int faculty_choice;
        show_menu();
        try
        {
            std::cin >> choice2;
            std::cin.ignore(); 
            if(std::cin.fail())
            {
                throw std::runtime_error("Wrong choice! Insert betwen 1 and 10");
            }     
        }
        catch(std::runtime_error& error)
        {
            std::cerr << error.what() <<std::endl;
        }
        Logging_system::has_changes = false;
        switch(choice2)
        {
            case 1:
                if(faculties->size() == 0)
                {
                    faculties->emplace_back(Faculty("Inginerie meacanica  industriala si transporturi","IMIT","MECHANICAL_ENGINEER"));
                    faculties->emplace_back(Faculty("Calculatoare informatica si microelectronica","CIM","SOFTWARE_ENGINEERING"));
                    faculties->emplace_back(Faculty("Inginerie si management in industria alimentara","TA","FOOD_TECHNOLOGY"));
                    faculties->emplace_back(Faculty("Planificare urbana si regionala","UA","URBANISM_ARCHITECTURE"));
                    faculties->emplace_back(Faculty("Medicina veterinara",  "MV","VETERINARY_MEDICINE"));
                    students_file.open("C:\\Users\\Capitan\\OneDrive\\Desktop\\students.txt",std::ios::in);
                    if (!students_file.is_open())
                    {
                        std::cerr << "Nu am putut deschide fisierul." << std::endl;
                        return 1;
                    }
                }
                faculty_choice = get_faculty_choice(faculties);
                if(faculty_choice == -1)
                    break;
                faculties->at(faculty_choice).add_student(students_file,logging_file);
            break;

            case 2:
                faculty_choice = get_faculty_choice(faculties);
                if(faculty_choice == -1)
                    break;          
                faculties->at(faculty_choice).graduate_student(logging_file);
            break;

            case 3:
                faculty_choice = get_faculty_choice(faculties);
                if(faculty_choice == -1)
                    break;
                faculties->at(faculty_choice).display_all_enrolled_students();
            break;

            case 4:
                faculty_choice = get_faculty_choice(faculties);
                faculties->at(faculty_choice).display_all_graduates();
            break;

            case 5:
                faculty_choice = get_faculty_choice(faculties);
                if(faculty_choice == -1)
                    break;
                faculties->at(faculty_choice).verify_students_adherence();
            break;

            case 6:
                search_student_by_email(faculties,logging_file);
            break;
            
            case 7:
                add_faculty(faculties,logging_file);
            break;

            case 8:
                display_all_faculties(faculties);
            break;

            case 9:
                field_choice = get_study_field(); 
                show_all_faculties_belonging_to_a_field(faculties,field_choice);
            break;

            case 10:
                File_manager::load_all_previous_changes(faculties,all_faculty_abreviations);
            break;
            case 0:
                File_manager::save_all_changes(faculties);
                students_file.close();
                exit(0);
            break;

            default:
                std::cout << "Wrong number." << std::endl;
            break;
        }
        iterations++;
        if(Logging_system::has_changes == false)
        {
            logging_file << "No operation performed" << std::endl << std::endl;
        }
        
    }
    logging_file.close();
    students_file.close();
    
    return 0;
}



