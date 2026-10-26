#include <iostream>

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* head = nullptr;
    Node* tail = nullptr;
};

bool isEmpty(const Queue& q) {
    return q.head == nullptr;
}

void enqueue(Queue& q, int value) {
    Node* newNode = new Node{ value, nullptr };
    if (isEmpty(q)) {
        q.head = q.tail = newNode;
    }
    else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
}

int dequeue(Queue& q) {
    if (isEmpty(q)) {
        std::cerr << "Черга порожня!\n";
        return -1;
    }
    Node* temp = q.head;
    int value = temp->data;
    q.head = q.head->next;

    if (q.head == nullptr) {
        q.tail = nullptr;
    }

    delete temp;
    return value;
}

void printQueue(const Queue& q) {
    if (isEmpty(q)) {
        std::cout << "Черга порожня.\n";
        return;
    }
    Node* current = q.head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

void clearQueue(Queue& q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

void removeMultiplesOfThree(Queue& q) {
    Queue tempQueue;

    while (!isEmpty(q)) {
        int val = dequeue(q);
        if (val % 3 != 0) {
            enqueue(tempQueue, val);
        }
    }

    while (!isEmpty(tempQueue)) {
        enqueue(q, dequeue(tempQueue));
    }
}

int main() {
    Queue myQueue;
    int n;

    std::cout << "Введіть кількість елементів послідовності: ";
    std::cin >> n;

    std::cout << "Введіть " << n << " цілих чисел через пробіл:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        enqueue(myQueue, val);
    }

    std::cout << "\nПочаткова черга: ";
    printQueue(myQueue);

    removeMultiplesOfThree(myQueue);

    std::cout << "Черга після видалення чисел, кратних 3: ";
    printQueue(myQueue);

    clearQueue(myQueue);

    return 0;
}