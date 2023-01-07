#include<iostream>

class Player{
    public:
     int x;
     int y;
     int speed;

     void Move(int xa,int ya)
     {
        x+=xa;
        y+=ya;
     }
};

int main()
{
    Player player;
    player.Move(1,-1);
}