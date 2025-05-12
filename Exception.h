#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include<exception>
#include<string>
#include<iostream>
#include <memory>
#include <cstring>

class DeckFileNotFound:public std::exception
{
public:
    DeckFileNotFound()
    {
        m_message ="Deck File Error: File not found";
    }

    const char* what() const noexcept override
    {
        return m_message.c_str();
    }

private:
    std::string m_message;
};

class DeckFileFormatError :public std::exception
{
public:
    DeckFileFormatError(int line):m_line(line)
    {
        m_message ="Deck File Error: File format error in line "+ std::to_string(m_line);
    }

    const char* what() const noexcept override
    {
        return m_message.c_str();
    }

private:
    int m_line;
    std::string m_message;
};

class DeckFileInvalidSize: public std::exception
{
public:
    DeckFileInvalidSize()
    {
        m_message ="Deck File Error: Deck size is invalid";
    }

    const char* what() const noexcept override
    {
        return m_message.c_str();
    }

private:
    std::string m_message;
};


#endif //EX4_EXCEPTION_H



