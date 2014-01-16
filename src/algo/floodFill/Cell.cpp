#include "Cell.h"

#define NULL 0

Cell::Cell() : m_x(0), m_y(0), m_distance(0), m_explored(false), m_prev(NULL){
    for (int i = 0; i < 4; i++){
        m_walls[i] = false;
    }
}

Cell::~Cell()
{ }

int Cell::getX(){
    return m_x;
}

int Cell::getY(){
    return m_y;
}

int Cell::getDistance(){
    return m_distance;
}

bool Cell::getExplored(){
    return m_explored;
}

Cell* Cell::getPrev(){
    return m_prev;
}

bool Cell::isWall(int direction){
    return m_walls[direction];
}

void Cell::setX(int x){
    m_x = x;
}

void Cell::setY(int y){
    m_y = y;
}

void Cell::setDistance(int distance){
    m_distance = distance;
}

void Cell::setExplored(bool explored){
    m_explored = explored;
}

void Cell::setWall(int direction, bool isWall){
    m_walls[direction] = isWall;
}

void Cell::setPrev(Cell* prev){
    m_prev = prev;
}
