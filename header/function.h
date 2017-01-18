#ifndef FUNCTION_H
#define FUNCTION_H
#include "element.h"
#include <SDL2/SDL.h>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;
std::vector<Label> stat;
std::vector <Button> button;
std::vector <Map> map;
std::vector <Person> bird;
std::vector <Number> number;
std::vector <Number> mini;
std::vector <Label> badge;

std::vector<Canal> up;
std::vector<Canal> down;




	int cutu=0;
int cutd=0;
int d=0;
int u=0;
int tmp=0;
float interval=0.0;
int space=200;
bool exec=false;

bool newscore=false;

 std::string line;
  std::ofstream edit;
  std:: fstream read;
std::ostringstream score;
std::ostringstream var;




	 void menu(){
if(button.empty()){
	button.push_back(Button());
	button.push_back(Button());

	button[0].size(700,232,120,70);


	//
	button[1].size(820,232,120,70);


}

	button[0].position(0,SCREEN_HEIGHT-button[0].dim.h*2);
		button[1].position(SCREEN_WIDTH-button[1].dim.w,SCREEN_HEIGHT-button[1].dim.h*2);


	button[0].onClick();
	button[0].print();
		button[1].onClick();
		button[1].print();




		 }
	void etat(){
		///////////////STAT////////////////
		if(stat.empty()){
		stat.push_back(Label());
stat.push_back(Label());
stat.push_back(Label());
stat.push_back(Label());

//GZT READY
stat[0].size(590,115,192, 60);
stat[0].position(SCREEN_WIDTH/2-stat[0].dim.w/2,SCREEN_HEIGHT/6);

//GAME OVER
stat[1].size(790,115,192, 60);
stat[1].position(SCREEN_WIDTH/2-stat[1].dim.w/2,SCREEN_HEIGHT/6);
//TAPE ON SCREEN


stat[2].size(581,170,120, 110);
stat[2].position(SCREEN_WIDTH/2-stat[2].dim.w/2,SCREEN_HEIGHT-stat[2].dim.h-200);



//TABLE

stat[3].size(0,515,235,125);
stat[3].position(SCREEN_WIDTH/2-stat[3].dim.w/2,SCREEN_HEIGHT-350);
}


//////////////////////////////////

}
void tunnel(short gap){
u=0;d=0;cutu=0;
	srand(time(NULL));
	 u =rand() % 180 +20;

	 cutu=970-u;


 d=SCREEN_HEIGHT-(110+gap+u);

	}




		void	scoreTable(){
			if(mini.empty()){


		mini.push_back(Number("0","font/font.ttf",25,'w'));
			mini.push_back(Number("0","font/font.ttf",25,'w'));
			mini.push_back(Number("NEW","font/font.ttf",22,'r'));

			badge.push_back(Label());
//CURR
		mini[0].position(stat[3].ins.x+180,stat[3].ins.y+35);
				//BEST
				mini[1].position(stat[3].ins.x+180,stat[3].ins.y+75);
	//NEW SCORE
			mini[2].position(stat[3].ins.x+130,stat[3].ins.y+75);
badge[0].position(stat[3].ins.x+30,stat[3].ins.y+44);
			}











     mini[0].print();
		 mini[0].clean(score.str().c_str());
		mini[1].print();
		mini[1].clean(var.str().c_str());

     if(newscore){mini[2].print();mini[2].clean("NEW");}
		if(tmp>0 && tmp<=25){badge[0].size(290,562,48,48);badge[0].print();
			}
		if(tmp>25 && tmp<=50){badge[0].size(290,515,48,48);badge[0].print();
			}
		if(tmp>50 && tmp<=75){badge[0].size(240,515,48,48);badge[0].print();
			}
		if(tmp>75){badge[0].size(240,562,48,48);badge[0].print();
			}


    }

    //TOD O NEW SCORE
    //DISPLAY BADGES



    /////////////////////////////////////////////
