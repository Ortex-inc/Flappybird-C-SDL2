#ifndef ELEMENT_H
#define ELEMENT_H
#include "inputHandle.h"
#include "sound.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Source {
	public:
	SDL_Surface *surface;

	Source(const char*src){
	surface=NULL;
	surface=IMG_Load(src);
}
}source("src/source.bmp");



class Person{
	public:
	SDL_Texture *texture;
	SDL_Rect ins,dim;
	bool crached;
	bool droped;
	int clip;
	float angle;
Person(int cutX,int cutY,int width,int height,int clip,bool crached){
	this->droped=false;
	this->crached=crached;
	this->dim.x=cutX;
	this->dim.y=cutY;
	this->dim.w=this->ins.w=width;
	this->dim.h=this->ins.h=height;
	this->clip=clip;

	texture=NULL;
		texture=SDL_CreateTextureFromSurface(screen,source.surface);


	}
	void position(int x,int y);
	void animate(float);
	void drop(void);
	void print(void);
	};

	void Person::animate(float angle){
		this->angle=angle;
		if(this->angle<=-80){droped=true;}
		else{droped=false;}
		if(dim.x+dim.w>=dim.w*clip){dim.x=0;}
		 else{
		dim.x+=dim.w;
		}
		}

		void Person::position(int x,int y){
			this->ins.x=x;
			this->ins.y=y;

			}



void Person::print(){

	this->ins.h=this->dim.h;

	this->ins.w=this->dim.w;

	 SDL_RenderCopyEx(screen, texture,&dim, &ins,this->angle,0,SDL_FLIP_NONE );
	}
//

class Button{
	public:
		SDL_Texture *texture;
		SDL_Rect ins,dim;
	bool clicked;
	int oldY;
	Button(){
		clicked=false;
		oldY=0;
		texture=SDL_CreateTextureFromSurface(screen,source.surface);

		}
		void position(int x, int y);
		void size(int cutX, int cutY,int width, int height);
		void hover(void);
		bool onClick(void);
		void print(void);
	};
	void Button::position(int x,int y){
		this->ins.x=x;
		this->ins.y=y;
		this->oldY=this->ins.y;
		}


		void Button::size(int cutX,int cutY, int width ,int height){
		this->dim.x=cutX;
		this->dim.y=cutY;
		this->dim.w=this->ins.w=width;
		this->dim.h=this->ins.h=height;


		}
		void Button::hover(){
	if(ins.x<=hovX && ins.x+dim.w>=hovX && ins.y<=hovY && ins.y+dim.h>=hovY ){
		//hover code

		}
	}
