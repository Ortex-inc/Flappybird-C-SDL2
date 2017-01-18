#ifndef SOUND_H
#define SOUND_H
#include <SDL2/SDL_mixer.h>

//decalre
Mix_Music *music = NULL;
Mix_Chunk *fx = NULL;


void soundTrack(const char* src){
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
//Initialisation de l'API Mixer

   {

      printf("%s", Mix_GetError());

   }
	   music = Mix_LoadMUS(src);
	   Mix_PlayMusic( music, -1 );

	 }

void effect(const char* src){
fx= Mix_LoadWAV( src );
if(Mix_PlayChannel( -1, fx, 0 )){
 printf("%s", Mix_GetError());
};

}
#endif
