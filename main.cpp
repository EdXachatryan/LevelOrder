#include <iostream>
#include <queue>
#include <stack>



struct node
{
    node(int v) : data(v), pLeftNode(nullptr), pRightNode(nullptr) {}
    int data;
    node* pLeftNode;
    node* pRightNode;
};

using nodePtr = node*;


void levelOrderTravers(nodePtr root)
{
    if (root == nullptr)
        return;

    std::queue<nodePtr> nodes;

    std::stack<nodePtr> reverseOrder;
    reverseOrder.push(root);
    nodePtr temp = reverseOrder.top();
    std::cout << temp->data << " ";
    nodes.push(temp->pLeftNode);
    nodes.push(temp->pRightNode);
    reverseOrder.pop();
    std::cout << std::endl;

    while (!nodes.empty())
    {
        while (!nodes.empty())
        {
            nodePtr temp = nodes.front();
            std::cout << temp->data << " ";
            nodes.pop();
            if (temp->pLeftNode != nullptr)
                reverseOrder.push(temp->pLeftNode);
            if (temp->pRightNode != nullptr)
                reverseOrder.push(temp->pRightNode);
        }
        std::cout << std::endl;

        while (!reverseOrder.empty())
        {
            nodePtr temp = reverseOrder.top();
            std::cout << temp->data << " ";
            reverseOrder.pop();

            if (temp->pLeftNode != nullptr)
                nodes.push(temp->pLeftNode);
            if (temp->pRightNode != nullptr)
                nodes.push(temp->pRightNode);
        }
        std::cout << std::endl;
    }
}

int main()
{
    nodePtr root = new node(1);
    root->pLeftNode = new node(2);
    root->pRightNode = new node(3);
    root->pLeftNode->pLeftNode = new node(4);
    root->pLeftNode->pRightNode = new node(5);
    root->pLeftNode->pRightNode->pLeftNode = new node(6);
    root->pLeftNode->pRightNode->pRightNode = new node(7);

    levelOrderTravers(root);



    system("pause");
    return 0;
}