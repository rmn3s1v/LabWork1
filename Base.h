#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;

// ОСНОВНОЙ КЛАСС
class Base
{
private:
    string **array_of_books; // двумерный массив для хранения данных о книгах
    string **array_of_studybooks; // двумерный массив для хранения данных об учебниках
    string **array_of_chancellerys; // двумерный массив для хранения данных о канцелярии

public:
// создание конструкторов и деструктора
    Base(); // конструктор по умолчанию
    Base(int flag_to_load); // конструктор с параметром
    Base(const Base &B); // конструктор копирования
    ~Base(); // деструктор

// основные методы
    void Set(int choice); // добавить элемент
    void Get(); // получить элемент
    void Delete(int choice); // удалить элемент
    void Change(int choice); // изменить данные

};

class Book:public Base
{
private:
    string name; // название
    string author; // автор
    string year; // год выпуска
    string annotation; // аннотация
    string genre; // жанр
    string volume_of_page; // объем страниц
    string cost; // цена

public:
// создание конструкторов и деструктора
    Book(); // конструктор по умолчанию
    Book(string name, string author, string year, string annotation, string genre, string volume_of_page, string cost); // конструктор с параметром
    Book(const Book &S); // конструктор копирования
    ~Book(); // деструктор

// создание основных методов
    void Set(string name, string author, string year, string annotation, string genre, string volume_of_page, string cost); // добавление данных о книге
    void Get(); // получение данных о книге
    void Delete(int choice); // удаление данных о книге
    void Change(int choice); // изменение данных о книге
};

class StudyBook:public Base
{
private:
    string name; // название
    string author; // автор
    string year; // год выпуска
    string educational_institution; // учебное заведение
    string year_of_study; // год обучения
    string volume_of_page; // объем страниц
    string cost; // цена

public:
// создание конструкторов и деструктора
    StudyBook(); // конструктор по умолчанию
    StudyBook(string name, string author, string year, string educational_institution, string year_of_study, string volume_of_page, string cost); // конструктор с параметром
    StudyBook(const StudyBook &S); // конструктор копирования
    ~StudyBook(); // деструктор

// создание основных методов
    void Set(string name, string author, string year, string educational_institution, string year_of_study, string volume_of_page, string cost); // добавление данных об учебнике
    void Get(); // получение данных об учебнике
    void Delete(int choice); // удаление данных об учебнике
    void Change(int choice); // изменение данных об учебнике
};

class Chancellery:public Base
{
private:
    string type; // тип
    string color; // цвет
    string appointment; // назначение
    string cost; // цена

public:
// создание конструкторов и деструктора
    Chancellery(); // конструктор по умолчанию
    Chancellery(string type, string color, string appointment, string cost); // конструктор с параметром
    Chancellery(const Chancellery &S); // конструктор копирования
    ~Chancellery(); // деструктор

// создание основных методов
    void Set(string type, string color, string appointment, string cost); // добавление данных о канцелярии
    void Get(); // получение данных о канцелярии
    void Delete(int choice); // удаление данных о канцелярии
    void Change(int choice); // изменение данных о канцелярии
};

#endif
