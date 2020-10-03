#include <iostream>
#include "RecursiveFilesExtractor.h"
#include "XMLForest.h"
#include "../lib/rapidxml.hpp"

int main(int argc, char *argv[])
{
    PathList xmls_paths = RecursiveFilesExtractor("C:\\temp\\xmls", ".xml").get_recursive_paths_list();
    PathList xsds_paths = RecursiveFilesExtractor("C:\\temp\\xsds", ".xsd").get_recursive_paths_list();
    XMLForest * forest = new XMLForest();
    forest->insert_xml_files(xmls_paths);
    forest->insert_xsd_files(xsds_paths);
    forest->estimate_coverage();
    delete forest;
    return 0;
}