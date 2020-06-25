#include<string>
using namespace std;
// Hashmap is implemented using chaining
template <typename V>


// Mapnode class for linked list implemenetation of node
// Assuming the key is of string data type
class MapNode{
public:
	string key;
	V value;
	MapNode* next;

	// constructor
	MapNode(string key,V value)
	{
		this->key = key;
		this->value = value;
		next = NULL;
	}

	// destructor delete nodes recursively
	~MapNode()
	{
		delete next;
	}
};

class HashMap
{
	// array of mapnodes pointer
	MapNode<V>** buckets;
	int numBuckets;
	int size;
public:
	// constructor
	HashMap()
	{
		numBuckets = 10;
		buckets = new Mapnode<V>*[numBuckets];

		for(int i=0;i<numBuckets;i++)
		{
			buckets[i]=NULL;
		}

		size = 0;
	}
	~HashMap()
	{
		// delete every key
		for(int i=0;i<numBuckets;i++)
			delete buckets[i];

		//delte the buckets array
		delete [] buckets;
	}

	// Others members function
	// getValue(key)
	// insert(key,value)
	// remove(key,velue)
	// getSize of map

	int getSize()
	{
		return size;
	}

	V getValue(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		
		while(head!=NULL)
		{
			// If key matches then return value
			if(head->key==key)
			{
				return head->value;
			}
			head= head->next;
		}
		// If element is not present return 0
		return 0;
	}
private:
	// Hasing function 
	// Uses polynomial function to hash the values
	int getBucketIndex(string key)
	{
		// coefficient of polynomial
		int currentCoefficient  = 1;
		int hashcode = 0;

		for(int i = key.size()-1;i>=0;i--)
		{
			hashcode += key[i] * currentCoefficient;
			// hashcoce should not be greater than the bucket size
			hashcode = hashcode % numBuckets;

			// Increment current coefficient 
			currentCoefficient *= 37;
			currentCoefficient = currentCoefficient % numBuckets;

		}
		return hashcode % numBuckets;
	}
public:
	void insert(srtring key,int value)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];

		// check if key and value already present then insert nohting

		while(head!=NULL)
		{
			if(head->key == key and head->value==value)
				return;
			head = head->next;
		}

		// Else insert the node
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key,value);
		node->next = head;
		buckets[bucketIndex]=node;
		size++;

	}

	// remove the node
	V remove(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* previous = head;

		while(head!=NULL)
		{
			// if key is found
			if(head->key==key)
			{
				// If the key element is the first elemet
				if(prev==NULL)
				{
					// then map points to the the next key
					// do not forget to delete the head
					buckets[bucketIndex]= head->next;
				}
				else
				{
					// if previous not null then privous should
					// point to the next key
					previous->next=head->next;
				}

				//delete the node
				// return the value before deleting
				// reduce the size of the map
				V value = head->value;
				delete head;
				size--;
				return value;

			}
			else{
				previous=head;
				head=head->next;
			}

		}

		// key not found
		return 0;

	}


};