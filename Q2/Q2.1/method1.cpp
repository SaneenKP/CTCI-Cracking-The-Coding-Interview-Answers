//Brute force implementation without extra space or datastructure.
//Time complexity - O(n) - n = no. of elements in the linked list.

#include<iostream>


//Node class for each node which holds value and the address of next node.
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

//Linked List class which connects all of the nodes.
//head is the root node.
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

void removeDuplicated(LinkedList &ls){

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
    ls.display();
    removeDuplicated(ls);
    ls.display();

}