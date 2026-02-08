#include <iostream>
#include "repositories/BookRepository.h"
#include "repositories/UserRepository.h"
#include "repositories/LoanRepository.h"
#include "services/LibraryService.h"
#include "strategies/NormalFineStrategy.h"

int main()
{
    BookRepository bookRepo;
    UserRepository userRepo;
    LoanRepository loanRepo;
    NormalFineStrategy fineStrategy;

    LoanService loanService(&loanRepo, &fineStrategy);
    LibraryService library(&bookRepo, &userRepo, &loanService);

    User *u = new User("Raj", UserRole::MEMBER);
    library.addUser(u);

    User *u1 = new User("Ankit", UserRole::MEMBER);
    library.addUser(u1);

    User *u3 = new User("Abhay", UserRole::MEMBER);
    library.addUser(u3);

    Book *b1 = new Book("Math", "Author A");
    library.addBook(b1, 1); // two copies

    library.borrowBook(u->getId(), "Math");

    library.borrowBook(u1->getId(), "Math");

    library.borrowBook(u3->getId(), "Math");

    int fine = library.returnBook(1);
    std::cout << "Fine: " << fine << std::endl;

    return 0;
}