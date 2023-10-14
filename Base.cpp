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
    this->volume_of_page = "NONE"; // объем страниц
    this->cost = "NONE"; // цена

    cout << "Вызван конструктор по умолчанию класса - Book" << endl;
}

// конструктор с параметром
Book::Book(string name, string author, string year, string annotation, string genre, string volume_of_page, string cost)
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
    cin >> year;

    cout << "Аннотация: ";
    cin >> this->annotation;

    cout << "Жанр: ";
    cin >> this->genre;

    cout << "Объем страниц: ";
    cin >> this->volume_of_page;

    cout << "Цена: ";
    cin >> this->cost;
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
    this->volume_of_page = "NONE"; // объем страниц
    this->cost = "NONE"; // цена
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

    string choice;

    try
    {
        cin >> choice;
        for (int i = 0; i < choice.length(); i++)
        {
            if (choice[i] >= 'A' and choice[i] <= 'Z' or choice[i] >= 'a' and choice[i] <= 'z') throw "Error";
        }
        if (stoi(choice) < 1 or stoi(choice) > 7) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (stoi(choice) == 1)
    {
        cout << "Название: ";
        cin >> this->name;
    }

    else if (stoi(choice) == 2)
    {
        cout << "Автор: ";
        cin >> this->author;
    }

    else if (stoi(choice) == 3)
    {
        cout << "Год выпуска: ";
        cin >> year;
    }

    else if (stoi(choice) == 4)
    {
        cout << "Аннотация: ";
        cin >> this->annotation;
    }

    else if (stoi(choice) == 5)
    {
        cout << "Жанр: ";
        cin >> this->genre;
    }

    else if (stoi(choice) == 6)
    {
        cout << "Объем страниц: ";
        cin >> this->volume_of_page;
    }

    else
    {
        cout << "Цена: ";
        cin >> this->cost;
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
    this->volume_of_page = "NONE"; // объем страниц
    this->cost = "NONE"; // цена

    cout << "Вызван конструктор по умолчанию класса - StudyBook" << endl;
}

// конструктор с параметром
StudyBook::StudyBook(string name, string author, string year, string educational_institution, string year_of_study, string volume_of_page, string cost)
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
    cin >> year;

    cout << "Учебное заведение: ";
    cin >> educational_institution;

    cout << "Год обучения: ";
    cin >> year_of_study;

    cout << "Объем страниц: ";
    cin >> this->volume_of_page;

    cout << "Цена: ";
    cin >> this->cost;
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
    this->volume_of_page = "NONE"; // объем страниц
    this->cost = "NONE"; // цена
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

    string choice;

    try
    {
        cin >> choice;
        for (int i = 0; i < choice.length(); i++)
        {
            if (choice[i] >= 'A' and choice[i] <= 'Z' or choice[i] >= 'a' and choice[i] <= 'z') throw "Error";
        }
        if (stoi(choice) < 1 or stoi(choice) > 7) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (stoi(choice) == 1)
    {
        cout << "Название: ";
        cin >> this->name;
    }

    else if (stoi(choice) == 2)
    {
        cout << "Автор: ";
        cin >> this->author;
    }

    else if (stoi(choice) == 3)
    {
        cout << "Год выпуска: ";
        cin >> year;
    }

    else if (stoi(choice) == 4)
    {
        cout << "Учебное заведение: ";
        cin >> educational_institution;
    }

    else if (stoi(choice) == 5)
    {
        cout << "Год обучения: ";
        cin >> year_of_study;
    }

    else if (stoi(choice) == 6)
    {
        cout << "Объем страниц: ";
        cin >> this->volume_of_page;
    }

    else
    {
        cout << "Цена: ";
        cin >> this->cost;
    }
}

// класс Chancellery
// конструктор по умолчанию
Chancellery::Chancellery()
{
    this->type = "NONE"; // название
    this->color = "NONE"; // автор
    this->appointment = "NONE"; // год выпуска
    this->cost = "NONE"; // аннотация

    cout << "Вызван конструктор по умолчанию класса - Chancellery" << endl;
}

// конструктор с параметром
Chancellery::Chancellery(string type, string color, string appointment, string cost)
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
    cin >> this->cost;
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
    this->cost = "NONE"; // аннотация
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

    string choice;

    try
    {
        cin >> choice;
        for (int i = 0; i < choice.length(); i++)
        {
            if (choice[i] >= 'A' and choice[i] <= 'Z' or choice[i] >= 'a' and choice[i] <= 'z') throw "Error";
        }
        if (stoi(choice) < 1 or stoi(choice) > 4) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (stoi(choice) == 1)
    {
        cout << "Тип: ";
        cin >> this->type;
    }

    else if (stoi(choice) == 2)
    {
        cout << "Цвет: ";
        cin >> this->color;
    }

    else if (stoi(choice) == 3)
    {
        cout << "Назначение: ";
        cin >> appointment;
    }

    else
    {
        cout << "Цена: ";
        cin >> this->cost;
    }
}

// методты GetType

int Book::TypeID()
{
    return 1;
}
int StudyBook::TypeID()
{
    return 2;
}
int Chancellery::TypeID()
{
    return 3;
}

string Book::Save(int count)
{
    if (count == 0) return this->name;
    else if (count == 1) return this->author;
    else if (count == 2) return this->year;
    else if (count == 3) return this->annotation;
    else if (count == 4) return this->genre;
    else if (count == 5) return this->volume_of_page;
    else if (count == 6) return this->cost;
}

string StudyBook::Save(int count)
{
    if (count == 0) return this->name;
    else if (count == 1) return this->author;
    else if (count == 2) return this->year;
    else if (count == 3) return this->educational_institution;
    else if (count == 4) return this->year_of_study;
    else if (count == 5) return this->volume_of_page;
    else if (count == 6) return this->cost;
}

string Chancellery::Save(int count)
{
    if (count == 0) return this->type;
    else if (count == 1) return this->color;
    else if (count == 2) return this->appointment;
    else if (count == 3) return this->cost;
}

void Book::Load(int count, string line)
{
    if (count == 0) this->name = line;
    else if (count == 1) this->author = line;
    else if (count == 2) this->year = line;
    else if (count == 3) this->annotation = line;
    else if (count == 4) this->genre = line;
    else if (count == 5) this->volume_of_page = line;
    else if (count == 6) this->cost = line;
}

void StudyBook::Load(int count, string line)
{
    if (count == 0) this->name = line;
    else if (count == 1) this->author = line;
    else if (count == 2) this->year = line;
    else if (count == 3) this->educational_institution = line;
    else if (count == 4) this->year_of_study = line;
    else if (count == 5) this->volume_of_page = line;
    else if (count == 6) this->cost = line;
}

void Chancellery::Load(int count, string line)
{
    if (count == 0) this->type = line;
    else if (count == 1) this->color = line;
    else if (count == 2) this->appointment = line;
    else if (count == 3) this->cost = line;
}
