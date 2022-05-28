#include "NaturalNumbers.h"

void NaturalNumbers::clear()
{
    delete[] this->numbers;
    delete[] this->name;
}

void NaturalNumbers::initialise(const int& n)
{
    this->numbers = new int[n];
    if (!numbers) {
        std::cout << "Failed allocation" << std::endl;
        return;
    }
}

NaturalNumbers::NaturalNumbers() : numbers(nullptr), size(0)
{
    int size = strlen("Empty set");

    this->name = new char[size + 1];
    if (!this->name) {
        std::cout << "Failed memory allocation" << std::endl;
        return;
    }

    strcpy_s(name, size, "Empty set");
}

NaturalNumbers::NaturalNumbers(int* numbers, const int& n, const char* name)
{
    this->initialise(n);

    int naturalIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (!this->operator[](numbers[i])) {
            this->numbers[naturalIndex] = numbers[i];
            naturalIndex++;
        }
        else {
            std::cout << "The number " << numbers[i] << " its dublicated so it wont be added" << std::endl;
        }
    }

    this->setSize(naturalIndex);
    this->setName(name);
}

NaturalNumbers::NaturalNumbers(const NaturalNumbers& other)
{
    this->initialise(other.size);

    this->setSize(other.size);
    this->setNumbers(other.numbers, other.size);
    this->setName(other.name);
}

NaturalNumbers& NaturalNumbers::operator=(const NaturalNumbers& other)
{
    if (this != &other) {

        this->clear();
        this->initialise(other.size);

        this->setSize(other.size);
        this->setNumbers(other.numbers, other.size);
        this->setName(other.name);
    }

    return *this;
}

NaturalNumbers::~NaturalNumbers()
{
    this->clear();
}

NaturalNumbers NaturalNumbers::operator*(const NaturalNumbers& other)
{
    NaturalNumbers temp;

    int max = this->size > other.size ? this->size : other.size;

    temp.setSize(max);

    int naturalIndex = 0;
    if (max == this->size) {
        for (int i = 0; i < max; ++i) {
            if (other[this->numbers[i]]) {
                temp.numbers[naturalIndex] = this->numbers[i];
            }
        }
    }
    else {
        for (int i = 0; i < max; ++i) {
            if (this->operator[](other.numbers[i])) {
                temp.numbers[naturalIndex] = other.numbers[i];
            }
        }
    }

    temp.setSize(naturalIndex);

    return temp;
}

NaturalNumbers NaturalNumbers::operator*=(const NaturalNumbers& other)
{
    NaturalNumbers temp = *this * other;
    *this = temp;

    return *this;
}

bool NaturalNumbers::operator[](const int& n) const
{
    for (int i = 0; i < this->size; ++i) {
        if (this->numbers[i] == n) {
            return true;
        }
    }

    return false;
}

const int* NaturalNumbers::getNumbers() const
{
    return this->numbers;
}

const char* NaturalNumbers::getName() const
{
    return this->name;
}

int NaturalNumbers::getSize() const
{
    return this->size;
}

void NaturalNumbers::setNumbers(int* numbers, const int& size)
{
    for (int i = 0; i < size; ++i) {
        this->numbers[i] = numbers[i];
    }
}

void NaturalNumbers::setName(const char* name)
{
    delete[] this->name;

    int size = strlen(name);
    this->name = new char[size + 1];
    if (!name) {
        std::cout << "Failed memory allocation" << std::endl;
        return;
    }

    strcpy_s(this->name, size, name);
}

void NaturalNumbers::setSize(const int& size)
{
    this->size = size;
}

std::ostream& operator<<(std::ostream& os, const NaturalNumbers& natNums)
{
    os << "The name of the NaturalNumbers: " << natNums.name << std::endl;
    os << "The numbers are: " << std::endl;
    for (int i = 0; i < natNums.size; ++i) {
        os << natNums.numbers[i] << std::endl;
    }

    return os;
}

std::istream& operator>>(std::istream& is, NaturalNumbers& natNums)
{
    char name[MAX_NAME];
    if (is.peek() == '\n') is.ignore();
    is.getline(name, MAX_NAME, '\n');
    bool failed = is.fail();
    if (failed) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    natNums.setName(name);

    int size = 0;
    std::cout << "Enter how many numbers do you want to add: ";
    is >> size;
    while (size < 0 || is.fail()) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid argument, please try again: ";
        is >> size;
    }

    natNums.initialise(size);

    std::cout << "Enter the numbers: ";
    int naturalIndex = 0;
    for (int i = 0; i < size; ++i) {

        int temp = 0;
        is >> temp;
        while (is.fail() || temp < 0) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid argument, please try again: ";
            is >> temp;
        }

        if (!natNums[temp]) {
            natNums.numbers[naturalIndex] = temp;
            naturalIndex++;
        }
    }

    natNums.setSize(naturalIndex);

    return is;
}
