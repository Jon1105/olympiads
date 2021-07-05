// http://www.france-ioi.org/algo/task.php?idChapter=671&idTask=2329

#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    size_t nbLignes, nbColonnes;
    std::cin >> nbLignes >> nbColonnes;
    bool carte[nbLignes][nbColonnes] = {false};
    // std::vector<std::vector<bool>> carte(nbLignes, std::vector<bool>(nbColonnes, false));
    for (size_t i = 0; i < nbLignes; i++)
    {
        for (size_t j = 0; j < nbColonnes; j++)
        {
            std::cin >> carte[i][j];
        }
    }

    throw ;
    
    return 0;
}
