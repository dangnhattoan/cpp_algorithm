/**
 * @file    SinglyLinkedList.h
 * @author  Toan Dang, dangnhattoan@gmail.com 
 * @date    25 Oct 2022
 * @version 0.1
 * @brief   A singly linked list implementation.
*/

#ifndef S_LINKLIST_H
#define S_LINKLIST_H

#include <iostream>

/** @brief  Struct of singly linked list node  */
template <class T>
struct Node {
    T data_;
    Node *next_;

    explicit Node(T value, Node<T> *ptr) : data_{value}, next_{ptr} {};
};

/*
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**                           PROTOTYPES SECTION
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

template <class T, bool Const>
class SinglyLinkedListIterator;

/** @brief  SinglyLinkedList class  */
template <class T>
class SinglyLinkedList {
    private:
        size_t size_;
        Node<T> *head_ = nullptr;
        Node<T> *tail_ = nullptr;
    public:
        using iterator = SinglyLinkedListIterator<T, false>;
        using const_iterator = SinglyLinkedListIterator<T, true>;
        iterator begin() { iterator it{head_}; return it; }                     // Iterator begin()
        iterator end() { iterator it{nullptr}; return it; }                     // Iterator end()
        const_iterator cbegin() const {const_iterator it{head_}; return it;}     // Constant iterator begin()
        const_iterator cend() const {const_iterator it{nullptr}; return it;}    // Constant iterator end()
        
        SinglyLinkedList(){};
        size_t size() const { return size_; }
        bool isEmpty() const { return size() == 0;}
        void addLast(const T& value);
        void addFirst(const T& value);
        iterator insert(const_iterator It, const T& value);

        ~SinglyLinkedList(){
            for (Node<T> *p = head_, *next; p != nullptr; p = next) {
                next = p->next_;
                delete p;
            }
        }
};

/*
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**                           FUNCTIONS SECTION
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      Add new element into the singly linked list. Time complexity: O(1)
**
** @param [in]
**      value: Value of the new element
**
** @return
**       None
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template <class T>
void SinglyLinkedList<T> :: addLast(const T& value) {
    Node<T> *new_tail = new Node<T>(value, nullptr);
    if (tail_) {
        tail_->next_ = new_tail;
    } else {
        head_ = new_tail;
    }
    tail_ = new_tail;
    size_++;
}


/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      Add new element to the beginning of the linked list. Time complexity: O(1)
**
** @param [in]
**      value: Value of the new element
**
** @return
**       None
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template <class T>
void SinglyLinkedList<T> :: addFirst(const T& value) {
    Node<T> *new_head = new Node<T>(value, nullptr);
    if (head_) {
        new_head->next_ = head_;
    } else {
        tail_ = new_head;
    }
    head_ = new_head;
    size_++;
}

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      Add new element at specific index. Time complexity: O(n)
**
** @param [in]
**      value: Value of the new element
**
** @return
**       iterator: the iterator of new node
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template <class T>
typename SinglyLinkedList<T>::iterator SinglyLinkedList<T> :: insert(const_iterator It, const T& value) {
    iterator result = iterator{nullptr};
    
    /* Time complexity: O(1) */
    if (It == cbegin()) {
        addFirst(value);
        return begin();
    }

    /* Time complexity: O(1) */
    if (It == const_iterator{tail_}) {
        addLast(value);
        return iterator{tail_};
    }

    /* Time complexity: O(n) */
    Node<T> *tmp = head_;
    for (auto cIt = cbegin(); cIt != cend(); ++cIt) {
        if (It == cIt) {
            /*Insert new node after the found iterator*/
            Node<T> *newNode = new Node<T>(value, tmp->next_);
            tmp->next_ = newNode;
            size_++;
            return iterator{newNode};
        }
        tmp = tmp->next_;
    }

    return result;
}

/** 
 * @brief  
 *          SinglyLinkedListIterator class
 *  @note         
 *          The iterator category is forward_iterator
*/
template <class T, bool Const>
class SinglyLinkedListIterator {
    friend class SinglyLinkedList<T>;
    friend class SinglyLinkedListIterator<T, !Const>;
    using node_ptr = std::conditional_t<Const, const Node<T>*, Node<T>* >;
    node_ptr ptr_;

    public:
        using reference = std::conditional_t<Const, const T&, T&>;

        /* Iterator Traits */
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;
        using pointer = std::conditional_t<Const, const T*, T*>;
        using value_type = T;
        
        explicit SinglyLinkedListIterator(Node<T> *ptr) : ptr_{ptr} {};
        reference operator*() const { return ptr_->data_; }
        auto& operator++() { ptr_ = ptr_->next_ ; return *this; }               // preincrement ++i
        auto operator++(int) { auto result = *this; ++*this; return result; }   // postincrement i++
        
        template <bool R>
        bool operator==(SinglyLinkedListIterator<T, R>& rhs) const { return ptr_ == rhs.ptr_; }

        template <bool R>
        bool operator!=(SinglyLinkedListIterator<T, R>& rhs) const { return ptr_ != rhs.ptr_; }
};

#endif /* S_LINKLIST_H */