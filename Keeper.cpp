#include <iostream>
#include "Keeper.h"

using namespace std;

// класс Keeper
// конструктор по умолчанию
Keeper::Keeper()
{
    this->array = new Base*[1];
    this->size = 1;
    this->countElement = 0;

    cout << "Вызван конструктор по умолчанию класса - Keeper" << endl;
}

// конструктор c параметром
Keeper::Keeper(int size)
{
    this->array = new Base*[size];
    this->size = size;
    this->countElement = 0;

    cout << "Вызван конструктор с параметром класса - Keeper" << endl;
}

// конструктор копирования
Keeper::Keeper(const Keeper &K)
{
    this->array = new Base*[K.size];
    this->size = K.size;
    this->countElement = K.countElement;

    for (int count = 0; count < countElement; count++)
    {
        this->array[count] = K.array[count];
    }

    cout << "Вызван конструктор копирования класса - Keeper" << endl;
}

// деструктор
Keeper::~Keeper()
{
    for (int count = 0; count < countElement; count ++)
    {
        delete [] array[count];
    }
    delete [] array;

    cout << "Вызван деструктор класса - Keeper" << endl;
}

// основные методы
// метод добавления элемента
void Keeper::Set()
{
    cout << "Выберите, что вы хотите добавить:" <<  endl;
    cout << "1 - Книги \n"
         << "2 - Учебники \n"
         << "3 - Канцелярия" << endl;
    int choice;

    try
    {
        cin >> choice;
        if (choice > 3 or choice < 1) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный выбор" << endl;
    }

    if (choice == 1)
    {
        Base *ptr_book = new Book();
        array[countElement++] = ptr_book;
        ptr_book->Set();
    }

    else if (choice == 2)
    {
        Base *ptr_studybook = new StudyBook();
        array[countElement++] = ptr_studybook;
        ptr_studybook->Set();
    }

    else
    {
        Base *ptr_chancellery = new Chancellery();
        array[countElement++] = ptr_chancellery;
        ptr_chancellery->Set();
    }
}

// метод получения элементов
void Keeper::Get()
{
    cout << "Данные:" << endl;
    for (int count = 0; count < countElement; count++)
    {
        array[count]->Get();
    }
}

// метод удаления
void Keeper::Delete()
{
    cout << "Введите номер, который вы хотите удалить: ";
    int id;
    try
    {
        cin >> id;
        if (id > countElement or id < 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный выбор" << endl;
    }

    delete [] array[id];
}

// метод изменения
void Keeper::Change()
{
    cout << "Введите номер, данные которого вы хотите изменить: ";
    int id;
    try
    {
        cin >> id;
        if (id > countElement or id < 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный выбор" << endl;
    }

    array[id]->Change();
}

// метод сохранения в файл
void Keeper::Save()
{
    cout << "Save" << endl;
}

// метод восстановления из файла
void Keeper::Load()
{
    cout << "Load" << endl;
}
