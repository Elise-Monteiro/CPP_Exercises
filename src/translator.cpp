#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

std::set<std::string> make_exit_commands()
{
    return {"q", "quit", "e", "exit"};
}

bool instruction(std::istream &input, std::map<std::string, std::string> &dico, std::vector<std::string> &historique, const std::set<std::string> &exit_commands)
{
    std::string commande;
    std::cout << "Entrez une commande :" << std::endl;
    input >> commande;
    if (exit_commands.count(commande) != 0)
    {
        std::cout << "Fin du Programme" << std::endl;
        return false;
    }
    else if (commande == "add")
    {
        std::string w1;
        std::string w2;
        input >> w1;
        input >> w2;
        std::cout << w1 << " => " << w2 << std::endl;
        dico.emplace(w1, w2);
        historique.push_back("add " + w1 + " " + w2);
    }
    else if (commande == "translate")
    {
        std::string line;
        std::getline(input, line);

        auto words = std::stringstream{};
        words << line;
        while (!words.eof())
        {
            std::string word;
            words >> word;
            if (dico.count(word) == 0)
            {
                std::cout << "???" << std::endl;
            }
            else
            {
                std::cout << dico.at(word) << std::endl;
            }
        }
    }
    else if (commande == "print")
    {
        for (auto element : dico)
        {
            std::cout << element.first << " => " << element.second << std::endl;
        }
    }
    else if (commande == "save")
    {
        std::string name;
        input >> name;

        auto file = std::ofstream{name};
        for (auto command : historique)
        {
            file << command << "\n";
        }
    }
    else if (commande == "load")
    {
        std::string name;
        input >> name;

        auto file = std::ifstream{name};
        while (!file.eof())
        {
            instruction(file, dico, historique, exit_commands);
        }
    }
    else if (commande == "clear")
    {
        dico.clear();
        historique.clear();
    }
    else if (commande == "remove")
    {
        std::string word;
        input >> word;
        for (auto it = dico.begin(); it != dico.end();)
        {
            if (it->first == word || it->second == word)
                it = dico.erase(it);
            else
                ++it;
        }
        historique.push_back("remove " + word);
    }
    return true;
}

int main()
{
    const auto exit_commands = make_exit_commands();
    std::map<std::string, std::string> dico;
    std::vector<std::string> historique{};
    while (instruction(std::cin, dico, historique, exit_commands))
    {
    }
    return 0;
}