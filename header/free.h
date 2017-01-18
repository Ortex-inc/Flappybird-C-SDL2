
#ifndef FREE_H
#define FREE_H

void	cleanUp(){
// FREE TTF
/*TTF_CloseFont(police);
TTF_Quit();
//FREE FX

 Mix_FreeMusic( music );
  Mix_FreeChunk( fx );
  //FREE SURFACE
  
SDL_FreeSurface(bg);
*/
SDL_FreeSurface(screen);
SDL_Quit();
		}
		
		#endif
