// DO NOT MODIFY THIS FILE !

#include "JsonParser.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <string_view>

void JsonParser::extract_spaces()
{
    while (!_in.eof() && std::isspace(_in.peek()))
        _in.get();
}

// DO NOT MODIFY THIS FILE !

bool JsonParser::check_next_char_equals(int c, std::string_view v)
{
    int c2 = _in.peek();
    if (c == c2)
    {
        _in.get();
        return true;
    }
    std::cerr << "Unexpected character (";
    if (c2 >= 20 && c2 < 127)
    {
        std::cerr << (char)c2;
    }
    else if (c2 == -1)
    {
        std::cerr << "EOF";
    }
    else
    {
        std::cerr << '\\' << c2;
    }

    if (v != "")
    {
        std::cerr << "). Expecting a char in \"" << v << "\"." << std::endl;
    }
    else
    {
        std::cerr << "). Expecting '" << (char)c << "'." << std::endl;
    }
    return false;
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::parse_Node()
{
    extract_spaces();
    int c = _in.peek();
    switch (c)
    {
    case '{':
        return parse_ObjectNode();
    case '[':
        return parse_ArrayNode();
    case '"':
        return parse_StringLeaf();
        //        case 'n':
        //            return parse_constant("null");
    case 'f':
        return parse_constant("false");
    case 't':
        return parse_constant("true");
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'e':
    case 'E':
    case '.':
    case '-':
    case '+':
        return parse_IntLeaf();
    default:
        check_next_char_equals(-123456789, "{[\"nft0123456789eE.-+");
        return nullptr;
    }
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::parse_constant(std::string_view target)
{
    char c[6];
    for (size_t x = 0; x < target.size(); x++)
    {
        _in >> c[x];
        if (c[x] != target[x])
        {
            c[x + 1] = '\0';
            /*std::cerr << "Expecting JSON value (probably constant " << target << ") at position "
                      << (_in.tellg() - (long)x) << ". Got string starting with " << c << std::endl;*/
            return nullptr;
        }
    }
    //        if (target == "null")
    //            return NullNode::make_ptr();
    if (target == "true")
        return IntLeaf::make_ptr(1);
    if (target == "false")
        return IntLeaf::make_ptr(0);
    return nullptr;
}

// DO NOT MODIFY THIS FILE !

std::optional<std::string> JsonParser::extract_string()
{
    extract_spaces();
    check_next_char_equals('"');
    std::string s = "";
    char        c = '\0';
    while (((c = _in.get()) != '"') && !_in.eof())
    {
        s += c;
        if (c == '\\') /* If c is a '\' then the next char is escaped. */
        {
            c = _in.get();
            if (_in.eof())
                break;
            s += _in.get();
        }
    }

    if (_in.eof())
    {
        std::cerr << "Found EOF while looking for closing \"." << std::endl;
        return std::optional<std::string>();
    }
    return s;
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::parse_StringLeaf()
{
    auto str = extract_string();
    if (str)
        return StringLeaf::make_ptr(std::move(str.value()));
    else
        return nullptr;
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::parse_IntLeaf()
{
    // unsigned starting_pos = _in.tellg();

    double d;
    _in >> d;
    // size_t end_pos_double = _in.tellg();

    return IntLeaf::make_ptr(d);
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::parse_ArrayNode()
{
    if (!check_next_char_equals('['))
        return nullptr;
    auto arrayNode = ArrayNode::make_ptr();
    extract_spaces();
    if (_in.peek() == ']')
    {
        _in.get();
        return arrayNode;
    }

    do
    {
        auto child = parse_Node();
        if (child == nullptr)
            return nullptr;
        else
            arrayNode->push_back(std::move(child));
        extract_spaces();
    }
    while (_in.get() == ',');

    _in.unget();
    if (check_next_char_equals(']', ",]"))
        return arrayNode;
    else
        return nullptr;
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::parse_ObjectNode()
{
    if (!check_next_char_equals('{'))
        return nullptr;
    auto objectNode = ObjectNode::make_ptr();
    extract_spaces();
    if (_in.peek() == '}')
    {
        _in.get();
        return objectNode;
    }

    do
    {
        std::optional<std::string> opt_key = extract_string();
        if (!opt_key)
            return nullptr;
        extract_spaces();
        if (!check_next_char_equals(':'))
            return nullptr;
        auto child = parse_Node();
        if (child == nullptr)
            return nullptr;
        else
            objectNode->insert(std::move(opt_key.value()), std::move(child));
        extract_spaces();
    }
    while (_in.get() == ',');
    _in.unget();
    if (check_next_char_equals('}', ",}"))
        return objectNode;
    else
        return nullptr;
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::run()
{
    return parse_Node();
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::parse_from_istream(std::istream& in)
{
    JsonParser            parser(in);
    std::unique_ptr<Node> parsed_tree = parser.run();
    if (parsed_tree)
        return parsed_tree;
    else
        exit(EXIT_FAILURE);
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::parse_from_file(std::string const& path)
{
    std::ifstream in(path.c_str(), std::ifstream::in);
    if (!in.is_open())
    {
        std::cerr << "Could not open file: " << path << std::endl;
        exit(EXIT_FAILURE);
    }
    return parse_from_istream(in);
}

// DO NOT MODIFY THIS FILE !

std::unique_ptr<Node> JsonParser::parse_from_string(std::string const& str)
{
    std::stringstream ss { str };
    return parse_from_istream(ss);
}

// DO NOT MODIFY THIS FILE !