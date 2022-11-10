/**
 * @file    Stack.h
 * @author  (original JAVA) William Fiset, william.alexandre.fiset@gmail.com
 *          (convert to C++) Toan Dang, dangnhattoan@gmail.com 
 * @date    Nov 08, 2022
 * @version 0.1
 * @brief   A stack class
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <deque>

namespace dsa {
    template <class _Tp, class _Container = std::deque<_Tp> >
    class stack;

    template < class _Tp, class _Container /*= std::deque<T>*/ >
    class stack {
        public:
            using container_type = _Container;
            
            using value_type = typename container_type::value_type;
            using reference = typename container_type::reference;
            using const_reference = typename container_type::const_reference;
            using size_type = typename container_type::size_type;
            static_assert( (std::is_same<_Tp, value_type>::value),"" );
        
        protected:
            container_type c;

        public:
            stack() {}
            stack(container_type __c) noexcept(std::is_nothrow_copy_constructible<container_type>::value) : c{__c} {}
            stack(const stack& __s) : c{__s.c} {}
            stack& operator=(const stack& __s) {
                c = __s.c;
                return *this;
            }
            stack(stack&& __s) noexcept(std::is_nothrow_move_constructible<container_type>::value)
                : c{std::move(__s.c)} {}
            stack& operator=(stack&& __s) {
                c = std::move(__s.c);
                return *this;    
            }

            inline void push(const _Tp& element) {c.push_back(element);}
            inline void push(_Tp&& element) {c.push_back(std::forward<_Tp>(element));}
            
            inline void pop() {c.pop_back();}

            inline reference top() {return c.back();}
            inline const_reference top() const {return c.back();}

            inline bool empty() const {return c.empty();}
            inline std::size_t size() const {return c.size();}
    };
}

#endif /* STACK_H */