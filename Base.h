#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;

// ОСНОВНОЙ КЛАСС
class Base
{
// основные методы
public:
    virtual void Set() = 0; // добавить элемент
    virtual void Get() = 0; // получить элемент
    virtual void Delete() = 0; // удалить элемент
    virtual void Change() = 0; // изменить данные
    virtual void Load(int count, string line) = 0; // для выгрузки данных из файла
    virtual string Save(int count) = 0; // для выгрузки данных в файл
    virtual int TypeID() = 0; // чтобы понят студент или  учитель или администрация
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
    Book(const Book &B); // конструктор копирования
    ~Book(); // деструктор

// создание основных методов
    void Set() override; // добавление данных о книге
    void Get() override; // получениnaе данных о книге
    void Delete() override; // удаление данных о книге
    void Change() override; // изменение данных о книге
    void Load(int count, string line) override;
    string Save(int count) override;
    int TypeID() override;
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
    void Set() override; // добавление данных об учебнике
    void Get() override; // получение данных об учебнике
    void Delete() override; // удаление данных об учебнике
    void Change() override; // изменение данных об учебнике
    void Load(int count, string line) override;
    string Save(int count) override;
    int TypeID() override;
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
    Chancellery(const Chancellery &C); // конструктор копирования
    ~Chancellery(); // деструктор

// создание основных методов
    void Set() override; // добавление данных о канцелярии
    void Get() override; // получение данных о канцелярии
    void Delete() override; // удаление данных о канцелярии
    void Change() override; // изменение данных о канцелярии
    void Load(int count, string line) override;
    string Save(int count) override;
    int TypeID() override;
};

#endif
