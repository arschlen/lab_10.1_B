#include <iostream>
#include <iomanip>
#include <string>

// Вимикаємо макроси min та max
#define NOMINMAX
#include <Windows.h>

using namespace std;

enum Specialnist { KN, PM, FI };
string specialnistStr[] = { "КН", "ПМ", "ФІ" };

union SpecialSubject {
    int ocinka_programuvannia;    // Для КН
    int ocinka_chyselni_metody;   // Для ПМ
    int ocinka_pedagogika;        // Для ФІ
};

struct Student {
    string prizv;
    int kurs;
    Specialnist specialnist;
    int ocinka_fizyka;
    int ocinka_matematyka;
    SpecialSubject spec_predmet; // Специфічний предмет
};

// Очищення вхідного буфера
void ClearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void CreateStudents(Student* students, const int N) {
    int specialnist;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;

        // Прізвище
        cout << " Прізвище: ";
        ClearInputBuffer();
        getline(cin, students[i].prizv);

        // Курс
        cout << " Курс (1-4): ";
        while (!(cin >> students[i].kurs) || students[i].kurs < 1 || students[i].kurs > 4) {
            cout << " Помилка! Введіть ціле число від 1 до 4: ";
            ClearInputBuffer();
        }

        // Спеціальність
        cout << " Спеціальність (0 - КН, 1 - ПМ, 2 - ФІ): ";
        while (!(cin >> specialnist) || specialnist < 0 || specialnist > 2) {
            cout << " Помилка! Введіть 0, 1 або 2: ";
            ClearInputBuffer();
        }
        students[i].specialnist = (Specialnist)specialnist;

        // Оцінка з фізики
        cout << " Оцінка з фізики (2-5): ";
        while (!(cin >> students[i].ocinka_fizyka) || students[i].ocinka_fizyka < 2 || students[i].ocinka_fizyka > 5) {
            cout << " Помилка! Введіть оцінку від 2 до 5: ";
            ClearInputBuffer();
        }

        // Оцінка з математики
        cout << " Оцінка з математики (2-5): ";
        while (!(cin >> students[i].ocinka_matematyka) || students[i].ocinka_matematyka < 2 || students[i].ocinka_matematyka > 5) {
            cout << " Помилка! Введіть оцінку від 2 до 5: ";
            ClearInputBuffer();
        }

        // Оцінка залежно від спеціальності
        if (students[i].specialnist == KN) {
            cout << " Оцінка з програмування (2-5): ";
            while (!(cin >> students[i].spec_predmet.ocinka_programuvannia) || students[i].spec_predmet.ocinka_programuvannia < 2 || students[i].spec_predmet.ocinka_programuvannia > 5) {
                cout << " Помилка! Введіть оцінку від 2 до 5: ";
                ClearInputBuffer();
            }
        }
        else if (students[i].specialnist == PM) {
            cout << " Оцінка з чисельних методів (2-5): ";
            while (!(cin >> students[i].spec_predmet.ocinka_chyselni_metody) || students[i].spec_predmet.ocinka_chyselni_metody < 2 || students[i].spec_predmet.ocinka_chyselni_metody > 5) {
                cout << " Помилка! Введіть оцінку від 2 до 5: ";
                ClearInputBuffer();
            }
        }
        else if (students[i].specialnist == FI) {
            cout << " Оцінка з педагогіки (2-5): ";
            while (!(cin >> students[i].spec_predmet.ocinka_pedagogika) || students[i].spec_predmet.ocinka_pedagogika < 2 || students[i].spec_predmet.ocinka_pedagogika > 5) {
                cout << " Помилка! Введіть оцінку від 2 до 5: ";
                ClearInputBuffer();
            }
        }

        cout << endl;
    }
}

void PrintStudents(const Student* students, const int N) {
    cout << "======================================================================================================================" << endl;
    cout << "| № | Прізвище        | Курс | Спеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "|" << setw(2) << i + 1
            << " | " << setw(15) << left << students[i].prizv
            << "|   " << setw(3) << students[i].kurs
            << "| " << setw(13) << specialnistStr[students[i].specialnist]
            << "|   " << setw(6) << students[i].ocinka_fizyka
            << "|   " << setw(9) << students[i].ocinka_matematyka;

        if (students[i].specialnist == KN)
            cout << "|      " << setw(11) << students[i].spec_predmet.ocinka_programuvannia
            << "|                 |            |" << endl;
        else if (students[i].specialnist == PM)
            cout << "|                 |      " << setw(12) << students[i].spec_predmet.ocinka_chyselni_metody
            << "|            |" << endl;
        else if (students[i].specialnist == FI)
            cout << "|                 |                 |   " << setw(9) << students[i].spec_predmet.ocinka_pedagogika << " |" << endl;
    }
    cout << "======================================================================================================================" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    while (!(cin >> N) || N <= 0) {
        cout << " Помилка! Введіть додатнє ціле число: ";
        ClearInputBuffer();
    }

    Student* students = new Student[N];

    CreateStudents(students, N);
    PrintStudents(students, N);

    delete[] students;
    return 0;
}
