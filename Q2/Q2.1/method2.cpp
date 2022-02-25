//implementation using unordered list ie Hashtable.
//Time complexity - O(n) - n = no. of elements in the linked list.
//Space complexity - O(n) - for the hash table.

#include<iostream>
#include<unordered_map>

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

    Node* prevNode = NULL;              //pointer to the previous Node.
    Node* currentNode = ls.getHead();   //pointer to find the duplicates.
    std::unordered_map <int,int> mp;    //map to store the values.


    while (currentNode != NULL)
    {
        if (mp.find(currentNode->getValue()) != mp.end()) 
            prevNode->setNext(currentNode->getNext());  //if not found in map then previous node = next of the duplicate pointer.
        else{
            prevNode = currentNode; 
            mp[currentNode->getValue()]++;  //add value to the map.
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