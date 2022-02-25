//Brute force implementation without extra space or datastructure.
//Time complexity - O(n^2) - n = no. of elements in the linked list.
//Space complexity - O(1)

#include<iostream>


//Node implementation.
//Not part of the algorithm.
class Node{

    private:
    int value;
    Node* next;

    public:

    //Constructor initialises the node.
    Node(int value){
        this->value = value;
        this->next = NULL;
    }

    void setValue(int value){
        this->value = value;
    }

    void setNext(Node* next){
        this->next = next;
    }

    int getValue(){return this->value;}
    Node* getNext(){return this->next;}


};

//Linked List implementation. 
//Not part of the algorithm.
class LinkedList{

    private:
    Node* head;

    public:

    LinkedList(){
        this->head = NULL;
    }

    //insert at the head of the linked list.
    //Time complexity O(1)
    void insertAtHead(int value){

        Node* node = new Node(value); //new node created.

        if(head==NULL){
            head = node;              //if head is null then the new node becomes the head.
        }else{
            node->setNext(head);      
            head = node;
        }
    }

    //insert at the end of the linked list.
    //Time complexity O(n)
    void insertAtEnd(int value){

        Node* node = new Node(value);

        if(head==NULL){
            head = node;
        }else{

            Node* temp = head;
            while(temp->getNext() != NULL){  // iterating through all the nodes to get to the end.
                temp = temp->getNext();
            }
            temp->setNext(node);
        }

    }

    //function just to display the linked list.
    void display(){
        Node* temp = head;
        while(temp != NULL){
            std::cout<<temp->getValue()<<" -> ";
            temp = temp->getNext();
        }
    }

    Node* getHead(){
        return this->head;
    }

};


//Algorithm for the problem.
//function the remove duplicates.
void removeDuplicated(LinkedList &ls){

    Node* currentNode = ls.getHead();                                                //get the head of the linked list in currecnt node pointer.

    while (currentNode != NULL)
    {
        Node* nextPointer = currentNode;                                             //second pointer to check the future duplicate values.

        while(nextPointer->getNext() != NULL){

            if (nextPointer->getNext()->getValue() == currentNode->getValue())      //if found duplicate.
                nextPointer->setNext(nextPointer->getNext()->getNext());            //set the next element to the duplicate as the next element to the pointer. This removes the connection of the duplicate element with the linked list.
            else
                nextPointer = nextPointer->getNext();   
        }
        currentNode = currentNode->getNext();
    }
}

int main(){

    LinkedList ls;
    int n;
    std::cout<<"Enter the size of the list : ";
    std::cin>>n;
    int value;

    for (int i = 0; i < n; ++i)
    {
        std::cin>>value;
        ls.insertAtEnd(value);
    }
    std::cout<<"List Before : "<<std::endl;
    ls.display();
    removeDuplicated(ls);
    std::cout<<std::endl<<"List after : "<<std::endl;
    ls.display();
    std::cout<<std::endl;

}