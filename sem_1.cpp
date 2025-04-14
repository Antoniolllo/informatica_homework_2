# задание оформить сабвектор в класс
class subvector {

private:
    int* mas;              // Указатель на массив
    unsigned int top;      // Текущий размер (количество элементов)
    unsigned int capacity; // Общая выделенная память

public:
    subvector() {
        mas = nullptr;
        top = 0;
        capacity = 0;
    }

    ~subvector() {
        delete[] mas;
    }


    bool resize(unsigned int new_capacity) {
        if (new_capacity == 0) {
            delete[] mas;
            mas = nullptr;
            top = 0;
            capacity = 0;
        }

        int* new_mas = new int[new_capacity];

        for (unsigned int i = 0; i < top && i < new_capacity; i++) {
            new_mas[i] = mas[i];
        }
        delete[] mas;
        mas = new_mas;
        capacity = new_capacity;
        if (top > new_capacity) {
            top = new_capacity;
        }
    }


    bool push_back(int d) {
        if (top == capacity) {
            unsigned int new_capacity = (capacity == 0) ? 1 : capacity * 2;
            if (resize(new_capacity)==0) return false;
        }
        mas[top++] = d;
    }


    int pop_back() {
        if (top == 0) {
            return 0;
        }
        return mas[--top];
    }


    void shrink_to_fit() {
        if (capacity > top) {
            resize(top);
        }
    }


    void clear() {
        top = 0;
    }


    unsigned int size() const {
        return top;
    }


    unsigned int get_capacity() const {
        return capacity;
    }
};

