class BST {
	// Complete this class
    BinaryTreeNode<int> * root;
    
    bool search(BinaryTreeNode<int>* root,int element)
    {
        if(root==NULL)
        {
            return false;
        }
        if(element==root->data)
            return true;
        if(element < root->data)
        {
            return search(root->left,element);
        }
        return search(root->right,element);
    }
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root,int element)
    {
        if(root==NULL)
        {
            root= new BinaryTreeNode<int>(element);
            return root;
        }
        if(element < root->data)
        {
            root->left = insert(root->left,element);
        }
        else
            root->right = insert(root->right,element);
        return root;
    }
    BinaryTreeNode<int>* minELement(BinaryTreeNode<int>* root)
    {
        BinaryTreeNode<int>* current = root;
        
        while(current!=NULL and current->left!=NULL)
            current = current->left;
        return current;
    }
    BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root,int element)
    {
        if(root==NULL)
        {
            return root;
        }
        // delete the node
        if(root->data == element)
        {
            // if leaf node 
            if(root->left == NULL and root->right==NULL)
            {
                delete root;
                return NULL;
            }
            // if only left child
            // delete current node  and the left child will be the current BST
            else if(root->left!=NULL and root->right==NULL)
            {
                BinaryTreeNode<int>* temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            // If onlt right child same as left 
            else if(root->left==NULL and root->right!=NULL)
            {
                BinaryTreeNode<int>* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            // special case both child are present
            // the inorder predecessor will the required node
            // inorder predecssor will the minimum element of the right subtree
            // which is equal to the left most child of right subtree
            else
            {
                BinaryTreeNode<int>* minNode = minELement(root->right);
                root->data = minNode->data;
                root->right = deleteNode(root->right,root->data);
                return root;
            }
        }
        else if( element < root->data)
        {
            root->left = deleteNode(root->left,element);
        }
        else
        	root->right = deleteNode(root->right,element);
        return root;
    }
    
    void printTree(BinaryTreeNode<int>* root)
    {
      if(root==NULL) return;
  		
      
  		cout<<root->data<<":";
    	if(root->left!=NULL)
      	cout<<"L:"<<root->left->data<<",";
    	if(root->right!=NULL)  
      	cout<<"R:"<<root->right->data;
     	cout<<endl;
      	printTree(root->left);
      	printTree(root->right);
    }
    public:
    BST()
    {
        root = NULL;
    }
    
    
    
    void insert(int element)
    {
        root = insert(root,element);
    }
    bool hasData(int element)
    {
        return search(root,element);
    }
    void deleteData(int element)
    {
        root=deleteNode(root,element);
    }
  	void printTree()
    {
        printTree(root);
    }
};
