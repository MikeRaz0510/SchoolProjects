/*	Mike Rasmussen
*	z1696323
*	CSCI340 PE1
* 
*	I certify that this is my own work and where appropriate an extension 
* 	of the starter code provided for the assignment.
*/
#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...
/**
 * @brief Construct a new HT::HT object
 * 
 * @param hs 
 ************************************************************************/
HT::HT(const unsigned &hs) 
  : hs()
{
  /*
   *The hash table, which is a vector of list containers, can be created 
   *dynamically for a given fixed size hs by its constructor. Initially, 
   *the pointer table, which is a vector of type Entry *, is empty but 
   *its size will increase dynamically after inserting a new Entry item in
   *this table, which is the address of the inserted item in the 
   *corresponding list container. 
   */

  std::vector<std::list<Entry> htable(hs, std::list<Entry>(Entry("","",0)));
  std::vector<Entry*> ptable;

}

/**
 * @brief Destroy the HT::HT object
 * 
 ************************************************************************/
HT::~HT() 
{
  /* Since the hash table is implemented as a vector of list containers, 
   *the destructor of the hash table first frees the memory for all list 
   *containers and then frees the memory for the vector containers for 
   *the hash table and the pointer table.
   */
 for (int i = htable.size()-1; i > 0; --i)
 {
    for (int j = 0; j < htable[i].size(); j++)
    {
      htable[i].pop_back();
    }
    htable.pop_back();
 }
}

/**
 * @brief 
 * 
 * @param e 
 ************************************************************************/
void HT::insert(const Entry &e) 
{
  /* This public function inserts the record of the item e:(key, desc, num) 
   *in the hash table. If the key already exists in the table, then the 
   *function prints an error message; otherwise, it prints the index value 
   *of the inserted record in the hash table and it also inserts the address 
   *of the record (in the hash table) into the pointer table. Since each 
   *element of the hash table is implemented as a list container with the 
   *data type Entry, in the case of a collision, simply insert the new record 
   *at the beginning of the corresponding list container. To check if the 
   *record e is already in the hash table, you can use the function find_if() 
   *in the STL. To compare the key of the record e with the keys of the elements 
   *in the list container, list<Entry> &l = hTable[i], in hash table position i, 
   *you can use either a predicate or a lambda for the compare component of the 
   *find_if() function. If the item is a new item, then the find_if() function 
   *returns l.cend().
   */
  int i = hash(e.key);
  htable[i].pushback(e);

  cout << "insert: :" << e.key << ":" << e.num << ':' << e.desc << ": Entry = " << i << endl;
  
  
}
/**
 * @brief 
 * 
 * @param s 
 ************************************************************************/
void HT::search(const string &s) 
{
  /* This public function searches the hash table for a record with key. 
   *As in the insert() function, you can use the find_if() function from 
   *in the STL to search for a record in the hash table. If the search is 
   *successful, search() function prints the information for the record; 
   *otherwise, it prints an error message.
   */
}

/**
 * @brief 
 * 
 ************************************************************************/
void HT::hTable_print() 
{
  /* This public function prints the subscript and the contents of all 
   *(and only) the active records in the hash table.
   */
}

/**
 * @brief 
 * 
 ************************************************************************/
void HT::pTable_print() 
{
  /*This public function prints the contents of all (and only) the active 
   *records in the hash table. Since the records need to be printed in 
   *alphabetical order with their key values, this function first sort the 
   *elements of the pointer table using the sort() function in the STL. The 
   *cmp component for sorting, bool cmp(Entry *p, Entry *q), returns true if 
   *the key of the item in location p comes before the item in location q 
   *in alphabetical order.
   */
}