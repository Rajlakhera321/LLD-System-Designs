#pragma once
#include <bits/stdc++.h>
#include "IdGenerator.h"
#include "User.h"

using namespace std;

class Payment
{
private:
    int paymentId;
    User *user; // Assuming we have a User class to represent the user making the payment
    double amount;
    string method;
    PaymentStatus status;

public:
    Payment(double amount, string method, PaymentStatus status, User *user) : amount(amount), method(method), status(status), user(user)
    {
        paymentId = IdGenerator::generatePaymentId();
    }

    int getPaymentId() const { return paymentId; }
    double getAmount() const { return amount; }
    string getMethod() const { return method; }
    PaymentStatus getStatus() const { return status; }
    User *getUser() const { return user; }

    void setStatus(PaymentStatus newStatus) { status = newStatus; }
};