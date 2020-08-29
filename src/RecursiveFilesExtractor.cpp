#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <experimental/filesystem>

#include "RecursiveFilesExtractor.h"

FilesMap RecursiveFilesExtractor::get_files_map() {
    FilesMap file_map = FilesMap();
    PathList relevant_paths_list = this->get_all_recursive_paths_();
    for(const std::string& path : relevant_paths_list)
        file_map[path] = get_file_content_(path);
    return file_map;
}

PathList RecursiveFilesExtractor::get_all_recursive_paths_() {
    PathList paths_list = PathList();
    for(auto& path: std::experimental::filesystem::recursive_directory_iterator(this->root_path_))
    {
        if(path.path().extension() == this->files_extension_type_)
            paths_list.push_back(path.path());
    }
    return paths_list;
}

std::string RecursiveFilesExtractor::get_file_content_(const std::string& file_path) {
    std::ifstream file_stream(file_path);
    return std::string ((std::istreambuf_iterator<char>(file_stream)),
                    std::istreambuf_iterator<char>());
}
