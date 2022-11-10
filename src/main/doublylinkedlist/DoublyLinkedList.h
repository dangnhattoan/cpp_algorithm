/**
 * @file    DoublyLinkedList.h
 * @author  (original JAVA) William Fiset, william.alexandre.fiset@gmail.com
 *          (conversion to C++) Toan Dang, dangnhattoan@gmail.com 
 * @date    Nov 03, 2022
 * @version 0.1
 * @brief   A doubly linked list implementation.
*/

#ifndef D_LINKLIST_H
#define D_LINKLIST_H

#include <iostream>
#include <sstream>
#include <iterator>
#include <memory>
#include <iterator>
#include <type_traits>
#include <__cxx_version>
#include <assert.h>

namespace dsa {
    template < class _Tp>
    class doubly_linked_list;

    template <class _Tp>
    class __list_const_iterator;

    template <class _Tp>
    struct __list_node;

    template <class _Tp>
    class _LIBCPP_TEMPLATE_VIS __list_iterator
    {
            friend class doubly_linked_list<_Tp>;
            friend class __list_const_iterator<_Tp>;

        private:
            using __node_pointer = __list_node<_Tp>*;
            __node_pointer __ptr_;

        public:
            /* Iterator traits */
            using value_type = _Tp; 
            using reference = value_type&;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::bidirectional_iterator_tag;
            using pointer = value_type*;

            using const_reference = const value_type&;

            _LIBCPP_INLINE_VISIBILITY
            explicit __list_iterator(__node_pointer __p) noexcept : __ptr_{__p} {}

            _LIBCPP_INLINE_VISIBILITY
            __list_iterator() noexcept : __ptr_{nullptr} {}

            _LIBCPP_INLINE_VISIBILITY
            __list_iterator(const __list_iterator& __p) : __ptr_{__p.__ptr_} {}

            _LIBCPP_INLINE_VISIBILITY
            reference operator*() const {
                return __ptr_->__value_; 
            }

            _LIBCPP_INLINE_VISIBILITY
            pointer operator->() const {
                return std::pointer_traits<pointer>::pointer_to(__ptr_->__value_);
            }

            _LIBCPP_INLINE_VISIBILITY
            __list_iterator& operator++() {
                __ptr_ = __ptr_->__next_;
                return *this;
            }

            _LIBCPP_INLINE_VISIBILITY
            __list_iterator operator++(int) {
                __list_iterator __t = __list_iterator{*this};
                ++(*this);
                return __t; 
            }

            _LIBCPP_INLINE_VISIBILITY
            __list_iterator& operator--() {
                __ptr_ = __ptr_->__prev_;
                return *this; 
            }

            _LIBCPP_INLINE_VISIBILITY
            __list_iterator operator--(int) {
                __list_iterator __t{*this};
                --(*this);
                return __t;
            }
            
            friend _LIBCPP_INLINE_VISIBILITY
            bool operator==(const __list_iterator& __x, const __list_iterator& __y) {
                return __x.__ptr_ == __y.__ptr_;
            }

            friend _LIBCPP_INLINE_VISIBILITY
            bool operator!= (const __list_iterator& __x, const __list_iterator& __y) {
                return !(__x == __y);
            }
    };

    template <class _Tp>
    class _LIBCPP_TEMPLATE_VIS __list_const_iterator
    {
            friend class doubly_linked_list<_Tp>;
            
        private:
            using __node_pointer = __list_node<_Tp>*;
            __node_pointer __ptr_;

        public:
            using value_type = _Tp;
            using iterator_category = std::bidirectional_iterator_tag;
            using reference = const value_type&;
            using pointer = const value_type*;
            using difference_type = std::ptrdiff_t;

            _LIBCPP_INLINE_VISIBILITY
            __list_const_iterator() noexcept : __ptr_{nullptr} {}

            _LIBCPP_INLINE_VISIBILITY
            explicit __list_const_iterator(__node_pointer __p) noexcept : __ptr_{__p} {}

            _LIBCPP_INLINE_VISIBILITY
            __list_const_iterator(const __list_iterator<_Tp>& __p) noexcept : __ptr_{__p.__ptr_} {}

            _LIBCPP_INLINE_VISIBILITY
            reference operator*() const {
                return __ptr_->__value_;
            }

            _LIBCPP_INLINE_VISIBILITY
            pointer operator->() const {
                return std::pointer_traits<pointer>::pointer_to(__ptr_->__value_);
            }

            _LIBCPP_INLINE_VISIBILITY
            __list_const_iterator& operator++() {
                __ptr_ = __ptr_->__next_;
                return *this;
            }

            _LIBCPP_INLINE_VISIBILITY
            __list_const_iterator operator++(int) {
                __list_const_iterator __t{*this};
                ++(*this);
                return __t; 
            }

