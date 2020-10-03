#ifndef XSD_COVERAGE_XMLFOREST_H
#define XSD_COVERAGE_XMLFOREST_H

#include <string>
#include <vector>

#include "RecursiveFilesExtractor.h"

struct TagNode;
using Edge = struct {
    TagNode * neighbor;
    std::vector<std::string> xml_reference_paths;
    std::vector<std::string> xsd_reference_paths;
};
typedef struct TagNode{
    std::string tag;
    std::vector<Edge> children;
    std::vector<Edge> parents;
} TagNode;
using NodeList = std::vector<TagNode*>;

class XMLForest {
public:
    XMLForest() {};
    void insert_xml_files(PathList xml_path_list);
    void insert_xsd_files(PathList xsd_path_list);
    void estimate_coverage();
private:
    NodeList forest_;
    TagNode * get_node_(std::string tag);
    void insert_tag_(std::string tag, std::string reference_path, bool is_xml, std::vector<std::string> children_tags, std::vector<std::string> parents_tags);
    void insert_xml_file_(std::string xml_path);
    void insert_xsd_file_(std::string xsd_path);
    Edge *get_edge_(TagNode *origin_node, std::string neighbor_tag, bool is_up_direction);
};

#endif //XSD_COVERAGE_XMLFOREST_H
