#include <iostream>
#include "Base.h"

using namespace std;

// класс Book
// конструктор по умолчанию
Book::Book()
{
    this->name = "NONE"; // название
    this->author = "NONE"; // автор
    this->year = "NONE"; // год выпуска
    this->annotation = "NONE"; // аннотация
    this->genre = "NONE"; // жанр
    this->volume_of_page = 0; // объем страниц
    this->cost = 0; // цена

    cout << "Вызван конструктор по умолчанию класса - Book" << endl;
}

// конструктор с параметром
Book::Book(string name, string author, string year, string annotation, string genre, int volume_of_page, float cost)
{
    this->name = name; // название
    this->author = author; // автор
    this->year = year; // год выпуска
    this->annotation = annotation; // аннотация
    this->genre = genre; // жанр
    this->volume_of_page = volume_of_page; // объем страниц
    this->cost = cost; // цена

    cout << "Вызван конструктор с параметром класса - Book" << endl;
}

// конструктор копирования
Book::Book(const Book &B)
{
    this->name = B.name; // название
    this->author = B.author; // автор
    this->year = B.year; // год выпуска
    this->annotation = B.annotation; // аннотация
    this->genre = B.genre; // жанр
    this->volume_of_page = B.volume_of_page; // объем страниц
    this->cost = B.cost; // цена

    cout << "Вызван конструктор копирования класса - Book" << endl;
}

// деструктор
Book::~Book()
{
    cout << "Вызван деструктор класса - Book" << endl;
}