            _LIBCPP_INLINE_VISIBILITY
            __list_const_iterator& operator--() {
                __ptr_ = __ptr_->__prev_;
                return *this; 
            }

            _LIBCPP_INLINE_VISIBILITY
            __list_const_iterator operator--(int) {
                __list_const_iterator __t{*this};
                --(*this);
                return __t;
            }

            friend _LIBCPP_INLINE_VISIBILITY
            bool operator==(const __list_const_iterator& __x, const __list_const_iterator& __y) {
                return __x.__ptr_ == __y.__ptr_;
            }

            friend _LIBCPP_INLINE_VISIBILITY
            bool operator!=(const __list_const_iterator& __x, const __list_const_iterator& __y) {
                return !(__x == __y);
            }
    };

    template <class _Tp>
    struct __list_node {
        _Tp __value_;

        __list_node * __prev_;
        __list_node * __next_;

        // _LIBCPP_INLINE_VISIBILITY
        // __list_node() = default;

        // _LIBCPP_INLINE_VISIBILITY
        // __list_node(const __list_node<_Tp>& ) = delete;

        // _LIBCPP_INLINE_VISIBILITY
        // __list_node& operator=(const __list_node<_Tp>& ) = delete; 
    };


    template <class _Tp>
    class doubly_linked_list {
        public:
            using _Alloc = std::allocator_traits<std::allocator<__list_node<_Tp>>>;

            using __node_alloc_traits = std::allocator_traits<std::allocator<__list_node<_Tp>>>;
            using __node_allocator = typename std::__rebind_alloc_helper<__node_alloc_traits, __list_node<_Tp>>::type; 
            using size_type = typename __node_alloc_traits::size_type; 
            using __node_pointer = typename __node_alloc_traits::pointer; 

            using __node_destructor = std::__allocator_destructor<__node_allocator>;
            using __hold_pointer = std::unique_ptr<__list_node<_Tp>, __node_destructor>;

            using iterator = __list_iterator<_Tp>;
            using const_iterator = __list_const_iterator<_Tp>;
            using reference = typename iterator::reference;
            using const_reference = typename const_iterator::reference;
            using value_type = _Tp;

            doubly_linked_list() : __size_{0}, __head_{nullptr}, __tail_{nullptr} {}

            ~doubly_linked_list() {} // TODO: to be implemented
            
            std::size_t size() const noexcept {return __size_;}     //!< Return the number of elements in the list
            bool empty() const noexcept {return __size_ == 0;}   //!< Check whether the list is empty

            /* Iterator */
            _LIBCPP_NODISCARD_ATTRIBUTE
            iterator begin() const noexcept { return iterator{__head_}; } //!< Return an iterator to the beginning

            _LIBCPP_NODISCARD_ATTRIBUTE
            iterator end() const noexcept { return __size_ == 0 ? begin() : iterator{nullptr}; }

            _LIBCPP_NODISCARD_ATTRIBUTE
            const_iterator cbegin() const noexcept { return const_iterator{__head_}; }

            _LIBCPP_NODISCARD_ATTRIBUTE
            const_iterator cend() const noexcept { return __size_ == 0 ? cbegin() : const_iterator{nullptr}; }

            /* Element access */
            inline reference front() { return __head_->__value_; }
            inline const_reference front() const { return __head_->__value_; }
            reference back() { return __tail_->__value_; }
            const_reference back() const {return __tail_->__value_;}

            /* Modifiers */
            void push_back(const _Tp& value);
            void push_back(_Tp&& value);
            void push_front(const _Tp& value);
            void push_front(_Tp&& value);

            template <class... _Args>
            void emplace_back(_Args&&... __args);
            
            template <class... _Args>
            void emplace_front(_Args&&... __args);

            void pop_back(void);
            void pop_front(void);

            iterator erase(iterator pos);
            iterator erase(const_iterator pos);
            iterator erase(iterator first, iterator last);

        private:
            std::size_t __size_;
            __list_node<_Tp> * __head_;
            __list_node<_Tp> * __tail_;
            std::__compressed_pair<size_type, __node_allocator> __size_alloc; 
            
            _LIBCPP_INLINE_VISIBILITY
            __node_allocator& __node_alloc() noexcept {
                return __size_alloc.second(); 
            }

            _LIBCPP_INLINE_VISIBILITY
            __hold_pointer __allocate_node(__node_allocator& __na) {
                __node_pointer __p = __node_alloc_traits::allocate(__na, 1); 
                __p->__prev_ = nullptr;
                return __hold_pointer(__p, __node_destructor(__na, 1));
            }

