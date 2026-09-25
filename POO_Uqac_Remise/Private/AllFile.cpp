#include "AllFiles.h"

Book::Book(std::string title, std::string author)
    : title_{ title },
    author_{ author },
    status_{ BookStatus::Available }
{
}

std::string Book::GetTitle() const
{
    return title_;
}

std::string Book::GetAuthor() const
{
    return author_;
}

BookStatus Book::GetStatus() const
{
    return status_;
}

bool Book::IsAvailable() const
{
    return status_ == BookStatus::Available;
}

bool Book::Checkout()
{
    if (!IsAvailable())
    {
        return false;
    }

    status_ = BookStatus::Borrowed;
    return true;
}

bool Book::Return()
{
    if (IsAvailable())
    {
        return false;
    }

    status_ = BookStatus::Available;
    return true;
}

// ==================== STUDENT ====================
int Student::studentCount_ = 0;

Student::Student(std::string name, int id)
    : name_{ name },
    id_{ id },
    borrowedCount_{ 0 }
{
    studentCount_++;
}

std::string Student::GetName() const
{
    return name_;
}

int Student::GetId() const
{
    return id_;
}

int Student::GetStudentCount()
{
    return studentCount_;
}

bool Student::CanBorrow() const
{
    return borrowedCount_ < MAX_BOOKS;
}

bool Student::BorrowBook(Book& book)
{
    // L'etudiant ne peut pas depasser 5 livres
    if (!CanBorrow())
    {
        return false;
    }

    // Le livre doit etre disponible
    if (!book.IsAvailable())
    {
        return false;
    }

    // On ajoute les informations du livre dans le tableau
    borrowedBooks_[borrowedCount_].title = book.GetTitle();
    borrowedBooks_[borrowedCount_].author = book.GetAuthor();

    // Le livre devient emprunte
    book.Checkout();

    // L'etudiant possede maintenant un livre de plus
    borrowedCount_++;

    return true;
}

bool Student::ReturnBook(Book& book)
{
    // On cherche le livre dans le tableau de l'etudiant
    for (int i = 0; i < borrowedCount_; i++)
    {
        if (borrowedBooks_[i].title == book.GetTitle())
        {
            // On decale les livres suivants vers la gauche
            for (int j = i; j < borrowedCount_ - 1; j++)
            {
                borrowedBooks_[j] = borrowedBooks_[j + 1];
            }

            // L'etudiant possede maintenant un livre de moins
            borrowedCount_--;

            // Le livre redevient disponible
            book.Return();

            return true;
        }
    }

    // Le livre n'etait pas dans le tableau de l'etudiant
    return false;
}

void Student::DisplayBorrowedBooks() const
{
    for (int i = 0; i < borrowedCount_; i++)
    {
        std::cout << "- " << borrowedBooks_[i].title << std::endl;
    }
}