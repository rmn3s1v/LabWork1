#include <iostream>
#include <fstream>
#include "Keeper.h"
#include "Base.h"

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
    string choice;

    try
    {
        cin >> choice;
        for (int i = 0; i < choice.length(); i++)
        {
            if (choice[i] >= 'A' and choice[i] <= 'Z' or choice[i] >= 'a' and choice[i] <= 'z') throw "Error";
        }
        if (stoi(choice) < 1 or stoi(choice) > 3) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный выбор" << endl;
    }

    // если массив переполнен
    if (this->countElement == this->size)
    {
        Base **buf_array = new Base*[size]; // создаем буферный массив для копирования объектов

        for (int count = 0; count < size; count++)
        {
            buf_array[count] = this->array[count]; // копируем элементы
        }

        delete [] this->array; // удаляем память под массив

        // выделяем новую память под наш массив
        try
        {
            this->array = new Base*[size*2]; // выделяем доп. память
        }
        catch(const std::exception& e)
        {
            std::cerr << "Память не удалось выделить" << endl;
            exit(1);
        }

        this->size = size * 2; // увеличиваем размер массива

        // копируем старые элементы
        for (int count = 0; count < countElement; count++)
        {
            this->array[count] = buf_array[count]; // копируем элементы
        }
    }

    if (stoi(choice) == 1)
    {
        Base *ptr_book = new Book();
        array[countElement++] = ptr_book;
        ptr_book->Set();
    }

    else if (stoi(choice) == 2)
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