            inline void __link_nodes_as_back(__node_pointer __f, __node_pointer __l);
            inline void __link_nodes_as_front(__node_pointer __f, __node_pointer __l);
            inline void __unlink_nodes(__node_pointer __f, __node_pointer __l);
    };
};      /* namespace dsa  */

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      Link in nodes [__f, __l] at the back of the list
**
** @param [in]
**      __f: first node
**
** @param [in]
**      __f: last node
**
** @return
**       None
** @note
**       Complexity: O(1)
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template <class _Tp>
inline void dsa::doubly_linked_list<_Tp>::__link_nodes_as_back(__node_pointer __f, __node_pointer __l) {
    if (empty()) {
        __head_ = __f; 
    } else {
        __f->__prev_ = __tail_;
        __l->__next_ = __tail_->__next_;
        __tail_->__next_ = __f;
    }

    __tail_ = __l; 
    ++__size_;
}

template <class _Tp>
inline void dsa::doubly_linked_list<_Tp>::__unlink_nodes(__node_pointer __f, __node_pointer __l) {
    if (__f == __head_) {
        __head_ = __l->__next_;
    } else {
        __f->__prev_->__next_ = __l->__next_;
        __l->__next_->__prev_ = __f->__prev_;
    }
}

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      Link in nodes [__f, __l] at the front of the list
**
** @param [in]
**      __f: first node
**
** @param [in]
**      __f: last node
**
** @return
**       None
** @note
**       Complexity: O(1)
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template <class _Tp>
inline void dsa::doubly_linked_list<_Tp>::__link_nodes_as_front(__node_pointer __f, __node_pointer __l) {
    if (empty()) {
        __tail_ = __l;
    } else {
        __head_->__prev_ = __l;
        __l->__next_ = __head_;
        __f->__prev_ = __head_->__prev_;
    }
    __head_ = __f;
    ++__size_;
}

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      Appends the given element value to the end of the list 
**
** @param [in]
**      value: the value of the element to append
**
** @return
**       None
** @note
**       Complexity: O(1)
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template <class _Tp>
void dsa::doubly_linked_list<_Tp>::push_back(_Tp&& __x) {
    typename _Alloc::allocator_type __na;
    typename _Alloc::pointer hold = _Alloc::allocate(__na, 1);
    
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::construct(__nodeAlloc, std::addressof(hold->__value_), std::move(__x));

    __link_nodes_as_back(hold, hold);
}

template <class _Tp>
void dsa::doubly_linked_list<_Tp>::push_back(const _Tp& __x) {
    typename _Alloc::allocator_type __na;
    typename _Alloc::pointer hold = _Alloc::allocate(__na, 1);
    
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::construct(__nodeAlloc, std::addressof(hold->__value_), __x);

    __link_nodes_as_back(hold, hold);
}

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      Prepends the given element value to the beginning of the list
**
** @param [in]
**      value: the value of the element to prepend
**
** @return
**       None
** @note
**       Complexity: O(1)
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template <class _Tp>
void dsa::doubly_linked_list<_Tp>::push_front(_Tp&& __x) {
    typename _Alloc::allocator_type __na;
    typename _Alloc::pointer hold = _Alloc::allocate(__na, 1);
    
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::construct(__nodeAlloc, std::addressof(hold->__value_), std::move(__x));

    __link_nodes_as_front(hold, hold);
}

template <class _Tp>
void dsa::doubly_linked_list<_Tp>::push_front(const _Tp& __x) {
    typename _Alloc::allocator_type __na;
    typename _Alloc::pointer hold = _Alloc::allocate(__na, 1);
    
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::construct(__nodeAlloc, std::addressof(hold->__value_), __x);

    __link_nodes_as_front(hold, hold);
}

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      The element is constructed with input parameters and appended into the end of the list
**
** @param [in]
**      args: the arguments args... are forwarded to the constructor as std::forward<_Args>(args)...
**
** @return
**       None
** @note
**       Complexity: O(1)
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template<class _Tp>
template<class... _Args>
void dsa::doubly_linked_list<_Tp>::emplace_back(_Args&&... args) {
    typename _Alloc::allocator_type __na;
    typename _Alloc::pointer hold = _Alloc::allocate(__na, 1);
    
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::construct(__nodeAlloc, std::addressof(hold->__value_), std::forward<_Args>(args)...);

    __link_nodes_as_back(hold, hold);
}

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      The element is constructed with input parameters and appended into the beginning of the list
**
** @param [in]
**      args: the arguments args... are forwarded to the constructor as std::forward<_Args>(args)...
**
** @return
**       None
** @note
**       Complexity: O(1)
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template<class _Tp>
template<class... _Args>
void dsa::doubly_linked_list<_Tp>::emplace_front(_Args&&... args) {
    typename _Alloc::allocator_type __na;
    typename _Alloc::pointer hold = _Alloc::allocate(__na, 1);
    
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::construct(__nodeAlloc, std::addressof(hold->__value_), std::forward<_Args>(args)...);

    __link_nodes_as_front(hold, hold);
}

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      Remove the last element of the list
**
** @param [in]
**      None
**
** @return
**       None
** @note
**       Complexity: O(1).
**       References and iterators to the erased elements are invalidated.
**       Throw runtime_error exception when the list is empty. 
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template <class _Tp>
void dsa::doubly_linked_list<_Tp>::pop_back() {
    if (empty()) throw std::runtime_error("Empty list");
    
    __tail_ = __tail_->__prev_;
    --__size_;

    /* Release memory */
    typename _Alloc::pointer hold;
    if (empty()) {
        hold = __head_;
        __head_ = nullptr;
    } else {
        hold = __tail_->__next_; 
    }
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::destroy(__nodeAlloc, std::addressof(hold->__value_)); 

    typename _Alloc::allocator_type __na;
    _Alloc::deallocate(__na, hold, 1);
}

