#include<string>
#include<sstream>
#include<iostream>

#include"../include/linked_list.hpp"
#include"../include/vessel.hpp"

template<class T>
LinkedList<T>::LinkedList(){
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList(){

}

template<class T>
int LinkedList<T>::length(){
    return this->size;
}

template<class T>
void LinkedList<T>::add(T* object){
    Cell<T>* cell = new Cell<T>(object);

    if(this->size == 0){
        this->first = cell;
        this->last = cell;
    }
    else if(this->size > 0){
        cell->prev = this->last;
        this->last->next = cell;
        this->last = cell;
    }
    ++this->size;
}

template<class T>
T* LinkedList<T>::get(int i){
    Cell<T>* cell;
    if(i >= this->size || i < -this->size){
        return nullptr;
    }
    else{
        if(i < 0){
            i = this->size + i;
        }
        if(i <= (float)this->size/2.0){
            cell = this->from_front(i);
        }
        else{
            cell = this->from_back((this->size-i)-1);
        }
        return cell != nullptr ? cell->object : nullptr;
    }
}

template<class T>
Cell<T>* LinkedList<T>::get_cell(int i){
    Cell<T>* cell;
    if(i >= this->size || i < -this->size){
        return nullptr;
    }
    else{
        if(i < 0){
            i = this->size + i;
        }
        if(i <= (float)this->size/2.0){
            cell = this->from_front(i);
        }
        else{
            cell = this->from_back((this->size-i)-1);
        }
        return cell;
    }
}

template<class T>
Cell<T>* LinkedList<T>::from_back(int i){
    int cell_i = 0;
    for (Cell<T>* cell = this->last; cell != nullptr; cell = cell->prev, cell_i++){
        if(cell_i == i){
            return cell;
        }
    }
    return nullptr;
}

template<class T>
Cell<T>* LinkedList<T>::from_front(int i){
    int cell_i = 0;
    for (Cell<T>* cell = this->first; cell != nullptr; cell = cell->next, cell_i++){
        if(cell_i == i){
            return cell;
        }
    }
    return nullptr;
}

template<class T>
void LinkedList<T>::remove(int i){
    int cell_i = 0;
    if(i >= this->size || i < -this->size){
        return;
    }
    else if(i == 0 || i == -this->size){
        Cell<T>* cell = this->first;
        this->first = cell->next;
        delete cell->object;
        delete cell;
    }
    else if(i == this->size-1 || i == -1){
        Cell<T>* cell = this->last;
        this->last = cell->prev;
        delete cell->object;
        delete cell;
    }
    else{
        Cell<T>* cell = this->get_cell(i);
        cell->prev->next = cell->next;
        cell->next->prev = cell->prev;
        delete cell->object;
        delete cell;
    }
    --this->size;
}

template<class T>
void LinkedList<T>::print(){
    int cell_i = 0;
    for (Cell<T>* cell = this->first; cell != nullptr; cell = cell->next, cell_i++){
        std::cout << cell_i << std::endl;
    }
}

template class LinkedList<Vessel>;