// основные методы
// метод установки значения
void Book::Set()
{
    cout << "Введите данные о книге:" << endl;

    cout << "Название: ";
    cin >> this->name;

    cout << "Автор: ";
    cin >> this->author;

    cout << "Год выпуска: ";
    try
    {
        cin >> year;
        for (int i = 0; i < year.size(); i++)
        {
            if ((year[i] >= 'A' and year[i] <= 'Z') or year[i] == '.' or
            year[i] == ',' or year[i] == '`' or year[i] == '~' or year[i] == '+' or
            year[i] == '=' or year[i] == '_' or year[i] == '&' or year[i] == '$' or
            year[i] == '#' or year[i] == '@' or year[i] == '!' or year[i] == '^' or
            year[i] == '<' or year[i] == '>' or year[i] == '№' or
            (year[i] >= 'А' and year[i] <= 'Я')) throw "Error";
        }
    }
    catch(const std::exception& e)
    {
        cout << "Неверный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверно введен год" << endl;
    }

    cout << "Аннотация: ";
    cin >> this->annotation;

    cout << "Жанр: ";
    cin >> this->genre;

    cout << "Объем страниц: ";
    try
    {
        cin >> this->volume_of_page;
        if (this->volume_of_page < 1) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверно введен объем" << endl;
    }

    cout << "Цена: ";
    try
    {
        cin >> this->cost;
        if (this->cost < 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверно введена цена" << endl;
    }
}

// метод получения значений
void Book::Get()
{
    cout << "~~~Информация о книге~~~" << endl;
    cout << "Название: " << this->name << endl;
    cout << "Автор: " << this->author << endl;
    cout << "Год выпуска: " << this->year << endl;
    cout << "Аннотация: " << this->annotation << endl;
    cout << "Жанр: " << this->genre << endl;
    cout << "Объем страниц: " << this->volume_of_page << endl;
    cout << "Цена: " << this->cost << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

// метод удаления данных
void Book::Delete()
{
    this->name = "NONE"; // название
    this->author = "NONE"; // автор
    this->year = "NONE"; // год выпуска
    this->annotation = "NONE"; // аннотация
    this->genre = "NONE"; // жанр
    this->volume_of_page = 0; // объем страниц
    this->cost = 0; // цена
}

// метод изменения данных
void Book::Change()
{
    cout << "Выберите, что вы хотите изменить:" << endl;
    cout << "1 - Название \n"
         << "2 - Автор \n"
         << "3 - Год выпуска \n"
         << "4 - Аннотация \n"
         << "5 - Жанр \n"
         << "6 - Объем страниц \n"
         << "7 - Цена \n"
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    int choice;

    try
    {
        cin >> choice;
        if (choice < 1 or choice > 7) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == 1)
    {
        cout << "Название: ";
        cin >> this->name;
    }

    else if (choice == 2)
    {
        cout << "Автор: ";
        cin >> this->author;
    }

    else if (choice == 3)
    {
        cout << "Год выпуска: ";
        try
        {
            cin >> year;
            for (int i = 0; i < year.size(); i++)
            {
                if ((year[i] >= 'A' and year[i] <= 'Z') or year[i] == '.' or
                year[i] == ',' or year[i] == '`' or year[i] == '~' or year[i] == '+' or
                year[i] == '=' or year[i] == '_' or year[i] == '&' or year[i] == '$' or
                year[i] == '#' or year[i] == '@' or year[i] == '!' or year[i] == '^' or
                year[i] == '<' or year[i] == '>' or year[i] == '№' or
                (year[i] >= 'А' and year[i] <= 'Я')) throw "Error";
            }
        }
        catch(const std::exception& e)
        {
            cout << "Неверный ввод" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Неверно введен год" << endl;
        }
    }

    else if (choice == 4)
    {
        cout << "Аннотация: ";
        cin >> this->annotation;
    }

    else if (choice == 5)
    {
        cout << "Жанр: ";
        cin >> this->genre;
    }

    else if (choice == 6)
    {
        cout << "Объем страниц: ";
        try
        {
            cin >> this->volume_of_page;
            if (this->volume_of_page < 1) throw "Error";
        }
        catch(const std::exception& e)
        {
            cout << "Некорректный ввод" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Неверно введен объем" << endl;
        }
    }

    else
    {
        cout << "Цена: ";
        try
        {
            cin >> this->cost;
            if (this->cost < 0) throw "Error";
        }
        catch(const std::exception& e)
        {
            cout << "Некорректный ввод" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Неверно введена цена" << endl;
        }
    }
}

// класс StudyBook
// конструктор по умолчанию
StudyBook::StudyBook()
{
    this->name = "NONE"; // название
    this->author = "NONE"; // автор
    this->year = "NONE"; // год выпуска
    this->educational_institution = "NONE"; // учебное заведение
    this->year_of_study = "NONE"; // год обучения
    this->volume_of_page = 0; // объем страниц
    this->cost = 0; // цена

    cout << "Вызван конструктор по умолчанию класса - StudyBook" << endl;
}

// конструктор с параметром
StudyBook::StudyBook(string name, string author, string year, string educational_institution, string year_of_study, int volume_of_page, float cost)
{
    this->name = name; // название
    this->author = author; // автор
    this->year = year; // год выпуска
    this->educational_institution = educational_institution; // учебное заведение
    this->year_of_study = year_of_study; // год обучения
    this->volume_of_page = volume_of_page; // объем страниц
    this->cost = cost; // цена

    cout << "Вызван конструктор с параметром класса - StudyBook" << endl;
}

// конструктор копирования
StudyBook::StudyBook(const StudyBook &S)
{
    this->name = S.name; // название
    this->author = S.author; // автор
    this->year = S.year; // год выпуска
    this->educational_institution = S.educational_institution; // аннотация
    this->year_of_study = S.year_of_study; // жанр
    this->volume_of_page = S.volume_of_page; // объем страниц
    this->cost = S.cost; // цена

    cout << "Вызван конструктор копирования класса - StudyBook" << endl;
}

// деструктор
StudyBook::~StudyBook()
{
    cout << "Вызван деструктор класса - StudyBook" << endl;
}

// основные методы
// метод установки значения
void StudyBook::Set()
{
    cout << "Введите данные о книге:" << endl;

    cout << "Название: ";
    cin >> this->name;

    cout << "Автор: ";
    cin >> this->author;

    cout << "Год выпуска: ";
    try
    {
        cin >> year;
        for (int i = 0; i < year.size(); i++)
        {
            if ((year[i] >= 'A' and year[i] <= 'Z') or year[i] == '.' or
            year[i] == ',' or year[i] == '`' or year[i] == '~' or year[i] == '+' or
            year[i] == '=' or year[i] == '_' or year[i] == '&' or year[i] == '$' or
            year[i] == '#' or year[i] == '@' or year[i] == '!' or year[i] == '^' or
            year[i] == '<' or year[i] == '>' or year[i] == '№' or
            (year[i] >= 'А' and year[i] <= 'Я')) throw "Error";
        }
    }
    catch(const std::exception& e)
    {
        cout << "Неверный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверно введен год" << endl;
    }

    cout << "Учебное заведение: ";
    cin >> educational_institution;

    cout << "Год обучения: ";
    try
    {
        cin >> year_of_study;
        for (int i = 0; i < year.size(); i++)
        {
            if ((year[i] >= 'A' and year[i] <= 'Z') or year[i] == '.' or
            year[i] == ',' or year[i] == '`' or year[i] == '~' or year[i] == '+' or
            year[i] == '=' or year[i] == '_' or year[i] == '&' or year[i] == '$' or
            year[i] == '#' or year[i] == '@' or year[i] == '!' or year[i] == '^' or
            year[i] == '<' or year[i] == '>' or year[i] == '№' or
            (year[i] >= 'А' and year[i] <= 'Я')) throw "Error";
        }
    }
    catch(const std::exception& e)
    {
        cout << "Неверный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверно введен год" << endl;
    }

    cout << "Объем страниц: ";
    try
    {
        cin >> this->volume_of_page;
        if (this->volume_of_page < 1) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверно введен объем" << endl;
    }

    cout << "Цена: ";
    try
    {
        cin >> this->cost;
        if (this->cost < 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверно введена цена" << endl;
    }
}

// метод получения значений
void StudyBook::Get()
{
    cout << "~~~Информация об учебнике~~~" << endl;
    cout << "Название: " << this->name << endl;
    cout << "Автор: " << this->author << endl;
    cout << "Год выпуска: " << this->year << endl;
    cout << "Учебное заведение: " << this->educational_institution << endl;
    cout << "Год обучения: " << this->year_of_study << endl;
    cout << "Объем страниц: " << this->volume_of_page << endl;
    cout << "Цена: " << this->cost << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

// метод удаления данных
void StudyBook::Delete()
{
    this->name = "NONE"; // название
    this->author = "NONE"; // автор
    this->year = "NONE"; // год выпуска
    this->educational_institution = "NONE"; // аннотация
    this->year_of_study = "NONE"; // жанр
    this->volume_of_page = 0; // объем страниц
    this->cost = 0; // цена
}

// метод изменения данных
void StudyBook::Change()
{
    cout << "Выберите, что вы хотите изменить:" << endl;
    cout << "1 - Название \n"
         << "2 - Автор \n"
         << "3 - Год выпуска \n"
         << "4 - Учебное заведение \n"
         << "5 - Год обучения \n"
         << "6 - Объем страниц \n"
         << "7 - Цена \n"
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    int choice;

    try
    {
        cin >> choice;
        if (choice < 1 or choice > 7) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == 1)
    {
        cout << "Название: ";
        cin >> this->name;
    }

    else if (choice == 2)
    {
        cout << "Автор: ";
        cin >> this->author;
    }

    else if (choice == 3)
    {
        cout << "Год выпуска: ";
        try
        {
            cin >> year;
            for (int i = 0; i < year.size(); i++)
            {
                if ((year[i] >= 'A' and year[i] <= 'Z') or year[i] == '.' or
                year[i] == ',' or year[i] == '`' or year[i] == '~' or year[i] == '+' or
                year[i] == '=' or year[i] == '_' or year[i] == '&' or year[i] == '$' or
                year[i] == '#' or year[i] == '@' or year[i] == '!' or year[i] == '^' or
                year[i] == '<' or year[i] == '>' or year[i] == '№' or
                (year[i] >= 'А' and year[i] <= 'Я')) throw "Error";
            }
        }
        catch(const std::exception& e)
        {
            cout << "Некорректный ввод" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Неверно введен год" << endl;
        }
    }

    else if (choice == 4)
    {
        cout << "Учебное заведение: ";
        cin >> educational_institution;
    }

    else if (choice == 5)
    {
        cout << "Год обучения: ";
        try
        {
            cin >> year_of_study;
            for (int i = 0; i < year_of_study.size(); i++)
            {
                if ((year_of_study[i] >= 'A' and year_of_study[i] <= 'Z') or year_of_study[i] == '.' or
                year_of_study[i] == ',' or year_of_study[i] == '`' or year_of_study[i] == '~' or year_of_study[i] == '+' or
                year_of_study[i] == '=' or year_of_study[i] == '_' or year_of_study[i] == '&' or year_of_study[i] == '$' or
                year_of_study[i] == '#' or year_of_study[i] == '@' or year_of_study[i] == '!' or year_of_study[i] == '^' or
                year_of_study[i] == '<' or year_of_study[i] == '>' or year_of_study[i] == '№' or
                (year_of_study[i] >= 'А' and year_of_study[i] <= 'Я')) throw "Error";
            }
        }
        catch(const std::exception& e)
        {
            cout << "Некорректный ввод" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Неверно введен год" << endl;
        }
    }

    else if (choice == 6)
    {
        cout << "Объем страниц: ";
        try
        {
            cin >> this->volume_of_page;
            if (this->volume_of_page < 1) throw "Error";
        }
        catch(const std::exception& e)
        {
            cout << "Некорректный ввод" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Неверно введен объем" << endl;
        }
    }

    else
    {
        cout << "Цена: ";
        try
        {
            cin >> this->cost;
            if (this->cost < 0) throw "Error";
        }
        catch(const std::exception& e)
        {
            cout << "Некорректный ввод" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Неверно введена цена" << endl;
        }
    }
}

// класс Chancellery
// конструктор по умолчанию
Chancellery::Chancellery()
{
    this->type = "NONE"; // название
    this->color = "NONE"; // автор
    this->appointment = "NONE"; // год выпуска
    this->cost = 0; // аннотация

    cout << "Вызван конструктор по умолчанию класса - Chancellery" << endl;
}

// конструктор с параметром
Chancellery::Chancellery(string type, string color, string appointment, float cost)
{
    this->type = type; // название
    this->color = color; // автор
    this->appointment = appointment; // год выпуска
    this->cost = cost; // аннотация

    cout << "Вызван конструктор с параметром класса - Chancellery" << endl;
}

// конструктор копирования
Chancellery::Chancellery(const Chancellery &C)
{
    this->type = C.type; // название
    this->color = C.color; // автор
    this->appointment = C.appointment; // год выпуска
    this->cost = C.cost; // аннотация

    cout << "Вызван конструктор копирования класса - Chancellery" << endl;
}

// деструктор
Chancellery::~Chancellery()
{
    cout << "Вызван деструктор класса - Chancellery" << endl;
}

// основные методы
// метод установки значения
void Chancellery::Set()
{
    cout << "Введите данные о канцелярии:" << endl;

    cout << "Тип: ";
    cin >> this->type;

    cout << "Цвет: ";
    cin >> this->color;

    cout << "Назначение: ";
    cin >> appointment;

    cout << "Цена: ";
    try
    {
        cin >> this->cost;
        if (this->cost < 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверно введена цена" << endl;
    }
}

// метод получения значений
void Chancellery::Get()
{
    cout << "~~~Информация о канцелярии~~~" << endl;
    cout << "Тип: " << this->type << endl;
    cout << "Цвет: " << this->color << endl;
    cout << "Назначение: " << this->appointment << endl;
    cout << "Цена: " << this->cost << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

// метод удаления данных
void Chancellery::Delete()
{
    this->type = "NONE"; // название
    this->color = "NONE"; // автор
    this->appointment = "NONE"; // год выпуска
    this->cost = 0; // аннотация
}

// метод изменения данных
void Chancellery::Change()
{
    cout << "Выберите, что вы хотите изменить:" << endl;
    cout << "1 - Тип \n"
         << "2 - Цвет \n"
         << "3 - Назначение \n"
         << "4 - Цена \n"
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    int choice;

    try
    {
        cin >> choice;
        if (choice < 1 or choice > 7) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == 1)
    {
        cout << "Тип: ";
        cin >> this->type;
    }

    else if (choice == 2)
    {
        cout << "Цвет: ";
        cin >> this->color;
    }

    else if (choice == 3)
    {
        cout << "Назначение: ";
        cin >> appointment;
    }

    else
    {
        cout << "Цена: ";
        try
        {
            cin >> this->cost;
            if (this->cost < 0) throw "Error";
        }
        catch(const std::exception& e)
        {
            cout << "Некорректный ввод" << endl;
        }
        catch(const char*mssg)
        {
            cout << "Неверно введена цена" << endl;
        }
    }
}
