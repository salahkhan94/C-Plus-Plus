#include <iostream>

using namespace std;

template<typename T>
class node{
    public:
        node(){}
        node(T data){
            this->data = data;
        }
        ~node(){
            delete next;
        }
        void setdata(T data){
            this->data= data;
        }
        void setnext(node * next){
            this->next = next;
        }
        node* getnext(){
            return next;
        }
        T getdata(){
            return data;
        }
    private:
        T data;
        node* next=NULL;
};

template<typename T>
class linkedlist{
    public:
        linkedlist(){}
        node<T>* insert(node<T> *start, T data){
            node<T> *t = start;
            node<T> *n= new node<T>(data);
            if(start!=NULL){
                for(;t->getnext()!=NULL;t = t->getnext()){}
                t->setnext(n);
            }
            else{
                start = n;
            }
            return start;
        }
        void remove(node<T> *start, T data){
            if(start==NULL){
                std::cout << "\nLinked List is empty\n";
                return;
            }
            else{
                node<T> *t =start;
                node<T> *parent = start;
                while(t!=NULL && t->getdata()!=data){
                    parent = t;
                    t=t->getnext();
                }
                if(t->getdata()==data){

                    parent->setnext(t->getnext());
                    delete t;
                    return;
                }
                else{
                    std::cout<<"data not found"<<endl;
                    return;
                }

            }
        }
        node<T> * reverse(node<T>* start){
            if(start==NULL){
                std::cout << "\nLinked List is empty\n";
                return start;
            }
            else{
                node<T>* t = start->getnext();
                node<T>*child = start;
                node<T>*parent = start->getnext();
                child->setnext(NULL);
                while(t!=NULL){
                    //std::cout<<"child at : "<<t->getdata()<<endl;
                    t=parent->getnext();
                    parent->setnext(child);
                    child = parent;
                    parent = t;
                }
                return child;
            }
        }
        void show(node<T>* start){
            if(start==NULL){
                std::cout << "\nLinked List is empty\n";
                return;
            }
            node<T>* temp=start;
            while(temp!=NULL){
                std::cout<<"Val : "<<temp->getdata()<<endl;
                temp = temp->getnext();
            }
        }
};

int main()
{
    node<int> *start=NULL;
    linkedlist<int> ll;
    start = ll.insert(start,2);
    start =ll.insert(start,3);
    start =ll.insert(start,4);
    start =ll.insert(start,5);
    start =ll.insert(start,6);
    start =ll.insert(start,7);
    start =ll.insert(start,8);
    ll.show(start);
    start = ll.reverse(start);
    ll.show(start);
}