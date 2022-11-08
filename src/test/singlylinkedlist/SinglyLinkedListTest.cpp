#include <iostream>
#include <list>

#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"


template <class Ptr>
struct BlockList {
    struct block;

    // using block_ptr_t = typename std::pointer_traits<Ptr>::template rebind<block>;
    using block_ptr_t = typename std::pointer_traits<Ptr>::template rebind<block>; 

    struct block {
        std::size_t size{};
        block_ptr_t next_block{}; 
    };
    block_ptr_t free_blocks; 
};

template <class _Con>
void print_container(const _Con& container) {
    for (auto ele : container) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

struct President {
    std::string name;
    std::string country;
    int year;

    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(std::move(p_year)) {
            std::cout << "I am being constructed \n";
        } // constructor
    
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(std::move(other.year)) {
            std::cout << "I am being moved \n";
        } // move constructor 

    ~President() {
        std::cout << name << ": I am being deleted \n";
    }

    President& operator=(const President& other) = default; // Copy assignment constructor 


    friend std::ostream& operator<<(std::ostream& os, const President& pre) {
        os << "President: " << pre.name << " " << pre.country << " " << pre.year << std::endl;
        return os; 
    }
};

template <class _Tp>
void print(const _Tp& xs) {
    for (auto& ele : xs) {
        std::cout << ele;
    }
    std::cout << std::endl; 
}

int main() {
    dsa::doubly_linked_list<President> president_lst;
    try
    {
        president_lst.pop_back();    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    president_lst.push_front(President("Donald Trump front", "USA", 2010));
    president_lst.push_front(President("Obama front", "USA", 2011));
    president_lst.push_front(President("Bilinton front", "USA", 2000));
    president_lst.emplace_front("Donald Trump1 front", "USA1", 2010);
    president_lst.emplace_front("Obama1 front", "USA", 2011);
    president_lst.emplace_front("Bilinton1 front", "USA", 2000);

    while(true)
        print(president_lst);
    
    return 0;
}
