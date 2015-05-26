/** ADT priority queue.
Listing 13-4.
@file PriorityQueueInterface.h */

#ifndef _PRIORITY_QUEUE_INTERFACE
#define _PRIORITY_QUEUE_INTERFACE

template<class ItemType>
class PriorityQueueInterface
{
public:
	/** Sees whether this priority queue is empty.
	@return True if the priority queue is empty, or false if not. */
	virtual bool isEmpty() const = 0;

	/** Adds a new entry to this priority queue.
	@post If the operation was successful, newEntry is at the
	priority queue.
	@param newEntry  The object to be added as a new entry.
	@return True if the addition is successful or false if not. */
	virtual bool add(const ItemType& newEntry) = 0;

	/** Removes the entry with the highest priority from the
	priority queue.
	@post If the operation was successful, the entry with the
	highest priority has been removed.
	@return True if the removal is successful or false if not. */
	virtual bool remove() = 0;

	/** Returns the entry in this priority queue with the
	highest priority.
	@pre The queue is not empty.
	@post The entry with the highest priority has been 
	returned, and the queue is unchanged.
	@return The entry with the highest priority. */
	virtual ItemType peek() const = 0;
}; // end PriorityQueueInterface
#endif