#include <iostream>
#include "RecursiveFilesExtractor.h"
#include "../lib/rapidxml.hpp"

int main(int argc, char *argv[])
{
    FilesMap xmls_map = RecursiveFilesExtractor("C:\\temp\\xmls", ".xml").get_files_map();
    FilesMap xsds_map = RecursiveFilesExtractor("C:\\temp\\xsds", ".xsd").get_files_map();
    return 0;
}