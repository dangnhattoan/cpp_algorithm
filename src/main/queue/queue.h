/**
 * @file    ArrayQueue.h
 * @author  (original JAVA) William Fiset, william.alexandre.fiset@gmail.com
 *          (conversion to C++) Toan Dang, dangnhattoan@gmail.com 
 * @date    Dec 26, 2022
 * @version 0.1
 * @brief   An array implementation of a queue
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <deque>

namespace dsa {
    /** 
     * @brief queue is a container adaptor that gives the programmer the functionality of a queue, a FIFO
     * (first-in, first-out) data structure.
     * 
     * @tparam
     *      T the type of stored element
     * @tparam
     *      Container the type of underlying container to use to store the elements
    */
    template <typename T, class Container = std::deque<T>>
    class queue
    {
        protected:
            Container _container;                                   //!< container

        public:
            using container_type = Container;                       //!< Type of elements
            using value_type = Container::value_type;               //!< Type of the \em **underlying** container
            using size_type = Container::size_type;                 //!< value_type&
            using reference = Container::reference;                 //!< const value_type&
            using const_reference = Container::const_reference;     //!< size_t

            /**
             *  @brief 
             *      constructor 
             * 
             * @param[in]
             *      cont: container that stores element
             * 
             * */
            explicit queue( const Container& cont = Container() )
            : _container(cont)
            {}

            /**
             *  @brief 
             *      constructor 
             * 
             * @param[in]
             *      cont: container that stores element
             * 
             * */
            explicit queue( const Container&& cont )
            : _container(std::move<Container>(cont))
            {}

            ~queue() = default;

            /**
             * Return true if the %queue is empty.
            */
            bool empty() const
            {
                return _container.empty();       
            }

            /** Returns the number of elements in the %queue */
            size_type size() const {return _container.size();}

            /**
             * Return a read/write reference to the data at the first 
             * element of the %queue.
            */
            reference front()
            {
                return _container.front();
            }

            /**
             * Return a constant reference to the data at the first element
             * of the %queue
            */

            const_reference front() const
            {
                return _container.front();
            }

            /**
             * Return a read/write reference to the data at the last 
             * element of the %queue.
            */
            reference back()
            {
                    return _container.back();
            }

            /**
            * Return a constant reference to the data at the last 
            * element of the %queue.
            */
            const_reference back() const
            {
                return _container.back();
            }

            /**
            *   @brief  Add data to the end of the %queue.
            *   @param  val    Data to be added
            */
            void push(const value_type& val)
            {
                _container.push_back(val);
            }

            /**
            *   @brief  Add data to the end of the %queue.
            *   @param  val    Data to be added
            */
            void push(value_type&& val)
            {
                _container.push_back(std::move(val));
            }

            /**
            *   @brief  Add data to the end of the %queue.
            *   @param  args    Arguments passed to element constructor
            */
            template<typename... _Args>
            decltype(auto) emplace(_Args&&... args)
            {
                return _container.emplace_back(std::forward<_Args>(args)...);
            }

            /**
             * @brief   Removes first element.
            */
            void pop()
            {
                _container.pop_front();
            }
    };
}

#endif  /* QUEUE_H */