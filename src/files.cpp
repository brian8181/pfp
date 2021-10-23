#include <string>

using namespace std;

enum TokenType
{
	Number,
	Operator
};

class Token
{
private: 

	int last_id = 0;
	int id = 0;
	TokenType type = Number;
	string value;
	
	Token(string v)
	{

        //last_id = 0;

		// this.value = value;
		// id = ++last_id;

		// double d;
		//bool isnum = double.TryParse(value, out d);
		// if (!isnum)
		// 	type = TokenType.Operator;
	}

	TokenType getType()
	{
		return type;
	}

	string Value()
	{
		return value;
	}
};

  /// <summary>
        /// represents a parser node
        /// </summary>
class Node
{
    Node* parent = 0;

public:

    Node* GetParent()
    {
        return parent; 
    }

    // public Node SetParent(Node* parent)
    // {

    //     parent = parent; 
    // }
};

/// <summary>
/// a terminal node
/// </summary>
class TerminalNode : Node
{
    Token* token = 0;

    TerminalNode(string token) 
    {
       
    }

    TerminalNode(Token token)
    {
        this->token = &token;
    }

    // Token Token
    // {
    //     get { return token; }
    //     set { token = value; }
    // }
};

/// <summary>
/// a binary parser node
/// </summary>
class BinaryNode : TerminalNode
{
    // TerminalNode left* = null;
    // TerminalNode right* = null;

    // BinaryNode(Token token, TerminalNode* left, TerminalNode* right)
    //     : BinaryNode(token)
    // {
    //     this->left = left;
    //     this->right = right;
    //     // this->left->Parent = this;
    //     // this->right->Parent = this;
    // }

    // public TerminalNode Left
    // {
    //     get { return left; }
    // }

    // public TerminalNode Right
    // {
    //     get { return right; }
    // }
};