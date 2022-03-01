//Direct implemenation without creating any extra space.
//time complexity - o(1).
//Space complexity - O(1).

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

//Function to fill the linked list with values.
void fill(LinkedList &ls , int n){

    
    int value;
    for (int i = 0; i < n; ++i)
    {
        std::cin>>value;
        ls.insertAtEnd(value);
    }

    std::cout<<"List Before : "<<std::endl;
    ls.display();

}

//Algorithm to delete the middle with only middle node given.
void deleteMiddle(Node* &middle){

    if (middle->getNext() == NULL) return;
    middle->setValue(middle->getNext()->getValue());
    middle->setNext(middle->getNext()->getNext());
}
int main(){

    LinkedList ls;
    int n;

    std::cout<<"Enter the size of the list : ";
    std::cin>>n;

    fill(ls , n);
    int pos;

    std::cout<<"\nEnter the position of the node to delete (starting from 0 index): ";
    std::cin>>pos;

    Node* temp = ls.getHead();
    while (pos-- > 0)
        temp = temp->getNext();

    deleteMiddle(temp);
    std::cout<<"List after : "<<std::endl;
    ls.display();

}