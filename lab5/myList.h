#ifndef MYLIST_H
#define MYLIST_H

#include <memory>
#include <stdexcept>

#define IMPLEMENTED_constructorOfEmptyList
#define IMPLEMENTED_pushingAndPopingElementsFront
#define IMPLEMENTED_nodesStoredAsUniquePtrs
#define IMPLEMENTED_popFromWhenEmptyList
#define IMPLEMENTED_copyingDisabled
#define IMPLEMENTED_removingElements
#define IMPLEMENTED_iteratorOperations
#define IMPLEMENTED_iteratorWithRangedForLoop
#define IMPLEMENTED_iteratorWithStlAlgorithm
#define IMPLEMENTED_ostreamOperator

template<class T>
class MyList{
protected:
    struct Node{
        using node_ptr = std::unique_ptr<Node>;
        T data;
        node_ptr next_;
    };
    using node_ptr = std::unique_ptr<Node>;
    node_ptr head_= nullptr;
    std::size_t size_ = 0;
public:
    using value_type = T;
    std::size_t size() const noexcept { return size_; };
    MyList():head_(nullptr),size_(0){};
    void push_front(T);
    T pop_front();
    T front()const { return head_->data;}
    void remove(T element);


    class Iterator{
        friend class MyList;
    public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::forward_iterator_tag;

        Iterator() noexcept: current_node(nullptr){};
        Iterator(const node_ptr &node) noexcept : current_node(node.get()){};

        Iterator &operator++() noexcept
        {
            if (current_node != nullptr)
            {
                previous_node = current_node;
                current_node = current_node->next_.get();
            }
            return *this;
        };

        Iterator operator++(int) noexcept
        {
            Iterator Iter = *this;
            ++*this;
            return Iter;
        };

        friend bool operator!=(Iterator iterator1, Iterator iterator2) {
            return iterator1.current_node != iterator2.current_node;
        }

        friend bool operator==(Iterator iterator1, Iterator iterator2) {
            return iterator1.current_node == iterator2.current_node;
        }

        T &operator*() {
            return this->current_node->data;
        }

        T *operator->() {
            return &this->current_node->data;
        }

    private:
        Node *previous_node = nullptr;
        Node *current_node = nullptr;

    };
////////////////////////////////////////////////////////////////////


    Iterator begin() const noexcept
    {
        return Iterator(this->head_);
    };
    Iterator end() const noexcept
    {
        return Iterator();
    };

    Iterator erase(const Iterator& pos)
    {
        if (pos.current_node != nullptr)
        {
            if (pos.previous_node == nullptr)
            {
                head_ = std::move(pos.current_node->next_);
                size_--;
                return Iterator(head_);
            }
            else
            {
                pos.previous_node->next_ = std::move(pos.current_node->next_);
                size_--;
                return Iterator(pos.previous_node->next_);
            }
        }
        return pos;
    };

    friend std::ostream& operator<<(std::ostream& os, const MyList<T>& list)
    {
        for (const auto& element : list) {
            os << element << " ";
        }
        return os;
    }

};
template<class T>
void MyList<T>::push_front(T to_push) {
    node_ptr newNode = std::make_unique<Node>();
    newNode->next_ = std::move(head_);
    newNode->data=to_push;
    head_ = std::move(newNode);
    size_++;
}
template<class T>
T MyList<T>::pop_front() {
    if (head_ == nullptr)
        throw std::out_of_range("Cannot pop from empty list.");
    T to_pop;
    to_pop=head_->data;
    head_=std::move(head_->next_);
    size_--;
    return to_pop;

}
template<class T>
void MyList<T>::remove(T element) {
    for (auto it = begin(); it != end();) {
        if (*it == element) {
            it= erase(it);
        } else {
            it++;
        }
    }
}


#endif // MYLIST_H

