#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    int y = 0;
    int y2 = 2.5;
    


    while (true)
    {
        auto can = Canvas(300,80);  
    
    //Símbolo
    can.DrawPointLine(150,10,150,40); 
    can.DrawPointLine(130,25,170,25);  
    can.DrawPointLine(150,10,170,10); 
    can.DrawPointLine(130,25,130,10); 
    can.DrawPointLine(150,40,130,40); 
    can.DrawPointLine(170,25,170,40);

    //Censura
    can.DrawBlockCircle(150,25,25);
    can.DrawBlockLine(130,9,170,39);
    
    
    //Cara
    can.DrawPointEllipse(20,25,2.5,y2);
    can.DrawPointEllipse(40,25,2.5,y2);
    
    can.DrawPointLine(30,30,35,35);
    can.DrawPointLine(35,35,30,35);
    can.DrawPointEllipse(30,45,10,y);
    //Radio maximo en y = 5
    //Radio en y2 = 2.5

        if(y>4){
            y=0;
            y2=0;
        }else{
            y2=2.5;
        }
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Blue,canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
        y++;
    }

    return 0;
}