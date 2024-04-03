#include "mystring.h"

void MyString::clear() {
    size_ = 0;
    std::fill(initialBuffer.begin(), initialBuffer.end(), '\0');
    text.clear();
}

// use: std::find_if_not, std::copy, ::isspace
void MyString::trim() {
    auto left = std::find_if_not(begin(), end(), ::isspace);
    auto right = std::find_if_not(std::make_reverse_iterator(end()), std::make_reverse_iterator(begin()), ::isspace);

    if (left == end()) {
        clear();
        return;
    }

    std::copy(left, right.base(), begin());
    size_ = std::distance(left, right.base());
    text.resize(0);


}

std::ostream &operator<<(std::ostream &os, const MyString &myString) {
    for(size_t i = 0; i < myString.size(); ++i){
        os << myString[i];
    }
    return os;
}


void MyString::toLower() {
    MyString copy = *this;
    std::transform(begin(), end(), begin(), [](char c) {
        return std::tolower(c);
    });
}

char MyString::operator[](std::size_t index) const {
    if(index >= size_){
        throw std::out_of_range("Index out of range");
    }
    if (index < initialBufferSize_) {
        return initialBuffer[index];
    } else {
        return text[index - initialBufferSize_];
    }
}

std::istream &operator>>(std::istream &stream, MyString &text) {
    text.clear();
    char c;
    while (stream.get(c)) {
        if (c == '\n') {
            break;
        }
        text.push_back(c);
    }
    return stream;
}

void MyString::push_back(char c) {
    if (size_ < initialBufferSize_) {
        initialBuffer[size_] = c;
    } else {
        text.push_back(c);
    }
    ++size_;
    capacity_ = initialBufferSize_ + text.capacity();
}

// use: std::find_if, std::back_inserter, std::transform, ::tolower
std::set<MyString> MyString::getUniqueWords() const {
    std::set<MyString> uniqueWords;
    MyString word;

    std::transform(begin(), end(), std::back_inserter(word), [](char c) { return std::tolower(c); });
    auto wordStart = std::find_if(word.begin(), word.end(), [](char c) { return std::isalpha(c); });
    auto wordEnd = std::find_if_not(wordStart, word.end(), [](char c) { return std::isalpha(c); });
    MyString uniqueWord;
    while (wordStart!=word.end()){

        std::transform(wordStart, wordEnd, std::back_inserter(uniqueWord), [](char c) { return c; });

        uniqueWords.insert(uniqueWord);

        wordStart = std::find_if(wordEnd, word.end(), [](char c) {  return std::isalpha(c); });
        if(wordStart==word.end()){
            break;
        }
        wordEnd = std::find_if_not(wordStart, word.end(), [](char c) { return std::isalpha(c); });
        uniqueWord.clear();
    }
    return uniqueWords;

}

std::map<MyString, size_t> MyString::countWordsUsageIgnoringCases() const {
    std::map<MyString, size_t> wordsUsage;
    MyString word;

    std::transform(begin(), end(), std::back_inserter(word), [](char c) { return std::tolower(c); });
    auto wordStart = std::find_if(word.begin(), word.end(), [](char c) { return std::isalpha(c); });
    auto wordEnd = std::find_if_not(wordStart, word.end(), [](char c) { return std::isalpha(c); });

    while (wordStart != word.end()) {
        MyString uniqueWord;
        std::transform(wordStart, wordEnd, std::back_inserter(uniqueWord), [](char c) { return std::tolower(c); });
        wordsUsage[uniqueWord]++;

        wordStart = std::find_if(wordEnd, word.end(), [](char c) { return std::isalpha(c); });
        if (wordStart == word.end()) {
            break;
        }
        wordEnd = std::find_if_not(wordStart, word.end(), [](char c) { return std::isalpha(c); });
        uniqueWord.clear();
    }

    return wordsUsage;


}

// use: std::search
bool MyString::startsWith(std::string text) const {
    auto start = std::search(begin(), end(), text.begin(), text.end());
    return start == begin();

}

bool MyString::endsWith(std::string text) const {
    auto start = std::search(begin(), end(), text.begin(), text.end());
    return start == end() - text.size();
}

// use: std::all_of
bool MyString::all_of(int (*predicate)(int)) const {
    return std::all_of(begin(), end(), predicate);
}

// use: std::generate_n, std::back_inserter
MyString MyString::generateRandomWord(size_t size) {
    MyString word;
    std::generate_n(std::back_inserter(word), size, []() { return generateRandomChar(); });
    return word;
}

// use: std::copy, std::back_inserter
MyString MyString::join(const std::vector<MyString> &words) const {
    if (words.empty())
        return "";

    const MyString& separator = *this;
    MyString result;

    auto it = std::begin(words);

    if (it != std::end(words)) {
        std::copy(it->begin(), it->end(), std::back_inserter(result));
        ++it;
    }

    for (; it != std::end(words); ++it) {
        std::copy(separator.begin(), separator.end(), std::back_inserter(result));
        std::copy(it->begin(), it->end(), std::back_inserter(result));
    }

    return result;


}

bool MyString::operator!=(const MyString &other) const {
    return !(*this == other);

}

bool MyString::operator<(const MyString &other) const {
    if (size_ < initialBufferSize_ - 1)
        return std::strcmp(initialBuffer.data(), other.initialBuffer.data()) < 0;
    else
        if(std::strcmp(initialBuffer.data(), other.initialBuffer.data()) <= 0){
            return strcmp(text.c_str(), other.text.c_str()) < 0;
        }
        else
            return false;


}

MyString MyString::operator+=(char c) {
    push_back(c);
    return *this;
}

bool MyString::operator==(const MyString &string) const {
    if (this == &string) return true;
    if (size_ < initialBufferSize_ - 1)
        return initialBuffer==string.initialBuffer;
    else
        return (initialBuffer==string.initialBuffer && text == string.text);
}

char& MyString::operator[](std::size_t index) {
    if(index >= size_){
        throw std::out_of_range("Index out of range");
    }
    if (index < initialBufferSize_) {
        return initialBuffer[index];
    } else {
        return text[index - initialBufferSize_];
    }
}










