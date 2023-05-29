class Node
{

public:

    Node* GetParent();
    void SetParent(Node* parent);

private:

    Node* parent = 0;
};