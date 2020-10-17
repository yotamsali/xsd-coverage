#include <string>
#include <iostream>
#include "../lib/rapidxml_utils.hpp"
#include "XMLForest.h"

void XMLForest::insert_xml_file_(std::string xml_path) {
    rapidxml::file<> xml_file(xml_path.c_str());
    rapidxml::xml_document<> xml_document;
    xml_document.parse<0>(xml_file.data());
    rapidxml::xml_node<>* cur_node = xml_document.first_node();
    while (cur_node->next_sibling() != NULL ) {
        std::cout << cur_node->name() << std::endl;
        cur_node = cur_node->next_sibling();
    }
}

void XMLForest::insert_xsd_file_(std::string xsd_path) {
    return;
}

TagNode * XMLForest::get_node_(std::string tag) {
    for(int index = 0; index < this->forest_.size(); index++)
        if (this->forest_.at(index)->tag == tag)
            // Case node already exists in forest.
            return this->forest_.at(index);
    // Case node doesn't exist in forest.
    TagNode * new_tag_node = new TagNode;
    new_tag_node->tag = tag;
    this->forest_.push_back(new_tag_node);
    return new_tag_node;
}

Edge * XMLForest::get_edge_(TagNode * origin_node, std::string neighbor_tag, bool is_up_direction) {
    std::vector<Edge> * edge_list = NULL;
    if (is_up_direction)
        edge_list = &origin_node->parents;
    else
        edge_list = &origin_node->children;
    for (Edge edge : *edge_list) {
        if(edge.neighbor->tag == neighbor_tag)
            return &edge;
    }
    Edge * edge = new Edge();
    edge->neighbor = this->get_node_(neighbor_tag);
    return edge;
}

void
XMLForest::insert_tag_(std::string tag, std::string reference_path, bool is_xml, std::vector<std::string> children_tags,
                       std::vector<std::string> parents_tags) {
    TagNode * tag_node = XMLForest::get_node_(tag);
    for(std::string child_tag : children_tags) {
        Edge * new_edge = this->get_edge_(tag_node, child_tag, false);
        tag_node->children.push_back(*new_edge);
    }
    for (std::string parent_tag : parents_tags) {
        Edge * new_edge = this->get_edge_(tag_node, parent_tag, true);
        tag_node->parents.push_back(*new_edge);
    }

}

void XMLForest::insert_xml_files(PathList xml_path_list) {
    for(std::string xml_path : xml_path_list) {
        this->insert_xml_file_(xml_path);
    }
}

void XMLForest::insert_xsd_files(PathList xsd_path_list) {
    for (std::string xsd_path : xsd_path_list) {
        this->insert_xsd_file_(xsd_path);
    }
}

void XMLForest::estimate_coverage() {
    return;
}
