#ifndef XSD_COVERAGE_TREE_H
#define XSD_COVERAGE_TREE_H

template<typename T>
class TreeNode
{
public:
    TreeNode(const T& value)
            : Value(value)
    {}
    T Value;
    std::list<TreeNode<T> > Children;
};

template <typename T>
class Tree
{
public:
    Tree(TreeNode<T> root)
            : Root(root)
    {}
    TreeNode<T> Root;

};
#endif //XSD_COVERAGE_TREE_H
