#include "AllFiles.h"

int main()
{
    Book dune("Dune", "Frank Herbert");

    std::cout << "Titre : " << dune.GetTitle() << std::endl;
    std::cout << "Auteur : " << dune.GetAuthor() << std::endl;

    std::cout << "Disponible au depart : "
        << dune.IsAvailable() << std::endl;

    bool emprunt1 = dune.Checkout();

    std::cout << "Premier emprunt : "
        << emprunt1 << std::endl;

    std::cout << "Disponible apres emprunt : "
        << dune.IsAvailable() << std::endl;

    bool emprunt2 = dune.Checkout();

    std::cout << "Deuxieme emprunt : "
        << emprunt2 << std::endl;

    bool retour = dune.Return();

    std::cout << "Retour : "
        << retour << std::endl;

    std::cout << "Disponible apres retour : "
        << dune.IsAvailable() << std::endl;

    return 0;
}