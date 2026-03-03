#include <bits/stdc++.h>
#include "services/UserService.h"
#include "services/AccountService.h"
#include "services/TransactionService.h"

int main()
{
    // Create services
    UserService *userService;
    AccountService *accountService;
    TransactionService *transactionService;

    UserRepository *userRepository = new UserRepository();
    AccountRepository *accountRepository = new AccountRepository();
    TransactionRepository *transactionRepository = new TransactionRepository();

    userService = new UserService();
    accountService = AccountService::getInstance();
    transactionService = TransactionService::getInstance();

    // Create users
    User *user1 = new User("Alice", "alice@gmail.com", "password123");
    User *user2 = new User("Bob", "bob@gmail.com", "password456");

    // Register users
    userService->registerUser(user1);
    userService->registerUser(user2);

    // Create accounts
    Account *account1 = new Account("4111111111111111", 1000.0, user1);
    Account *account2 = new Account("4222222222222222", 500.0, user2);

    // Add accounts to account service
    accountService->createAccount(account1);
    accountService->createAccount(account2);

    // Create transactions
    Transactions *transaction1 = new Transactions(account2, account1, 200.0, TransactionEnum::CREDIT);
    Transactions *transaction2 = new Transactions(account1, account2, 200.0, TransactionEnum::DEBIT);

    transactionService->createTransaction(transaction1);
    transactionService->createTransaction(transaction2);

    vector<Transactions *> transactions = transactionService->getAllTransactions();
    for (Transactions *t : transactions)
    {
        cout << "Transaction: " << t->getAmount() << " from account " << t->getFromAccount()->getAccountNumber() << " to account " << t->getToAccount()->getAccountNumber() << endl;
    }

    return 0;
}