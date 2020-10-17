#include "RecursiveFilesExtractor.h"
#include "XMLForest.h"

//TODO: Handle memory leaks
int main(int argc, char *argv[])
{
    //TODO: Verify that dir exists and link to input parameters
    PathList xmls_paths = RecursiveFilesExtractor("C:\\temp\\xmls", ".xml").get_recursive_paths_list();
    PathList xsds_paths = RecursiveFilesExtractor("C:\\temp\\xsds", ".xsd").get_recursive_paths_list();
    XMLForest * forest = new XMLForest();
    forest->insert_xml_files(xmls_paths);
    forest->insert_xsd_files(xsds_paths);
    forest->estimate_coverage();
    delete forest;
    return 0;
}