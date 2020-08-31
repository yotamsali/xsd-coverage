#ifndef XSD_COVERAGE_XMLFOREST_H
#define XSD_COVERAGE_XMLFOREST_H

#include <string>
#include <vector>

struct TagNode;
using Edge = struct {
    TagNode * neighbor;
    std::vector<std::string> xml_reference_paths;
    std::vector<std::string> xsd_reference_paths;
};
typedef struct TagNode{
    std::string tag;
    std::vector<Edge> children;
} TagNode;
using NodeList = std::vector<TagNode>;

class XMLForest {
public:
    void insert_xml_file();
    void insert_xsd_file();
    void remove_cycles();
    void estimate_coverage();
private:
    NodeList forest_;
    NodeList get_node_connectivity_component_(TagNode node);
    bool is_in_forest()




};


#endif //XSD_COVERAGE_XMLFOREST_H
