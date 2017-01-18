#include <iostream>

#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "header/screen.h"
#include "header/function.h"
using namespace std;
/////////////////////////////////////////////////////////////////:

  int main( int argc, char* args[] ) {
	  clock_t begin_time=clock();
	   clock_t end_time;
// do something


setScreen("Flappy bird");
game=Game();
bird.push_back(Person(2,980,40,25,3,false));
if(number.empty()){
number.push_back(Number(" ","font/font.ttf",60,'c'));
 number[0].position(10,0);
}
map.push_back(Map(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_WIDTH,110));


Label logo =Label ();
logo.size(700,180,180,50);
logo.position(SCREEN_WIDTH/2-logo.dim.w/2,20);
soundTrack("sounds/funny.mp3");


bird[0].position(SCREEN_WIDTH/3,SCREEN_HEIGHT/3);


//CANALS
	down.push_back(Canal());
	up.push_back(Canal());
	down.push_back(Canal());
	up.push_back(Canal());

	init_Canal();



	bird[0].dim.x=0;bird[0].dim.y=980;bird[0].dim.w=56; bird[0].dim.h=30;

	while(!quit){
	start=SDL_GetTicks();
	input();
	map[0].realView();


// IN GAME
if(!game.newGame){
		logo.print();
		menu();
		nG();

		}

	if(game.newGame){


	button[0].ins.x=-1;
		button[1].ins.x=-1;


		if(space_pressed){
				    begin_time = clock();
			bird[0].ins.y-=45;
			space_pressed=false;}
   number[0].position(10,0);
   //
  if(!exec){number[0].currentScore=0;exec=true;}
      score.str("");
     score<<number[0].currentScore;

	  //////////
		moveCanal();

		if(!bird[0].crached){


		up[0].ins.x-=6;
		down[0].ins.x-=6;
		up[1].ins.x-=6;
		down[1].ins.x-=6;
			bird[0].ins.y+=6;



	}
	for(int inc=0;inc<=1;inc++){
		if(bird[0].ins.x>=down[inc].ins.x+down[inc].dim.w && bird[0].ins.x-down[inc].ins.x-down[inc].dim.w <=5 ){
			if(bird[0].ins.x>=up[inc].ins.x+up[inc].dim.w)
			{
				if(!bird[0].crached){
				number[0].currentScore++;



			}
			}
			}
		}
				bird[0].print();
		/////////////////////DETECT CRASH////////////
			if(bird[0].crached){
				if(bird[0].ins.y+bird[0].dim.h<map[0].forwardIns.y){

					bird[0].dim.x=210;bird[0].dim.y=970;bird[0].dim.w=40; bird[0].dim.h=42;
					bird[0].ins.y+=30;

					}

				//ASSIGNED SCORE
				number[0].counter();
				//GAME OVER AND SCORE TABLE

				etat();
				menu();
				stat[1].print();
				stat[3].print();
				scoreTable();
				//PROPOSED NEW GAME OR VIEW OLD SCORES//
				if(nG()){


					bird[0].dim.x=0;bird[0].dim.y=980;bird[0].dim.w=56; bird[0].dim.h=30;


				number[0].currentScore=0;
				init_Canal();moveCanal();}
				///////

				} else{ if(interval<=0.10){
					bird[0].droped=false;
					bird[0].angle=-20.0;


					bird[0].animate(bird[0].angle);
					}

					else if(interval>0.10 && interval<=0.15){
					bird[0].ins.y+=15;
					bird[0].angle+=10;
					}
					else if (interval>0.15){
						bird[0].ins.y+=25;
							bird[0].angle+=14;
							bird[0].animate(bird[0].angle);
						bird[0].droped=true;
						}

						if(bird[0].angle<=-90){bird[0].angle=-90;}
				}
		number[0].print();
		number[0].clean(score.str().c_str());
	}

				//////////////////////////////////////

	//CHRONO;
			end_time = clock();
		interval=float( end_time - begin_time ) / CLOCKS_PER_SEC;
//effect("fx/hover_fx.wav");
update();
}

    return 0;
    }
