#include <iostream>
#include <string>
#include <exception>

using namespace std;

// simple exception class
class StackException : public std::exception {
    const char* m_msg;
    StackException() {};    // no default constructor
public:
    explicit StackException(const char* s) throw() : m_msg(s) { }
    const char* what() const throw() { return m_msg; }
};

// simple fixed-size LIFO stack template
template <typename T>
class Stack {
private:
    static const int m_defaultSize = 10;
    static const int m_maxSize = 1000;
    int m_size;
    int m_top;
    T* m_stackPtr;
public:
    explicit Stack(int s = m_defaultSize);
    ~Stack() { delete[] m_stackPtr; }
    T& push(const T&);
    T& pop();
    bool isEmpty() const { return m_top < 0; }
    bool isFull() const { return m_top >= m_size - 1; }
    int top() const { return m_top; }
    int size() const { return m_size; }
};

// Stack<T> constructor
template <typename T>
Stack<T>::Stack(int s) {
    if (s > m_maxSize || s < 1) throw StackException("invalid stack size");
    else m_size = s;
    m_stackPtr = new T[m_size];
    m_top = -1;
}

template <typename T>
T& Stack<T>::push(const T& i) {
    if (isFull()) throw StackException("stack full");
    return m_stackPtr[++m_top] = i;
}

template <typename T>
T& Stack<T>::pop() {
    if (isEmpty()) throw StackException("stack empty");
    return m_stackPtr[m_top--];
}

constexpr int nums[] = { 1, 2, 3, 4, 5 };
constexpr const char* strs[] = { "one", "two", "three", "four", "five" };

int main() {
    try {
        Stack<int> si(5);

        cout << "si size: " << si.size() << endl;
        cout << "si top: " << si.top() << endl;

        for (int i : nums) {
            si.push(i);
        }

        cout << "si top after pushes: " << si.top() << endl;
        cout << "si is " << (si.isFull() ? "" : "not ") << "full" << endl;

        while (!si.isEmpty()) {
            cout << "popped " << si.pop() << endl;
        }
    }
    catch (StackException& e) {
        cout << "Stack error: " << e.what() << endl;
    }

    try {
        Stack<string> ss(5);

        cout << "ss size: " << ss.size() << endl;
        cout << "ss top: " << ss.top() << endl;

        for (const char* s : strs) {
            ss.push(s);
        }

        cout << "ss top after pushes: " << ss.top() << endl;
        cout << "ss is " << (ss.isFull() ? "" : "not ") << "full" << endl;

        while (!ss.isEmpty()) {
            cout << "popped " << ss.pop() << endl;
        }
    }
    catch (StackException& e) {
        cout << "Stack error: " << e.what() << endl;
    }

    return 0;
}
