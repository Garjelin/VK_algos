#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

// Определение узла списка
struct Node {
    char ISBN[11];
    char nameBook[101];
    int year;
    Node* next;
    
    Node(const char* isbn, const char* nb, int y) : year(y), next(nullptr) {
        strncpy(ISBN, isbn, sizeof(ISBN) - 1);
        ISBN[sizeof(ISBN) - 1] = '\0';
        strncpy(nameBook, nb, sizeof(nameBook) - 1);
        nameBook[sizeof(nameBook) - 1] = '\0';
    }
};

// Функция для объединения двух отсортированных списков
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;

    if (left->year < right->year || (left->year == right->year && strcmp(left->nameBook, right->nameBook) <= 0)) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Функция для разбиения списка на две части
void split(Node* source, Node** front, Node** back) {
    if (!source || !source->next) {
        *front = source;
        *back = nullptr;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

// Функция для сортировки односвязного списка слиянием
void mergeSort(Node** head) {
    Node* current = *head;
    Node* left;
    Node* right;

    if (!current || !current->next) {
        return;
    }

    // Разбиваем список на две части
    split(current, &left, &right);

    // Рекурсивно сортируем каждую часть
    mergeSort(&left);
    mergeSort(&right);

    // Объединяем отсортированные части
    *head = merge(left, right);
}

// Функция для добавления элемента в конец списка
void push(Node** head, char* ISBN, char* nameBook, int year) {
    Node* newNode = new Node(ISBN, nameBook, year);
    if (!*head) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    //cout << newNode->ISBN << " " << newNode->nameBook << " " << newNode->year << endl;
}

// Функция для вывода списка
void printList(Node* node) {
    while (node) {
        cout << node->ISBN << " \"" << node->nameBook << "\" " << node->year << endl;
        node = node->next;
    }
}

void parseInput(Node** head, const string& line) {
    istringstream iss(line);
    char ISBN[11];
    char nameBook[101];
    int year;

    if (iss >> ISBN && iss.get() == ' ' && iss.get() == '"' && iss.getline(nameBook, sizeof(nameBook) - 1, '"') && iss.get() == ' ' && iss >> year) {
        push(head, ISBN, nameBook, year);
    } else {
        throw invalid_argument("Invalid input format");
    }
}

int main() {
    Node* head = nullptr;
    int n;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        try {
            string line;
            getline(cin, line);
            parseInput(&head, line);
        } catch (const invalid_argument& e) {
            cout << e.what() << " on line " << i + 1 << endl;
        }
    }

    
    mergeSort(&head);

    printList(head);

    return 0;
}
