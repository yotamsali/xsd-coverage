#ifndef XSD_COVERAGE_RECURSIVEFILESEXTRACTOR_H
#define XSD_COVERAGE_RECURSIVEFILESEXTRACTOR_H

#include <string>
#include <map>
#include <vector>

using PathList = std::vector<std::string>;

class RecursiveFilesExtractor {
public:
    RecursiveFilesExtractor(const char * root_path, const char * files_extension_type) :
    root_path_(std::string(root_path)), files_extension_type_(std::string(files_extension_type)) {};
    PathList get_recursive_paths_list();
private:
    std::string root_path_;
    std::string files_extension_type_;
};

#endif //XSD_COVERAGE_RECURSIVEFILESEXTRACTOR_H
