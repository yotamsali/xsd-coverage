#include <iostream>
#include "RecursiveFilesExtractor.h"
#include "../lib/rapidxml.hpp"

int main(int argc, char *argv[])
{
    RecursiveFilesExtractor xmls_extractor = RecursiveFilesExtractor("C:\\temp\\xmls", ".xml");
    RecursiveFilesExtractor xsds_extractor = RecursiveFilesExtractor("C:\\temp\\xsds", ".xsd");
    FilesMap xmls_map = xmls_extractor.get_files_map();
    FilesMap xsds_map = xsds_extractor.get_files_map();

    return 0;
}