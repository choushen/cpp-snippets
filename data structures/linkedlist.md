# LinkedLists
``` cpp

public node* AddNode(node* current, string content) 
{
    node* tail = new node();
    tail->content = content; // Set the content of the new node
    current->right = tail;
    return tail
}

public node* FindNode(node* head, int id) 
{
    node* current = head;

    while(current != null) 
    {
        if(current->id == id) 
        {
            return current;
        } 
        current = current->right;
    }
    
    return null; // Return null if the node is not found
}

```