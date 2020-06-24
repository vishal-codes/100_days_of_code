
template <typename T>
class Stack {
    Node<T> *head;
    int size;       // number of elements prsent in stack
    
    public :
    
    Stack() {
        head=NULL;
        size=0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    void push(T element) {
        Node<T>* n = new Node<T>(element);
        n->next = head;
        head = n;
        size = size+1;
        
    }
    
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        if(head==NULL)
          return 0;
        Node<T>* temp = head;
        head = head->next;
        int a =temp->data;
        delete temp;
        size=size-1;
        return a;
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if(size==0)
          return 0;
        return head->data;
    }
    
  
    
};