// метод получения элементов
void Keeper::GetChoice()
{
    cout << "Введите номер, который вы хотите увидеть: ";
    string id;
    try
    {
        cin >> id;
        for (int i = 0; i < id.length(); i++)
        {
            if (id[i] >= 'A' and id[i] <= 'Z' or id[i] >= 'a' and id[i] <= 'z') throw "Error";
        }
        if (stoi(id) > countElement or stoi(id) < 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный выбор" << endl;
    }

    array[stoi(id)]->Get();
}

// метод удаления
void Keeper::Delete()
{
    cout << "Введите номер, который вы хотите удалить: ";
    string id;
    try
    {
        cin >> id;
        for (int i = 0; i < id.length(); i++)
        {
            if (id[i] >= 'A' and id[i] <= 'Z' or id[i] >= 'a' and id[i] <= 'z') throw "Error";
        }
        if (stoi(id) > countElement or stoi(id) < 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный выбор" << endl;
    }

    *this -= stoi(id);
}

Keeper & Keeper::operator-=(int element)
{
    // сдвигаем все элементы

    for (int count = element; count < countElement-1; count++)
    {
        int buf_count = count + 1;
        array[count] = array[buf_count];
    }
    this->countElement--;
    return *this;
}

// метод изменения
void Keeper::Change()
{
    cout << "Введите номер, данные которого вы хотите изменить: ";
    string id;
    try
    {
        cin >> id;
        for (int i = 0; i < id.length(); i++)
        {
            if (id[i] >= 'A' and id[i] <= 'Z' or id[i] >= 'a' and id[i] <= 'z') throw "Error";
        }
        if (stoi(id) > countElement or stoi(id) < 0) throw "Error";
    }
    catch(const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch(const char*mssg)
    {
        cout << "Неверный выбор" << endl;
    }

    array[stoi(id)]->Change();
}

// метод сохранения в файл
void Keeper::Save()
{
    cout << "\nSAVE" << endl;

    ofstream loadB;
    ofstream loadS;
    ofstream loadC;
    loadB.open("books.txt");
    loadS.open("studybooks.txt");
    loadC.open("chancellery.txt");

    int countB = 0;
    int countS = 0;
    int countC = 0;

    for (int i = 0; i < countElement; i++)
    {
        if (this->array[i]->TypeID() == 1)
        {
            loadB << this->array[i]->Save(countB) << endl;
            countB++;

            loadB << this->array[i]->Save(countB) << endl;
            countB++;

            loadB << this->array[i]->Save(countB) << endl;
            countB++;

            loadB << this->array[i]->Save(countB) << endl;
            countB++;

            loadB << this->array[i]->Save(countB) << endl;
            countB++;

            loadB << this->array[i]->Save(countB) << endl;
            countB++;

            loadB << this->array[i]->Save(countB) << endl;
            countB = 0;
        }

        else if (this->array[i]->TypeID() == 2)
        {
            loadS << this->array[i]->Save(countS) << endl;
            countS++;

            loadS << this->array[i]->Save(countS) << endl;
            countS++;

            loadS << this->array[i]->Save(countS) << endl;
            countS++;

            loadS << this->array[i]->Save(countS) << endl;
            countS++;

            loadS << this->array[i]->Save(countS) << endl;
            countS++;

            loadS << this->array[i]->Save(countS) << endl;
            countS++;

            loadS << this->array[i]->Save(countS) << endl;
            countS = 0;
        }

        else if (this->array[i]->TypeID() == 3)
        {
            loadC << this->array[i]->Save(countC) << endl;
            countC++;

            loadC << this->array[i]->Save(countC) << endl;
            countC++;

            loadC << this->array[i]->Save(countC) << endl;
            countC++;

            loadC << this->array[i]->Save(countC) << endl;
            countC = 0;
        }
    }

    cout << "\nSAVE COMPLETE" << endl;

    loadB.close();
    loadS.close();
    loadC.close();
}

// метод восстановления из файла
void Keeper::Load()
{
    cout << "\nLOAD" << endl;

    ifstream loadB;
    ifstream loadS;
    ifstream loadC;
    loadB.open("books.txt");
    loadS.open("studybooks.txt");
    loadC.open("chancellery.txt");

    if (loadB.is_open() and loadS.is_open() and loadC.is_open())
    {
        string line; // строка, в которую будем считывать
        int count = 0; // счетчик для записи

        while (true)
        {
            if (!getline(loadB, line)) break;

            Base *ptr_book = new Book(); // создаем объект - студент

            ptr_book->Load(count, line);
            count++;

            getline(loadB, line);
            ptr_book->Load(count, line);
            count++;

            getline(loadB, line);
            ptr_book->Load(count, line);
            count++;

            getline(loadB, line);
            ptr_book->Load(count, line);
            count++;

            getline(loadB, line);
            ptr_book->Load(count, line);
            count++;

            getline(loadB, line);
            ptr_book->Load(count, line);
            count++;

            getline(loadB, line);
            ptr_book->Load(count, line);

            count = 0;

            this->array[countElement++] = ptr_book; // добавляем в массив
        }

        count = 0; // счетчик для записи

        while (true)
        {
            if (!getline(loadS, line)) break;

            Base *ptr_studybook = new StudyBook(); // создаем объект - студент

            ptr_studybook->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_studybook->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_studybook->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_studybook->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_studybook->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_studybook->Load(count, line);
            count++;

            getline(loadS, line);
            ptr_studybook->Load(count, line);

            count = 0;

            this->array[countElement++] = ptr_studybook; // добавляем в массив
        }

        count = 0; // счетчик для записи

        while (true)
        {
            if (!getline(loadC, line)) break;

            Base *ptr_chancellery = new Chancellery(); // создаем объект - студент

            ptr_chancellery->Load(count, line);
            count++;

            getline(loadC, line);
            ptr_chancellery->Load(count, line);
            count++;

            getline(loadC, line);
            ptr_chancellery->Load(count, line);
            count++;

            getline(loadC, line);
            ptr_chancellery->Load(count, line);

            count = 0;

            this->array[countElement++] = ptr_chancellery; // добавляем в массив
        }

        cout << "\nLOAD COMPLETE" << endl;
    }

    else
    {
        cout << "\nОшибка открытия файлов" << endl;
    }

    loadB.close();
    loadS.close();
    loadC.close();
}
