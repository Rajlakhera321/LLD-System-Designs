#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"
#include "../structs/BasicDetailDto.h"

using namespace std;

class BasicDetails : public Section
{
private:
    string name;
    string email;
    string phone;
    vector<unique_ptr<string> > socialLinks;

public:
    BasicDetails(const string &name, const string &email, const string &phone)
        : name(name), email(email), phone(phone) {}

    void addSocialLink(unique_ptr<string> link)
    {
        socialLinks.push_back(move(link));
    }
    SectionType getType() override
    {
        return SectionType::BASIC;
    }

    void update(void *data) override
    {
        BasicDetailDto *dto = static_cast<BasicDetailDto *>(data);

        name = dto->name;
        email = dto->email;
        phone = dto->phone;
    }

    void render() override
    {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        if (!socialLinks.empty())
        {
            cout << "Social Links:" << endl;
            for (const auto &link : socialLinks)
            {
                cout << "- " << *link << endl;
            }
        }
    }
};