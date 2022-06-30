struct Node
{
    char letter;
    Node* next = NULL;
};

void addNodeLeft(Node** pHead, char newChar)
{
    Node* newNode = new Node;
    *newNode = {newChar, *pHead};
    *pHead = newNode;
}

void addNodeRight(Node** pHead, char newChar)
{
    Node* newNode = new Node;
    Node* temp = *pHead;
    *newNode = {newChar, NULL};

    if (*pHead == NULL)  
    {  
        *pHead = newNode;  
        return;  
    } 

    while(temp->next!=NULL) temp = temp->next;

    temp->next = newNode;
}

void addNodeMid(Node** pHead, char newChar, int index)
{
    Node* temp = *pHead;

    for(int i = 1; i<index; i++) temp = temp->next;

    Node* newNode = new Node;
    *newNode = {newChar, temp->next};
    temp->next = newNode;
}

void reverse(Node** pHead)
{
    Node *current = *pHead, *prev = NULL, *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *pHead = prev;
}

void deleteNode(Node** pHead, int index)
{
    Node* temp = *pHead;

    if(index == 1)
    {
        *pHead = temp->next;
        delete temp;
    }
    else
    {
        Node* prev = NULL;

        for(int i = 1; i<index; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;
    }
}

void deleteList(Node** pHead)
{
    Node* current = *pHead;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }

    *pHead = NULL;
}

char getLetter(Node* temp, int index)
{
    for(int i = 1; i<index; i++) temp = temp->next;
    return temp->letter;
}

void printIndex(Node* temp)
{
    cout << "Index  | ";
    int i = 1;
    while(temp!=NULL)
    {
        cout << i << " | ";
        temp = temp->next;
        i++;
    }
    cout << '\n';
}

void printLetter(Node* temp)
{
    cout << '|';
    while(temp!=NULL)
    {
        cout << " " << temp->letter << " |";
        temp = temp->next;
    }
    cout << '\n';
}