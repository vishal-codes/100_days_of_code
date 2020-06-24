template<typename T>
class Queue {
    
    Node<T>* f;
    Node<T>* rear;
  	int size;
    public :
    
    
    Queue() {
        size=0;
      	f=NULL;
      	rear=NULL;
    }
    
    void enqueue(T data) {
        Node<T>* n = new Node<T>(data);
      if(size==0)
      {   f=n;
       		rear=n;
      }
      else
      {
        rear->next=n;
      	rear=n;
      }
      	
       size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    T dequeue() {
        // Return 0 if queue is empty
      if(size==0) return 0;
      Node<T>* temp = f;
      T a= f->data;
      f=f->next;
      delete temp;
      if(size==1) rear=NULL;
      size--;
      return a;
    }
    
    T front()  {
        // Return 0 if queue is empty
      if(size==0)
      return 0;
      
      return f->data;
    }
};
