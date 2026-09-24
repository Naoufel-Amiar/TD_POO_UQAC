#pragma once

#include <iostream>
#include <string>


// ==================== STATUT D'UN LIVRE ====================

enum class BookStatus
{
    Available,
    Borrowed
};


// ==================== CLASSE BOOK ====================

class Book
{
private:
    std::string title_;
    std::string author_;
    BookStatus status_;

public:
    Book(std::string title, std::string author);

    std::string GetTitle() const;
    std::string GetAuthor() const;
    BookStatus GetStatus() const;

    bool IsAvailable() const;

    bool Checkout();
    bool Return();
};


// ==================== INFORMATIONS D'UN LIVRE EMPRUNTE ====================

struct BorrowedBook
{
    std::string title;
    std::string author;
};


// ==================== CLASSE STUDENT ====================

class Student
{
private:
    std::string name_;
    int id_;

    static constexpr int MAX_BOOKS = 5;
    static int studentCount_;

    BorrowedBook borrowedBooks_[MAX_BOOKS];
    int borrowedCount_;

public:
    Student(std::string name, int id);

    std::string GetName() const;
    int GetId() const;
    inline int GetBorrowedCount() const
    {
        return borrowedCount_;
    }

    static int GetStudentCount();
    bool CanBorrow() const;

    bool BorrowBook(Book& book);
    bool ReturnBook(Book& book);

    void DisplayBorrowedBooks() const;
};