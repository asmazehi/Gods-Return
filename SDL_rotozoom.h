/*  
00002 
00003 SDL_rotozoom.c: rotozoomer, zoomer and shrinker for 32bit or 8bit surfaces
00004 
00005 Copyright (C) 2001-2012  Andreas Schiffler
00006 
00007 This software is provided 'as-is', without any express or implied
00008 warranty. In no event will the authors be held liable for any damages
00009 arising from the use of this software.
00010 
00011 Permission is granted to anyone to use this software for any purpose,
00012 including commercial applications, and to alter it and redistribute it
00013 freely, subject to the following restrictions:
00014 
00015 1. The origin of this software must not be misrepresented; you must not
00016 claim that you wrote the original software. If you use this software
00017 in a product, an acknowledgment in the product documentation would be
00018 appreciated but is not required.
00019 
00020 2. Altered source versions must be plainly marked as such, and must not be
00021 misrepresented as being the original software.
00022 
00023 3. This notice may not be removed or altered from any source
00024 distribution.
00025 
00026 Andreas Schiffler -- aschiffler at ferzkopp dot net
00027 
00028 */
 
 #ifndef _SDL_rotozoom_h
 #define _SDL_rotozoom_h
 
 #include <math.h>
 
 /* Set up for C function definitions, even when using C++ */
 #ifdef __cplusplus
 extern "C" {
 #endif
 
 #ifndef M_PI
 #define M_PI    3.141592654
 #endif
 
 //#include "SDL.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
 
         /* ---- Defines */
 
 #define SMOOTHING_OFF           0
 
 #define SMOOTHING_ON            1
 
         /* ---- Function Prototypes */
 
 #ifdef _MSC_VER
 #  if defined(DLL_EXPORT) && !defined(LIBSDL_GFX_DLL_IMPORT)
 #    define SDL_ROTOZOOM_SCOPE __declspec(dllexport)
 #  else
 #    ifdef LIBSDL_GFX_DLL_IMPORT
 #      define SDL_ROTOZOOM_SCOPE __declspec(dllimport)
 #    endif
 #  endif
 #endif
 #ifndef SDL_ROTOZOOM_SCOPE
 #  define SDL_ROTOZOOM_SCOPE extern
 #endif
 
         /* 
 
         Rotozoom functions
 
         */
 
         SDL_ROTOZOOM_SCOPE SDL_Surface *rotozoomSurface(SDL_Surface * src, double angle, double zoom, int smooth);
 
         SDL_ROTOZOOM_SCOPE SDL_Surface *rotozoomSurfaceXY
                 (SDL_Surface * src, double angle, double zoomx, double zoomy, int smooth);
 
 
         SDL_ROTOZOOM_SCOPE void rotozoomSurfaceSize(int width, int height, double angle, double zoom, int *dstwidth,
                 int *dstheight);
 
         SDL_ROTOZOOM_SCOPE void rotozoomSurfaceSizeXY
                 (int width, int height, double angle, double zoomx, double zoomy, 
                 int *dstwidth, int *dstheight);
 
         /* 
 
         Zooming functions
 
         */
 
         SDL_ROTOZOOM_SCOPE SDL_Surface *zoomSurface(SDL_Surface * src, double zoomx, double zoomy, int smooth);
 
         SDL_ROTOZOOM_SCOPE void zoomSurfaceSize(int width, int height, double zoomx, double zoomy, int *dstwidth, int *dstheight);
 
         /* 
 
         Shrinking functions
 
         */     
 
         SDL_ROTOZOOM_SCOPE SDL_Surface *shrinkSurface(SDL_Surface * src, int factorx, int factory);
 
         /* 
 
         Specialized rotation functions
 
         */
 
         SDL_ROTOZOOM_SCOPE SDL_Surface* rotateSurface90Degrees(SDL_Surface* src, int numClockwiseTurns);
 
         /* Ends C function definitions when using C++ */
 #ifdef __cplusplus
 }
 #endif
 
 #endif                          /* _SDL_rotozoom_h */
