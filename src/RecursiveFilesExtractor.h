#ifndef XSD_COVERAGE_RECURSIVEFILESEXTRACTOR_H
#define XSD_COVERAGE_RECURSIVEFILESEXTRACTOR_H

#include <string>
#include <map>
#include <vector>

using FilesMap = std::map<std::string, std::string>;
using PathList = std::vector<std::string>;

class RecursiveFilesExtractor {
public:
    RecursiveFilesExtractor(const char * root_path, const char * files_extension_type) :
    root_path_(std::string(root_path)), files_extension_type_(std::string(files_extension_type)) {};
    FilesMap get_files_map();
private:
    std::string root_path_;
    std::string files_extension_type_;
    PathList get_all_recursive_paths_();
    static std::string get_file_content_(const std::string& file_path);
};

#endif //XSD_COVERAGE_RECURSIVEFILESEXTRACTOR_H
