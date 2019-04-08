
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "animation.h"

int main()
{  personnage joueur;
   Imm ecran,bg;
   SDL_Event event;
   SDL_Init(SDL_INIT_EVERYTHING);
	int done=0;
	int test=0;
   	int i;
     timer t;
    t.start=0;
    t.end=0;
    t.diff=0;
   init(&joueur,&ecran,&bg); 
   ecran.srf = SDL_SetVideoMode(640, 480, 32, SDL_DOUBLEBUF); 
   load(&joueur,&bg);
   SDL_EnableKeyRepeat(100, 100);
  SDL_WM_SetCaption( "..perso animation..", NULL );
  while(!done)
{  
   t.start=SDL_GetTicks();
   display(&joueur,&ecran,&bg,&test);
   done= check_input(event,&test,done,&ecran,&joueur);
   t.end=SDL_GetTicks(); 
 t.diff+=t.end-t.start;
if(t.diff>=100 && (test==1 || test==2))
{
  t.diff=0;
  joueur.current_frame++;
}
}
for(i=1;i<14;i++){
SDL_FreeSurface(joueur.surface[i]);
} 
SDL_FreeSurface(joueur.surface[0]);
SDL_FreeSurface(bg.srf); 
SDL_Quit();


return 0;
}
