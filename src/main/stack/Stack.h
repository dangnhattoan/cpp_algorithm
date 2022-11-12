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
    /** 
     * @brief stack is a container adaptor which has the functionality of a stack, a LIFO (last in, first out)
     *      data stucture
     * 
     * @tparam
     *      _Tp the type of stored element
     * @tparam
     *      _Container the type of underlying container to use to store the elements
    */
    template < class _Tp,
            class _Container = std::deque<_Tp>
    > class stack {
        public:
            using container_type = _Container;                                  //!< container_type
            
            using value_type = typename container_type::value_type;             //!< value_type
            using reference = typename container_type::reference;               //!< reference
            using const_reference = typename container_type::const_reference;   //!< const_reference
            using size_type = typename container_type::size_type;               //!< size_type
            static_assert( (std::is_same<_Tp, value_type>::value),"" );
        
        protected:
            container_type c;                                                   //!< container to store elements

        public:
            /** @brief default constructor */
            stack() {}

            /**
             *  @brief 
             *      constructor 
             * 
             * @param[in]
             *      __c: container that stores element
             * 
             * */
            stack(container_type __c) noexcept(std::is_nothrow_copy_constructible<container_type>::value) : c{__c} {}

            /** @brief copy constructor */
            stack(const stack& __s) : c{__s.c} {}

            /** @brief copy assignment operator */
            stack& operator=(const stack& __s) {
                c = __s.c;
                return *this;
            }

            /** @brief move constructor */
            stack(stack&& __s) noexcept(std::is_nothrow_move_constructible<container_type>::value)
                : c{std::move(__s.c)} {}

            /** @brief move assignment operator */
            stack& operator=(stack&& __s) {
                c = std::move(__s.c);
                return *this;    
            }

            /**
             * @brief
             *      push the givent element to the top of the stack
             * 
             * @param[in]
             *      element element pushed into the stack
             * 
            */
            inline void push(const _Tp& element) {c.push_back(element);}

            /**
             * @brief
             *      push the givent element to the top of the stack
             * 
             * @param[in]
             *      element element pushed into the stack
             * 
            */
            inline void push(_Tp&& element) {c.push_back(std::forward<_Tp>(element));}
            
            /** @brief remove the top element from the stack*/
            inline void pop() {c.pop_back();}

            /**
             * @brief
             *      return reference to the element at the top of the stack
             * 
             * @return
             *      reference to the top element
            */
            inline reference top() {return c.back();}

            /**
             * @brief
             *      return constant reference to the element at the top of the stack
             * 
             * @return
             *      constant reference to the top element
            */
            inline const_reference top() const {return c.back();}

            /** @brief check wheter the stack is empty */
            inline bool empty() const {return c.empty();}

            /** @brief return the size of the stack */
            inline std::size_t size() const {return c.size();}
    };
}

#endif /* STACK_H */