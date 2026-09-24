#include <iostream>
#include "AllFiles.h"

// Convertit un booleen en texte pour afficher True ou False
std::string BoolToString(bool value)
{
    return value ? "True" : "False";
}

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

    std::cout << "Nombre d'etudiants crees : "
        << Student::GetStudentCount()
        << std::endl;


    // ==================== LIVRES DE LA BIBLIOTHEQUE ====================

    std::cout << "=== Livres de la bibliotheque ===" << std::endl;

    std::cout << dune.GetTitle()
        << " par " << dune.GetAuthor()
        << " : disponible = "
        << BoolToString(dune.IsAvailable())
        << std::endl;

    std::cout << fondation.GetTitle()
        << " par " << fondation.GetAuthor()
        << " : disponible = "
        << BoolToString(fondation.IsAvailable())
        << std::endl;


    // ==================== TEST LIVRE DEJA EMPRUNTE ====================

    std::cout << "\n=== Test livre deja emprunte ===" << std::endl;

    // Statut avant l'emprunt
    std::cout << "Statut de Dune avant emprunt : "
        << (dune.IsAvailable() ? "Disponible" : "Emprunte")
        << std::endl;

    bool testMarieDune = marie.BorrowBook(dune);

    std::cout << "Marie emprunte Dune : "
        << BoolToString(testMarieDune)
        << std::endl;

    // Statut apres l'emprunt
    std::cout << "Statut de Dune apres emprunt : "
        << (dune.IsAvailable() ? "Disponible" : "Emprunte")
        << std::endl;

    bool testHugoDune = hugo.BorrowBook(dune);

    std::cout << "Hugo essaie d'emprunter Dune : "
        << BoolToString(testHugoDune)
        << std::endl;


    // ==================== TEST DU RETOUR ====================

    // Statut avant le retour
    std::cout << "Statut de Dune avant retour : "
        << (dune.IsAvailable() ? "Disponible" : "Emprunte")
        << std::endl;

    bool retourDune = marie.ReturnBook(dune);

    std::cout << "Marie rend Dune : "
        << BoolToString(retourDune)
        << std::endl;

    // Statut apres le retour
    std::cout << "Statut de Dune apres retour : "
        << (dune.IsAvailable() ? "Disponible" : "Emprunte")
        << std::endl;


    // ==================== TEST LIMITE DE 5 LIVRES ====================

    std::cout << "\n=== Test limite de 5 livres ===" << std::endl;

    std::cout << "Emprunt 1 (Dune) : "
        << BoolToString(marie.BorrowBook(dune))
        << std::endl;

    std::cout << "Emprunt 2 (Fondation) : "
        << BoolToString(marie.BorrowBook(fondation))
        << std::endl;

    std::cout << "Emprunt 3 (Le Petit Prince) : "
        << BoolToString(marie.BorrowBook(petitPrince))
        << std::endl;

    std::cout << "Emprunt 4 (1984) : "
        << BoolToString(marie.BorrowBook(livre1984))
        << std::endl;

    std::cout << "Emprunt 5 (Les Miserables) : "
        << BoolToString(marie.BorrowBook(miserables))
        << std::endl;

    std::cout << "Emprunt 6 (L'Etranger) : "
        << BoolToString(marie.BorrowBook(etranger))
        << std::endl;


    // ==================== VERIFICATION DE LA LIMITE ====================

    std::cout << "\n=== Verification de la limite ===" << std::endl;

    std::cout << "CanBorrow apres 5 emprunts : "
        << BoolToString(marie.CanBorrow())
        << std::endl;

    std::cout << "Nombre de livres de Marie : "
        << marie.GetBorrowedCount()
        << std::endl;

    std::cout << "Liste des livres de Marie :" << std::endl;
    marie.DisplayBorrowedBooks();


    // ==================== TEST DES RETOURS ====================

    std::cout << "\n=== Test des retours ===" << std::endl;

    std::cout << "Marie rend Dune : "
        << BoolToString(marie.ReturnBook(dune))
        << std::endl;

    // L'Etranger n'a pas ete emprunte par Marie
    std::cout << "Marie essaie de rendre un livre non emprunte (L'Etranger) : "
        << BoolToString(marie.ReturnBook(etranger))
        << std::endl;


    // ==================== NOUVEL EMPRUNT APRES RETOUR ====================

    std::cout << "\n=== Emprunt apres liberation d'une place ===" << std::endl;

    std::cout << "Marie emprunte L'Etranger : "
        << BoolToString(marie.BorrowBook(etranger))
        << std::endl;


    // ==================== ETAT FINAL ====================

    std::cout << "\n=== Etat final ===" << std::endl;

    std::cout << "Etudiant " << marie.GetId()
        << " (" << marie.GetName() << ") : "
        << marie.GetBorrowedCount()
        << " / 5 livre(s)"
        << std::endl;

    marie.DisplayBorrowedBooks();

    std::cout << std::endl;

    std::cout << "Etudiant " << hugo.GetId()
        << " (" << hugo.GetName() << ") : "
        << hugo.GetBorrowedCount()
        << " / 5 livre(s)"
        << std::endl;

    hugo.DisplayBorrowedBooks();

    return 0;
}