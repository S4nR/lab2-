#include "faculty.hpp"
#include <map>
#ifndef FILE_MANAGER_HPP     
#define FILE_MANAGER_HPP   
class File_manager
{
    public:
        static void save_all_changes(std::vector<Faculty> * faculties);
        static void load_all_previous_changes(std::vector<Faculty> * faculties,std::map<std::string,int> &all_faculty_abreviations);
};



#endif