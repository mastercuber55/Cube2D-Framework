#ifndef _ASTRO_H
#define _ASTRO_H

#include "raylib.h"

#ifdef _ASTRO_PHY
#	ifdef _ASTRO_IMPLEMENTATION
#		define PHYSAC_IMPLEMENTATION
#		include "physac.h"
#		undef PHYSAC_IMPLEMENTATION
#	else 
#		include "physac.h"
#	endif // _ASTRO_IMPLEMENTATION
#endif // _ASTRO_PHY

struct AstroRectangle {
	
	Rectangle Rect;
	Color RenderColor;

	#ifdef _ASTRO_PHY
		PhysicsBody PhyBody;
	#endif
};

extern bool AstroRenderLoop;													// Keep Rendering Current Scene

void AstroInit(Vector2 WindowSize, const char * WindowTitle);	// Initialize Window And Phyics And SetExitKey(KEY_NULL)
bool AstroQuit();																// Close Window And Physics

struct AstroRectangle * AstroCreateRectangle(											// Create A AstroRectangle
	Rectangle RectangleToInitalizeWith, 
	Color ColorRectangleShouldAppear
);
void AstroRenderRectangle(struct AstroRectangle * Rect);						// Render A AstroRectangle
void AstroDestroyRectangle(struct AstroRectangle * Rect);						// Destroy A AstroRectangle

#endif

#ifdef _ASTRO_IMPLEMENTATION
#undef _ASTRO_IMPLEMENTATION

bool AstroRenderLoop = false;

struct AstroRectangle * AstroCreateRectangle(Rectangle RectangleToInitalizeWith, Color ColorRectangleShouldAppear) {

	struct AstroRectangle* RectangleToReturn = (struct AstroRectangle*)malloc(sizeof(struct AstroRectangle));

	RectangleToReturn->Rect = RectangleToInitalizeWith;
	RectangleToReturn->RenderColor = ColorRectangleShouldAppear;

	#ifdef _ASTRO_PHY
	RectangleToReturn->PhyBody = CreatePhysicsBodyRectangle((Vector2){ 
		RectangleToReturn->Rect.x + RectangleToReturn->Rect.width / 2.0f, 
		RectangleToReturn->Rect.y + RectangleToReturn->Rect.height / 2.0f 
	}, 
		RectangleToReturn->Rect.width, RectangleToReturn->Rect.height, 1.0f
	);
	#endif

	return RectangleToReturn;
}
void AstroRenderRectangle(struct AstroRectangle * Rect) {
	#ifdef _ASTRO_PHY
		Rect->Rect.x = Rect->PhyBody->position.x - Rect->Rect.width / 2.0f, 
		Rect->Rect.y = Rect->PhyBody->position.y - Rect->Rect.height / 2.0f;
	#endif
	DrawRectangleRec(Rect->Rect, Rect->RenderColor);
}
void AstroDestroyRectangle(struct AstroRectangle * Rect) {
	#ifdef _ASTRO_PHY
		DestroyPhysicsBody(Rect->PhyBody);
	#endif
	free(Rect);
}

void AstroInit(Vector2 WindowSize, const char * Title) {
	InitWindow(WindowSize.x, WindowSize.y, Title);
	SetExitKey(KEY_NULL);

	#ifdef _ASTRO_PHY
		InitPhysics();
	#endif
}

bool AstroQuit() {
	#ifdef _ASTRO_PHY
		ClosePhysics();
	#endif
	CloseWindow();
	return EXIT_SUCCESS;
}

#endif // _ASTRO_IMPLEMENTATION