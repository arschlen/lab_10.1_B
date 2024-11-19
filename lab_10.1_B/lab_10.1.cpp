#include <iostream>
#include <iomanip>
#include <string>

// �������� ������� min �� max
#define NOMINMAX
#include <Windows.h>

using namespace std;

enum Specialnist { KN, PM, FI };
string specialnistStr[] = { "��", "��", "Բ" };

union SpecialSubject {
    int ocinka_programuvannia;    // ��� ��
    int ocinka_chyselni_metody;   // ��� ��
    int ocinka_pedagogika;        // ��� Բ
};

struct Student {
    string prizv;
    int kurs;
    Specialnist specialnist;
    int ocinka_fizyka;
    int ocinka_matematyka;
    SpecialSubject spec_predmet; // ����������� �������
};

// �������� �������� ������
void ClearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void CreateStudents(Student* students, const int N) {
    int specialnist;
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;

        // �������
        cout << " �������: ";
        ClearInputBuffer();
        getline(cin, students[i].prizv);

        // ����
        cout << " ���� (1-4): ";
        while (!(cin >> students[i].kurs) || students[i].kurs < 1 || students[i].kurs > 4) {
            cout << " �������! ������ ���� ����� �� 1 �� 4: ";
            ClearInputBuffer();
        }

        // ������������
        cout << " ������������ (0 - ��, 1 - ��, 2 - Բ): ";
        while (!(cin >> specialnist) || specialnist < 0 || specialnist > 2) {
            cout << " �������! ������ 0, 1 ��� 2: ";
            ClearInputBuffer();
        }
        students[i].specialnist = (Specialnist)specialnist;

        // ������ � ������
        cout << " ������ � ������ (2-5): ";
        while (!(cin >> students[i].ocinka_fizyka) || students[i].ocinka_fizyka < 2 || students[i].ocinka_fizyka > 5) {
            cout << " �������! ������ ������ �� 2 �� 5: ";
            ClearInputBuffer();
        }

        // ������ � ����������
        cout << " ������ � ���������� (2-5): ";
        while (!(cin >> students[i].ocinka_matematyka) || students[i].ocinka_matematyka < 2 || students[i].ocinka_matematyka > 5) {
            cout << " �������! ������ ������ �� 2 �� 5: ";
            ClearInputBuffer();
        }

        // ������ ������� �� ������������
        if (students[i].specialnist == KN) {
            cout << " ������ � ������������� (2-5): ";
            while (!(cin >> students[i].spec_predmet.ocinka_programuvannia) || students[i].spec_predmet.ocinka_programuvannia < 2 || students[i].spec_predmet.ocinka_programuvannia > 5) {
                cout << " �������! ������ ������ �� 2 �� 5: ";
                ClearInputBuffer();
            }
        }
        else if (students[i].specialnist == PM) {
            cout << " ������ � ��������� ������ (2-5): ";
            while (!(cin >> students[i].spec_predmet.ocinka_chyselni_metody) || students[i].spec_predmet.ocinka_chyselni_metody < 2 || students[i].spec_predmet.ocinka_chyselni_metody > 5) {
                cout << " �������! ������ ������ �� 2 �� 5: ";
                ClearInputBuffer();
            }
        }
        else if (students[i].specialnist == FI) {
            cout << " ������ � ��������� (2-5): ";
            while (!(cin >> students[i].spec_predmet.ocinka_pedagogika) || students[i].spec_predmet.ocinka_pedagogika < 2 || students[i].spec_predmet.ocinka_pedagogika > 5) {
                cout << " �������! ������ ������ �� 2 �� 5: ";
                ClearInputBuffer();
            }
        }

        cout << endl;
    }
}

void PrintStudents(const Student* students, const int N) {
    cout << "======================================================================================================================" << endl;
    cout << "| � | �������        | ���� | ������������ | Գ���� | ���������� | ������������� | ������� ������ | ��������� |" << endl;
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
    cout << "������ ������� ��������: ";
    while (!(cin >> N) || N <= 0) {
        cout << " �������! ������ ������ ���� �����: ";
        ClearInputBuffer();
    }

    Student* students = new Student[N];

    CreateStudents(students, N);
    PrintStudents(students, N);

    delete[] students;
    return 0;
}
