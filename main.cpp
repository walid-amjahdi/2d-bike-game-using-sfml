#include "sprites.h"
#include "game.h"
#include "menu.h"
#include "tutorial.h"
#include "aboutPage.h"

int main()
{
    int times = 0;
    menu :
    switch (menu()) 
    {
    case 0 :
        goto end;
    break;
    case 1 :
        if (times < 1) 
        {
            ++times;
            story();
        }

    start:  
        switch (startGame())
        {
        case 0 :
            goto menu; 
        break;
        case 1 :
            goto start;
        break; 
        case 2 :
            switch (winingWindow())
            {
            case 0 :
                goto menu;
                break;
            case 1:
                start2 :
                switch (level2())
                {
                case 0 :
                    goto menu;
                    break;
                case 1 :
                    goto start2;
                    break;
                }
            }
        break;
        }
    break;
    case 2 :
        About();
        goto menu;
    break;
    }

    end :
    return 0;
}