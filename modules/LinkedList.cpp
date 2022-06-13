using std::cout;

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

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void addNodeMiddle(Node** pHead, char newChar, int index)
{
    Node* temp = *pHead;

    for(int i = 1; i<index; i++)
    {
        temp = temp->next;
    }

    Node* newNode = new Node;
    *newNode = {newChar, temp->next};
    temp->next = newNode;
}

void printIndex(Node* pHead)
{
    cout << "| ";
    int i = 1;
    while(pHead!=NULL)
    {
        cout << i << " | ";
        pHead = pHead->next;
        i++;
    }
    cout << '\n';
}

void printLinkedList(Node* pHead)
{
    cout << "| ";
    while(pHead!=NULL)
    {
        cout << pHead->letter << " | ";
        pHead = pHead->next;
    }
    cout << '\n';
}

void deleteNode(Node** pHead,Node** pHead2, int index)
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

        addNodeRight(pHead2, temp->letter);
        prev->next = temp->next;
        delete temp;
    }
}