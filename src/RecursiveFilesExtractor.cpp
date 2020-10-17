#include <experimental/filesystem>

#include "RecursiveFilesExtractor.h"

PathList RecursiveFilesExtractor::get_recursive_paths_list() {
    PathList paths_list = PathList();
    for(auto & path: std::experimental::filesystem::recursive_directory_iterator(this->root_path_))
    {
        if(path.path().extension() == this->files_extension_type_)
            paths_list.push_back(path.path().string());
    }
    return paths_list;
}