void Number::counter(){
  read.open("score.inf" , std::fstream::in);
      getline (read,line);
     bestScore=atoi(line.c_str());
		 var.str("");

      var<<bestScore;



tmp=currentScore;
 if(currentScore>atoi(line.c_str())){
	   	newscore=true;
	bestScore=currentScore;

	var.str("");
      var<<bestScore;
      read.close();
edit.open("score.inf", std::ofstream::out | std::ofstream::trunc);
	edit<<var.str();
	edit.close();
	}

}


	bool nG(){
		if(button[0].onClick()){
				//INIT NEW GAME

					bird[0].crached=false;
					down[0].position(SCREEN_WIDTH,map[0].forwardIns.y-d);
					up[0].position(SCREEN_WIDTH,0);
					bird[0].position(SCREEN_WIDTH/3,SCREEN_HEIGHT/3);


					btnX=-1;
					btnY=-1;

					map[0].realView();
					etat();
					stat[0].print();
					stat[2].print();
					button[0].clicked=false;
					SDL_RenderPresent(screen);
					SDL_Delay(600);
					newscore=false;
					game.newGame=true;
//SDL_FreeSurface(stat[0].label);

					return true;


					}
					else {return false;}
					}

					//FONCTION S CANALS
					///////////////////////////////////////::::::
					void init_Canal(){
					for (int inc=0;inc<=1;inc++){
					tunnel(110);
						down[inc].size(165,640,55,d);
						up[inc].size(110,cutu,55,u);
						down[inc].position(SCREEN_WIDTH+(space*inc),map[0].forwardIns.y-d);
						up[inc].position(SCREEN_WIDTH+(space*inc),0);
					}
							}

					//////////////////////////////////////////////////////////////
					void  moveCanal(){
					for(int inc=0;inc<=1;inc++){
								if(up[inc].ins.x<=4 && down[inc].ins.x<=4){
						up[inc].dim.x+=4;
						down[inc].dim.x+=4;
							up[inc].dim.w-=4;
						down[inc].dim.w-=4;

					}
						if( down[inc].dim.w<=4 && up[inc].dim.w<=4){
						tunnel(100);
						down[inc].size(165,640,55,d);
						up[inc].size(110,cutu,55,u);



						if(!inc){
							down[inc].position(SCREEN_WIDTH,map[0].forwardIns.y-d);
						up[inc].position(SCREEN_WIDTH,0);
						}
						if(inc==1){
							down[inc].position(SCREEN_WIDTH*2,map[0].forwardIns.y-d);
						up[inc].position(SCREEN_WIDTH*2,0);

							}
							/////////////////////////////////////////
							if((down[1].ins.x-down[0].ins.x)<space){
								down[0].ins.x=down[0].ins.x+space;
								up[0].ins.x=up[0].ins.x+space;
								}

								if((down[0].ins.x-down[1].ins.x)<space){
								down[1].ins.x=down[1].ins.x+space;
								up[1].ins.x=up[1].ins.x+space;
								}




								if((down[1].ins.x-down[0].ins.x)>space){
								down[1].ins.x=down[0].ins.x+space;
								up[1].ins.x=up[0].ins.x+space;
								}


								if((down[0].ins.x-down[1].ins.x)>space){
								down[0].ins.x=down[1].ins.x+space;
								up[0].ins.x=up[1].ins.x+space;
								}


					}



						///////////////////////////////////////////////////////////////////
							if(bird[0].ins.x+bird[0].dim.w>=up[inc].ins.x&&bird[0].ins.x<=up[inc].ins.x+up[inc].dim.w){
							if(bird[0].ins.y>=up[inc].ins.y && bird[0].ins.y<=up[0].ins.y+up[inc].dim.h ) {
								//bird.pos.y+=10;
								bird[0].crached=true;}
							}
							//worked
							if(bird[0].ins.x+bird[0].dim.w>=down[inc].ins.x&&bird[0].ins.x<=down[inc].ins.x+down[inc].dim.w){
								if(bird[0].ins.y+bird[0].dim.h>=down[inc].ins.y && bird[0].ins.y+bird[0].dim.h<=down[inc].ins.y+down[inc].dim.h ) {
								//bird.pos.y+=10;
								bird[0].crached=true;}
							}
							if(bird[0].ins.y+bird[0].dim.h>=map[0].forwardIns.y){
								//bird.pos.y+=10;
								bird[0].crached=true;
								}
								/////////////////////////////////////////////////////////////
							//////////////KEY DETECT

					up[inc].print();
					down[inc].print();


					}
					}

#endif
