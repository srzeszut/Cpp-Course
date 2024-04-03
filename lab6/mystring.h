#include <string>
#include "array"
#include "cstring"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>


class MyString
{
    std::array<char, 20> initialBuffer;
    std::string text;
    std::size_t size_;
    std::size_t capacity_;
public:
    using value_type = char;
    static const std::size_t initialBufferSize_ = 20;

    MyString(): size_(0),capacity_(initialBufferSize_+text.capacity()){
        initialBuffer[0] = '\0';
    }

    MyString(const char* givenText): capacity_(initialBufferSize_ + text.capacity()) {
        if (givenText == nullptr) {
            initialBuffer[0] = '\0';
            size_ = 0;
        } else {
            size_ = std::strlen(givenText);
            std::copy(givenText, givenText + initialBufferSize_ , initialBuffer.begin());
            if(size_ > initialBufferSize_) {
                text=std::string(givenText+initialBufferSize_, givenText+size_);
            }
        }
    }
    MyString(const std::string& givenText): capacity_(initialBufferSize_ + text.capacity()) {
        size_ = givenText.size();
        std::copy(givenText.begin(), givenText.end(), initialBuffer.begin());
        if(size_ > initialBufferSize_) {
            text=std::string(givenText.begin()+initialBufferSize_, givenText.end());
        }
    }
    char operator[](std::size_t index) const;
    char& operator[](std::size_t index);
    class const_iterator {
        friend class MyString;
        const MyString* myString;
        std::size_t index;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = char;
        using difference_type = std::ptrdiff_t;
        using pointer = const char*;
        using reference = const char&;

        const_iterator(const MyString* myString, std::size_t index)
                : myString(myString), index(index) {}

        const_iterator& operator++() {
            ++index;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator tmp = *this;
            ++index;
            return tmp;
        }

        const_iterator& operator--() {
            --index;
            return *this;
        }

        const_iterator operator--(int) {
            const_iterator tmp = *this;
            --index;
            return tmp;
        }

        const_iterator operator+(std::size_t n) const {
            return const_iterator(myString, index + n);
        }

        const_iterator operator-(std::size_t n) const {
            return const_iterator(myString, index - n);
        }

        std::ptrdiff_t operator-(const const_iterator& other) const {
            return index - other.index;
        }

        char operator[](std::size_t n) const {
            return *(*this + n);
        }

        bool operator==(const const_iterator& other) const {
            return index == other.index;
        }

        bool operator!=(const const_iterator& other) const {
            return index != other.index;
        }

        const char& operator*() const {
            if (index < myString->initialBufferSize_) {
                return myString->initialBuffer[index];
            } else {
                return myString->text[index - myString->initialBufferSize_];
            }
        }
    };
    [[nodiscard]] const_iterator begin() const noexcept {
        return {this, 0};
    }

    [[nodiscard]] const_iterator end() const noexcept {
        return {this, this->size()};
    }
    class Iterator {
        friend class MyString;
        MyString* myString;
        std::size_t index;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = char;
        using difference_type = std::ptrdiff_t;
        using pointer = char*;
        using reference = char&;
        Iterator(MyString* myString, std::size_t index): myString(myString), index(index) {}

        Iterator& operator++() {
            ++index;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++index;
            return tmp;
        }
        Iterator& operator--() {
            --index;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --index;
            return tmp;
        }
        Iterator operator+(std::size_t n)  {
            return {myString, index + n};
        }


        Iterator operator-(std::size_t n)  {
            return {myString, index - n};
        }

        std::ptrdiff_t operator-(const Iterator& other) const {
            return index - other.index;
        }

        char operator[](std::size_t n)  {
            return *(*this + n);
        }


        bool operator==(const Iterator& other) const {
            return index == other.index;
        }

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        Iterator& operator=(char value) {
            if (index < myString->initialBufferSize_) {
                myString->initialBuffer[index] = value;
            } else {
                myString->text[index - myString->initialBufferSize_] = value;
            }
            return *this;
        }

        char& operator*()  {  // Zmieniono na char&
            if (index < MyString::initialBufferSize_) {
                return myString->initialBuffer[index];
            } else {
                return myString->text[index - MyString::initialBufferSize_];
            }
        }

    };
    [[nodiscard]] Iterator begin()  noexcept{
        return {this, 0};
    }
    [[nodiscard]] Iterator end()  noexcept{
        return {this, this->size()};
    }

    MyString(const MyString& other):initialBuffer(other.initialBuffer),text(other.text),size_(other.size()),capacity_(other.capacity_){};

    [[nodiscard]] std::size_t size()const{
        return size_;
    }
    [[nodiscard]] std::size_t capacity()const{
        return capacity_;
    }
    [[nodiscard]] bool empty() const { return size() == 0; }
    void push_back(char c);

    void clear();

    void trim();
    void toLower();

    [[nodiscard]] std::set<MyString> getUniqueWords() const;
    [[nodiscard]] std::map<MyString, size_t> countWordsUsageIgnoringCases() const;

    [[nodiscard]] bool startsWith(std::string) const;
    [[nodiscard]] bool endsWith(std::string) const;

    bool all_of(int predicate(int)) const;

    [[nodiscard]] MyString join(const std::vector<MyString> &) const;
    static MyString generateRandomWord(size_t);


    bool operator!=(const MyString &) const;

    bool operator<(const MyString &string) const;

    MyString operator+=(char);

    bool operator==(const MyString &string) const;




    friend std::ostream &operator<<(std::ostream &, const MyString &);

    friend std::istream &operator>>(std::istream &, MyString &);

    private:
    static char generateRandomChar() { return rand() % 26 + 65 + rand() % 2 * 32; }





};