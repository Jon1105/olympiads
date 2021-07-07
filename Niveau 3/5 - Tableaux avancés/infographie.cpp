#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    size_t nbLignes, nbColonnes, nbRectangles;
    std::cin >> nbLignes >> nbColonnes;
    std::cin >> nbRectangles;
    // char canvas[nbLignes][nbColonnes] = {{0}};
    std::vector<std::vector<char>> canvas(nbLignes, std::vector<char>(nbColonnes, '.'));
    
    for (size_t i = 0; i < nbRectangles; i++) {
        size_t iLig1, iCol1, iLig2, iCol2;
        char couleur;
        std::cin >> iLig1 >> iCol1 >> iLig2 >> iCol2 >> couleur;

        for (size_t i = iLig1; i <= iLig2; i++) {
            for (size_t j = iCol1; j <= iCol2; j++) {
                canvas[i][j] = couleur;
            }
            
        }
    }
    // PRINT CANVAS
    for (size_t i = 0; i < nbLignes; i++)
    {
        for (size_t j = 0; j < nbColonnes; j++)
        {
            std::cout << canvas[i][j];
        }
        std::cout << '\n';
    }
    
    return 0;
}