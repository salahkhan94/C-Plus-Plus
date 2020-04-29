#include <stdexcept>
#include <iostream>

struct wagon
{
	int  data;
    wagon * left;
    wagon * right;
};

class TrainComposition
{
public:
    TrainComposition(){
        head = NULL;
        total = 0;
    }
    void attachWagonFromLeft(int wagonId)
    {   wagon *carr = new wagon;
        carr->data = wagonId;
        carr->left = NULL;
        carr->right = NULL;
        if(head==NULL){
            head = carr;
        }
        else{
            wagon *temp = head;
            while(temp->left!=NULL){
                temp = head->left;
            }
            temp->left  = carr;
            carr->right = temp;
        }
        total++;
    }

    void attachWagonFromRight(int wagonId)
    {
        wagon *carr = new wagon;
        carr->data = wagonId;
        carr->left = NULL;
        carr->right = NULL;
        if(head==NULL){
            head = carr;
        }
        else{
            wagon *temp = head;
            while(temp->right!=NULL){
                temp = head->right;
            }
            temp->right  = carr;
            carr->left = temp;
        }
        total++;
    }

    int detachWagonFromLeft()
    {
        if(head==NULL) return 0;
        wagon *temp = head;
        wagon *parent = head;
        while(temp->left!=NULL){
            parent=temp;
            temp = head->left;
        }
        if(temp==head) head = head->right;
        parent->left  = NULL;
        int data = temp->data;
        delete temp;
        total--;
        return data;
    }

    int detachWagonFromRight()
    {
        if(head==NULL) return 0;
        wagon *temp = head;
        wagon *parent = head;
        while(temp->right!=NULL){
            parent=temp;
            temp = head->right;
        }
        if(temp==head) head = head->left;
        parent->right = NULL;
        int data = temp->data;
        delete temp;
        total--;
        return data;
    }
private:
    wagon* head;
    int total;
};

#ifndef RunTests
int main()
{
    TrainComposition train;
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    std::cout << train.detachWagonFromRight() << "\n"; // 7 
    std::cout << train.detachWagonFromLeft(); // 13
}
#endif