/**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
**
** @brief
**      Remove the first element of the list
**
** @param [in]
**      None
**
** @return
**       None
** @note
**       Complexity: O(1).
**       References and iterators to the erased elements are invalidated.
**       Throw runtime_error exception when the list is empty. 
**
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
template <class _Tp>
void dsa::doubly_linked_list<_Tp>::pop_front() {
    if (empty()) throw std::runtime_error("Empty list");

    __head_ = __head_->__next_;
    --__size_;

    /* Release memory */
    typename _Alloc::pointer hold;
    if (empty()) {
        hold = __tail_;
        __tail_ = nullptr;
    }else {
        hold = __head_->__prev_;
    }

    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::destroy(__nodeAlloc, std::addressof(hold->__value_));

    typename _Alloc::allocator_type __na;
    _Alloc::deallocate(__na, hold, 1);
}

template <class _Tp>
typename dsa::doubly_linked_list<_Tp>::iterator dsa::doubly_linked_list<_Tp>::erase(iterator pos) {
    if (pos == end()) throw std::runtime_error("Non-dereferenceable iterator");

    if (pos == begin()) {
        pop_front();
        return begin();
    }

    if (pos == iterator(__tail_)) {
        pop_back();
        return end();
    }

    __node_pointer __n = pos.__ptr_;
    __node_pointer __r = __n->__next_;

    /* Release memory referred by pos */
    __unlink_nodes(__n, __n);
    --__size_;

    typename _Alloc::allocator_type __na;
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::destroy(__nodeAlloc, std::addressof(__n->__value_));
    _Alloc::deallocate(__na, __n, 1);

    return iterator(__r);
}

template <class _Tp>
typename dsa::doubly_linked_list<_Tp>::iterator dsa::doubly_linked_list<_Tp>::erase(const_iterator pos) {
    if (pos == cend()) throw std::runtime_error("Non-dereferenceable iterator");

    if (pos == cbegin()) {
        pop_front();
        return begin();
    }

    if (pos == const_iterator(__tail_)) {
        pop_back();
        return end();
    }

    __node_pointer __n = pos.__ptr_;
    __node_pointer __r = __n->__next_;

    /* Release memory referred by pos */
    __unlink_nodes(__n, __n);
    --__size_;

    typename _Alloc::allocator_type __na;
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;
    std::allocator_traits<std::allocator<_Tp>>::destroy(__nodeAlloc, std::addressof(__n->__value_));
    _Alloc::deallocate(__na, __n, 1);

    return iterator(__r);
}

template <class _Tp>
typename dsa::doubly_linked_list<_Tp>::iterator dsa::doubly_linked_list<_Tp>::erase(iterator first, iterator last) {
    if (first == last) return last;

    __node_pointer __f = first.__ptr_;
    __node_pointer __l, __r;
    if (last == end()) {
        __l = __tail_;
        __r = end().__ptr_;
    } else {
        __l = last.__ptr_->__prev_;
        __r = last.__ptr_;
    }

    __unlink_nodes(__f, __l);
    
    typename _Alloc::allocator_type __na;
    typename std::allocator_traits<std::allocator<_Tp>>::allocator_type __nodeAlloc;

    /* O(n) where n is the n */
    for (__node_pointer ptr = __f; ptr != __l->__next_; ptr = __f) {
        __f = __f->__next_;
        std::allocator_traits<std::allocator<_Tp>>::destroy(__nodeAlloc, std::addressof(ptr->__value_));
        _Alloc::deallocate(__na, ptr, 1);
        --__size_;
    }

    return iterator(__r);
}

#endif /* D_LINKLIST_H */