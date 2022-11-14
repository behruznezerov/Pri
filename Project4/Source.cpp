#include <iostream> 
#include <assert.h> 
#include <queue>
#include <vector>

using namespace std;

class Student {

    string name;
    string surname;
    int age;
    double score;

public:

    Student() {

        name = "";
        surname = "";
        age = 0;
        score = 0;

    }

    Student(string n, string s, int a, int av) {

        name = n;
        surname = s;
        age = a;
        score = av;

    }

    Student(const Student& oth) {

        name = oth.name;
        surname = oth.surname;
        age = oth.age;
        score = oth.score;

    }

    string GetName() {
        return name;
    }

    string GetSurname() {
        return surname;
    }

    int GetAge() {
        return age;
    }

    double Getscore() {

        return score;

    }

    bool operator>(const Student& oth) {
        return score > oth.score;
    }

    Student& operator=(const Student& oth) {

        name = oth.name;
        surname = oth.surname;
        age = oth.age;
        score = oth.score;
        return *this;

    }

    friend ostream& operator<<(ostream& out, const Student& oth) {

        cout << "Name : " << oth.name
            << "\nSurname : " << oth.surname
            << "\nAge : " << oth.age
            << "\nAverage Score : " << oth.score
            << endl;
        return out;

    }

};

template <typename T>
class PriorityQueue {

    T* arr;
    int capacity;
    int count;
    int rear;
    int GetMaxIndex() {
        int maxIndex = 0;
        for (int i = 0; i < count; i++) {
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        return maxIndex;
    }
public:
    PriorityQueue(int size) {

        arr = new T[size];
        capacity = size;
        count = 0;
        rear = -1;

    }
    bool IsFull() const { return capacity == count; }

    bool IsEmpty() const { return 0 == count; }

    void Push(T value) {
        assert(!IsFull());
        arr[++rear] = value;
        count++;
    }

    void Pop() {
        assert(!IsEmpty());
        int index = GetMaxIndex();
        for (int i = index; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void Print() {
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~PriorityQueue()
    {
        delete[] arr;
    }
};

int main() {
    Student Kenan("Kenan", "Eskerov", 16, 87);
    Student Elgun("Elgun", "Eyyubov", 17, 68);
    Student Behruz("Behruz", "Nezerov", 16, 100);
    PriorityQueue<Student> sira(5);
    sira.Push(Kenan);
    sira.Push(Elgun);
    sira.Push(Behruz);
    sira.Print();
    sira.Pop();
    sira.Print();
    sira.Pop();
    sira.Print();

}

