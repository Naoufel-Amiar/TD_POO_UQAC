#include <iostream>
#include "AllFiles.h"

int main()
{
    // ==================== CREATION DES LIVRES ====================

    Book dune("Dune", "Frank Herbert");
    Book fondation("Fondation", "Isaac Asimov");
    Book petitPrince("Le Petit Prince", "Antoine de Saint-Exupery");
    Book livre1984("1984", "George Orwell");
    Book miserables("Les Miserables", "Victor Hugo");
    Book etranger("L'Etranger", "Albert Camus");


    // ==================== CREATION DES ETUDIANTS ====================

    Student marie("Marie Tremblay", 1);
    Student hugo("Hugo Lambert", 2);


    // Permet d'afficher true / false au lieu de 1 / 0
    std::cout << std::boolalpha;


    // ==================== LIVRES DE LA BIBLIOTHEQUE ====================

    std::cout << "=== Livres de la bibliotheque ===" << std::endl;

    std::cout << dune.GetTitle()
        << " par " << dune.GetAuthor()
        << " : disponible = " << dune.IsAvailable()
        << std::endl;

    std::cout << fondation.GetTitle()
        << " par " << fondation.GetAuthor()
        << " : disponible = " << fondation.IsAvailable()
        << std::endl;


    // ==================== TEST LIVRE DEJA EMPRUNTE ====================

    std::cout << "\n=== Test livre deja emprunte ===" << std::endl;

    bool testMarieDune = marie.BorrowBook(dune);

    std::cout << "Marie emprunte Dune : "
        << testMarieDune << std::endl;

    bool testHugoDune = hugo.BorrowBook(dune);

    std::cout << "Hugo essaie d'emprunter Dune : "
        << testHugoDune << std::endl;


    // Marie rend Dune pour commencer les tests suivants avec 0 livre
    bool retourDune = marie.ReturnBook(dune);

    std::cout << "Marie rend Dune : "
        << retourDune << std::endl;

    std::cout << "Dune disponible apres retour : "
        << dune.IsAvailable() << std::endl;


    // ==================== TEST LIMITE DE 5 LIVRES ====================

    std::cout << "\n=== Test limite de 5 livres ===" << std::endl;

    std::cout << "Emprunt 1 (Dune) : "
        << marie.BorrowBook(dune) << std::endl;

    std::cout << "Emprunt 2 (Fondation) : "
        << marie.BorrowBook(fondation) << std::endl;

    std::cout << "Emprunt 3 (Le Petit Prince) : "
        << marie.BorrowBook(petitPrince) << std::endl;

    std::cout << "Emprunt 4 (1984) : "
        << marie.BorrowBook(livre1984) << std::endl;

    std::cout << "Emprunt 5 (Les Miserables) : "
        << marie.BorrowBook(miserables) << std::endl;

    std::cout << "Emprunt 6 (L'Etranger) : "
        << marie.BorrowBook(etranger) << std::endl;


    // ==================== VERIFICATION DE LA LIMITE ====================

    std::cout << "\n=== Verification de la limite ===" << std::endl;

    std::cout << "CanBorrow apres 5 emprunts : "
        << marie.CanBorrow() << std::endl;

    std::cout << "Nombre de livres de Marie : "
        << marie.GetBorrowedCount() << std::endl;


    // ==================== TEST DES RETOURS ====================

    std::cout << "\n=== Test des retours ===" << std::endl;

    std::cout << "Marie rend Dune : "
        << marie.ReturnBook(dune) << std::endl;

    // Dune a deja ete rendu, donc ce deuxieme retour doit echouer
    std::cout << "Marie essaie de rendre Dune une deuxieme fois : "
        << marie.ReturnBook(dune) << std::endl;


    // ==================== NOUVEL EMPRUNT APRES RETOUR ====================

    std::cout << "\n=== Emprunt apres liberation d'une place ===" << std::endl;

    std::cout << "Marie emprunte L'Etranger : "
        << marie.BorrowBook(etranger) << std::endl;


    // ==================== ETAT FINAL ====================

    std::cout << "\n=== Etat final ===" << std::endl;

    std::cout << marie.GetName()
        << " : " << marie.GetBorrowedCount()
        << "/5 livres" << std::endl;

    std::cout << hugo.GetName()
        << " : " << hugo.GetBorrowedCount()
        << "/5 livres" << std::endl;


    return 0;
}