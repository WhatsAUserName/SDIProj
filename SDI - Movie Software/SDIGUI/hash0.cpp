#pragma once
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here
#include "hash0.h"

/* Given:  Nothing.
Task:   This is the constructor for the HashTableClass.  It
initializes the table as an empty hash table.
Return: Nothing, though the implicit object is created.
*/
HashTableClass::HashTableClass(void)
{
	int k;

	NumItems = 0;
	for (k = 0; k < PrimeSize; k++)
	{
		TableArray[k] = EmptyItem;
		OrderArray[k] = 0;
	}
}


/* Given:   Nothing (other than the implicit object).
Task:    To see if this HashTableClass object is empty.
Return:  In the function name, true if table is empty, false otherwise.
*/
bool HashTableClass::Empty(void) const
{
	return (NumItems == 0);
}


/* Given:   Nothing (other than the implicit object).
Task:    To see if this HashTableClass object is full.
Return:  In the function name, true if table is full, false otherwise.
*/
bool HashTableClass::Full(void) const
{
	return (NumItems == PrimeSize);
}


/* Given:   Key   The item to be inserted into the table.
Assumes: That Key is not a duplicate of a value already in the table.
No attempt is made to handle duplicates properly.
Task:    To insert Key into the table.
Return:  In the function name, true if Key was inserted OK, false otherwise.
*/
bool HashTableClass::Insert(KeyType Key)
{
	bool Success;
	int k, Index;

	// Clear out OrderArray:
	for (k = 0; k < PrimeSize; k++)
		OrderArray[k] = 0;

	Success = false;
	if (Full())   // Table is full, give up on inserting.
		return Success;

	Index = Hash(Key);

	// Allow up to PrimeSize indices to be checked:
	for (k = 0; k < PrimeSize; k++)
	{
		OrderArray[Index] = k + 1;
		if ((TableArray[Index] == EmptyItem) || (TableArray[Index] == DeletedItem))
		{
			Success = true;
			NumItems++;
			TableArray[Index] = Key;
			break;
		}
		else
			Index = Rehash(Index);
	}

	return Success;
}


/* Given:  Key   The item to be deleted from the table.
Task:   To delete Key from the table.
Return: In the function name, true if Key was deleted OK, false otherwise (most
likely because Key could not be found in the table).
*/
bool HashTableClass::Delete(KeyType Key)
{
	bool Success;
	int k, Index;

	// Clear out OrderArray:
	for (k = 0; k < PrimeSize; k++)
		OrderArray[k] = 0;

	Success = false;
	if (Empty())   // Table is empty, give up on deleting.
		return Success;

	Index = Hash(Key);

	// Allow up to PrimeSize indices to be checked:
	for (k = 0; k < PrimeSize; k++)
	{
		OrderArray[Index] = k + 1;
		if (TableArray[Index] == Key)
		{
			Success = true;
			NumItems--;
			TableArray[Index] = DeletedItem;
			break;
		}
		else if (TableArray[Index] == EmptyItem)   // Give up, Key cannot be beyond here in the rehash path.
			break;
		else   // We have a deleted item or the wrong key, keep looking.
			Index = Rehash(Index);
	}

	return Success;
}


/* Given:  Key  The key value to search for.
Task:   To search for Key in the table.
Return: In function name, true if Item was found, false otherwise.
Index   The index for the location in the table where Key was found.
(But if false is returned, the value of Index is meaningless.)
*/
bool HashTableClass::Lookup(KeyType Key, int & Index)
{
	bool Success;
	int k;

	// Clear out OrderArray:
	for (k = 0; k < PrimeSize; k++)
		OrderArray[k] = 0;

	Success = false;
	if (Empty())   // Table is empty, give up on the lookup.
		return Success;

	Index = Hash(Key);

	// Allow up to PrimeSize indices to be checked:
	for (k = 0; k < PrimeSize; k++)
	{
		OrderArray[Index] = k + 1;
		if (TableArray[Index] == Key)
		{
			Success = true;
			break;
		}
		else if (TableArray[Index] == EmptyItem)   // Give up, Key cannot be beyond here in the rehash path.
			break;
		else   // We have a deleted item or the wrong key, keep looking.
			Index = Rehash(Index);
	}

	return Success;
}


/* Given:   Key   A KeyType value.
Assumes: That KeyType is an int or long (or that % is overloaded
to handle appropriately the particular data type).
Task:    To find the Hash function value for Key.
Return:  This hash function value in the function name.
*/
int HashTableClass::Hash(KeyType Key) const
{
	return Key % PrimeSize;
}


/* Given:   Index   An index into the hash table.
Task:    To find the Rehash function value for the given Index.
Return:  This Rehash function value in the function name.
*/
int HashTableClass::Rehash(int Index) const
{
	return (Index + 2) % PrimeSize;
}

