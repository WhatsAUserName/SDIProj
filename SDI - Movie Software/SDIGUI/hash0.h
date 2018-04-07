#include <string.h>

const int PrimeSize = 17;  // The size of the table should be a prime number.
const int EmptyItem = 0;
const int DeletedItem = -1;

typedef int KeyType;
typedef KeyType TableArrayType[PrimeSize];
typedef int OrderArrayType[PrimeSize];
typedef char TitleType;

class HashTableClass
   {
   public:
      HashTableClass(void);
      // No specialized destructor is needed.
      bool Empty(void) const;
      bool Full(void) const;
      bool Insert(KeyType Key);
      bool Delete(KeyType Key);
      bool Lookup(KeyType Key, int & Index);
      // Normally, data fields are private, but they are public here so that
      // their data can be easily retrieved and displayed.
      TableArrayType TableArray;   // Where the hash table data is stored.
      OrderArrayType OrderArray;   // Keeps track of the rehash path used.
	  TitleType title;
	  
   private:
      int NumItems;   // Number of items currently stored in the table.
      int Hash(KeyType Key) const;
      int Rehash(int Index) const;
	  
	  
   };