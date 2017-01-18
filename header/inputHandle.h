#ifndef IPNUTHANDLE_H
#define INPUTHANDLE_H
#include "function.h"
int btnX,btnY;
int hovX,hovY;
 bool  quit=false;
 bool space_pressed=false;
 SDL_Event event;

	void input(){
	/* Check for new events */
        while(SDL_PollEvent(&event))
        {



			 switch( event.type ){

				 case SDL_QUIT:
				 quit=true;
				 break;

         case SDL_KEYDOWN:
              /* Check the SDLKey values and move change the coords */
              switch( event.key.keysym.sym ){
//REMOVABLE CODE WHEN  PORTED THIS GAME IN ANDROID OR FOR ANY TOUCH DEVICE
        case SDLK_SPACE:
                     space_pressed=true;
            }
                      break;

                      case SDL_KEYUP:
                           /* Check the SDLKey values and move change the coords */
                           switch( event.key.keysym.sym ){
             //REMOVABLE CODE WHEN  PORTED THIS GAME IN ANDROID OR FOR ANY TOUCH DEVICE
                     case SDLK_SPACE:
                                  space_pressed=false;
                         }
                                   break;



            //Key down
            case  SDL_MOUSEBUTTONUP:
  	 btnX = -1 ;
  	 btnY = -1 ;
  					break;

  					case  SDL_MOUSEBUTTONDOWN:
  		 			btnX = event.button.x ;
  	 				btnY = event.button.y ;
  					break;
				   //click event

				   default:break;

		}

	// end input
}
//TAPE SCREEN
if(0<=btnX && SCREEN_WIDTH>=btnX && 0<=btnY && SCREEN_HEIGHT>=btnY ){
  space_pressed=true;
}
else{space_pressed=false;}
}



#endif
