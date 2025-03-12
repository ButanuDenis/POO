// PooLab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//clase si obiecte

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string nume;
    int varsta;
    float medie;

public:
    //Constructor cu variabila auxiliara
    Student(string nume_student, int varsta_student, float medie_student) {
        nume = nume_student;
        varsta = varsta_student;
        medie = medie_student;
        cout << "Constructorul a fost apelat pentru: " << nume << endl;
    }
    //Constructor folosind THIS
   /* Student(string nume, int varsta, float medie) {
        this->nume = nume;
        this->varsta = varsta;
        this->medie = medie;
        cout << "Constructorul a fost apelat pentru: " << nume << endl;
    }*/


    /*float returneaza_media() const {
        return medie;
    }

    void sorare_dupa_medie(student  **studenti, int n) 
    {
        for (int i=0;i<n-1;i++)
            for (int j = 0; j < n - 1; j++)
            {
                if (student[i]->returneza_media() > studenti[j + 1]->returneaza_media())
                {
                    student *aux = student[i];
                    student[j] = student[j + 1];
                    student[j + 1] = aux;
                }
            }

    }
    */


    ~Student()
    {
        cout << "Destructorul a fost apelat pentru: " << nume << endl;
    }
    void afisare_informatii()
    {
        cout << "Nume:" << nume << ",Varsta:" << varsta << ",Medie:" << medie;
    }

};

int main()
{
    int n, i;
    int median1{};
    cout << "Introduceti nr ed studenti: "; cin >> n;
    Student* studenti[2];
    n = 2;
    for (i = 0; i < n; i++)
    {
        string nume;
        int varsta;
        float medie;
        
        //Citim de la tastatura datele despre studentul curent (i)
        cout << "Introduceti numele studentului " << i + 1 << ": "; cin >> nume;
        cout << "Introduceti varsta studentului " << i + 1 << ": "; cin >> varsta;
        cout << "Introduceti media studentului " << i + 1 << ": "; cin >> medie;
        if (medie > median1)median1 = medie; //cautarea celei mai mare medie
        //Crearea unui nou obiect Student si stocarea lui intr-un array
        studenti[i] = new Student(nume, varsta, medie);
    }
        
    cout << "Media cea mai mare este:" << median1 << endl; //afisare cea mai mare medie

    for (i = 0; i < n; i++)
    {
        studenti[i]->afisare_informatii();
    }
    //Eliberare memoria alocata dinamic
    for (i = 0; i < n; i++)
    {
        delete studenti[i];
    }

    
    return 0;
}