bool Button::onClick(){

	if(ins.x<=btnX && ins.x+dim.w>=btnX && ins.y<=btnY && ins.y+dim.h>=btnY ){

		clicked=true;
			this->ins.y=this->oldY-+2;
				effect("fx/hover_fx.wav");
		//MAKE ANIMATION OR SOUND WHEN BUTTON COCKED
			}
			else if (btnX==-1 && btnY==-1){clicked=false;
			this->ins.y=this->oldY-2;
		}




return clicked;
}


			void Button::print() {
				SDL_RenderCopy(screen,texture,&dim,&ins);

				}
		//map

			class  Map {
	public:
		SDL_Texture *backTexture;
		SDL_Texture *forwardTexture;
		SDL_Rect backIns,backDim;
		SDL_Rect forwardIns,forwardDim;

	Map(int backWidth , int backHeight,int forwardWidth,int forwardHeight ){

		this->backDim.w=288;
		this->backDim.h=510;
		//
			this->forwardDim.w=this->forwardIns.w=forwardWidth;
			this->forwardDim.h=this->forwardIns.h=forwardHeight;
			backIns.x=0;
			backIns.y=0;
			forwardIns.x=0;
			forwardIns.y=SCREEN_HEIGHT-forwardHeight;
			backDim.x=0;
			backDim.y=0;
			forwardDim.x=585;
			forwardDim.y=0;
			//PROPOSIONEL WHEN HAVE MULTIPL RESOLUTION
			this->backIns.h=this->backDim.h;
			this->backIns.w=SCREEN_WIDTH;
	this->forwardIns.w=forwardWidth*2;
			backTexture=SDL_CreateTextureFromSurface(screen,source.surface);


			forwardTexture=SDL_CreateTextureFromSurface(screen,source.surface);

		}
		void realView(){
			if(forwardDim.x>16+584){forwardDim.x=584;} else{forwardDim.x+=6;}

			SDL_RenderCopy(screen,backTexture,&this->backDim,&this->backIns);
			SDL_RenderCopy(screen,forwardTexture,&this->forwardDim,&this->forwardIns);

			}
	};
	class Label{
		public:
			SDL_Texture *texture;
			SDL_Rect ins,dim;
		Label(){
			texture=SDL_CreateTextureFromSurface(screen,source.surface);


			}
			void position(int x, int y);
			void size( int cutX,int cutY, int width, int height);
			void hover(void);
			void print(void);


		};
	void	Label::position(int x,int y){
			this->ins.x=x;
			this->ins.y=y;
			}
		void	Label::size( int cutX,int cutY, int width, int height){
				this->dim.x=cutX;
				this->dim.y=cutY;
				this->dim.w=this->ins.w=width;
				this->dim.h=this->ins.h=height;
				}
		void Label::print(){
			SDL_RenderCopy(screen,texture,&dim,&ins);


			}


	class Canal{
		public:
			SDL_Texture* texture;
			SDL_Rect ins,dim;
		int gap;
		Canal(){
			texture=SDL_CreateTextureFromSurface(screen,source.surface);

			}
			void position(int,int);
				void print(void);
				void free(void);
				void size(int,int,int,int);

		};

		void Canal::position(int x,int y){
			this->ins.x=x;
			this->ins.y=y;
			}
			void Canal::size(int cutX,int cutY,int width,int height){

			this->dim.x=cutX;
			this->dim.y=cutY;
			this->dim.w=this->ins.w=width;
			this->dim.h=this->ins.h=height;

}
void Canal::print(){
	SDL_RenderCopy(screen,texture,&dim,&ins);
	}


class Number{
public:
int	bestScore;
int currentScore;
Uint8 r,b,g;
const char * fontPath;
SDL_Color color;
const char * label;
char c;
int size;

SDL_Rect ins;
SDL_Surface *surface;
	TTF_Font *font;
Number(const char * label,const char * fontPath,int size ,char c){
		TTF_Init();
		font=NULL;
surface=NULL;
switch(c)
{
	case'w':
	r=255;g=255;b=255;
	break;
	case 'r':
	r=255;g=0;b=0;
	break;
	case 't':
	r=64;g=153;b=255;
	break;
	default:
	r=255;g=255;b=255;
	break;
}

SDL_Color color={r,g,b};
				this->fontPath=fontPath;
				this->label=label;
				this->size=size;
				font = TTF_OpenFont(fontPath, size);

				surface=TTF_RenderText_Solid(font,label,color);
}
void position(int,int);
void counter();
void print();
void clean(const char*);
};
void Number::position(int x,int y){
this->ins.x=x;
this->ins.y=y;
}

void Number::print(){
	this->ins.w=surface->w;
	this->ins.h=surface->h;
SDL_Texture *texture=SDL_CreateTextureFromSurface(screen,surface);
SDL_RenderCopy(screen,texture,NULL,&ins);
SDL_DestroyTexture(texture);

}

void Number::clean(const char* pt){
SDL_Color color={r,g,b};

SDL_FreeSurface(this->surface);
TTF_CloseFont(this->font);
		this->font=NULL;
				this->font = TTF_OpenFont(this->fontPath, this->size);
				surface=TTF_RenderText_Solid(this->font,pt,color);

}

class Game{
	public:
bool newGame;

	Game(){
		newGame=false;
		}
	}game;





#endif
