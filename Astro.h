/**
 * @index	
 * 	Preprocessors
 * 	Structures
 * 	Variables
 * 	InitQuit Functions
 * 	Utility Functions
 * 	Rectangle Functions
 */

#ifndef ASTRO_H
#	define ASTRO_H

#ifndef ASTRO_MAX_TEXTURES
#	define ASTRO_MAX_TEXTURES 64
#endif

#include <stdlib.h>
#include <raylib.h>

#ifdef ASTRO_PHY
#	ifdef ASTRO_IMPLEMENTATION
#		define PHYSAC_IMPLEMENTATION
#		include <physac.h>
#		undef PHYSAC_IMPLEMENTATION
#	else 
#		include <physac.h>
#	endif // ASTRO_IMPLEMENTATION
#else

// PhysicsBody, Replacement for one defined in the physac header
typedef struct PhysicsBody {} PhysicsBody;

#endif // ASTRO_PHY

// AstroRectangle, Used for easier rectangle manipulation
typedef struct AstroRectangle {
	
	float x, y, w, h;
	double Rotation;
	unsigned int TextureIndex;

	Color Tint;
	PhysicsBody PhyBody;
} AstroRectangle;

extern bool AstroRenderLoop;
extern unsigned int AstroTexturesCount;
extern unsigned int AstroTexturesHash[ASTRO_MAX_TEXTURES];
extern Texture AstroTextures[ASTRO_MAX_TEXTURES];

#ifdef __cplusplus
	extern "C" {
#endif

void AstroInit(Vector2 WindowSize, const char * WindowTitle);
bool AstroQuit();					

unsigned int AstroHash(const char * String);

AstroRectangle AstroCreateRectangleColored(float x, float y, float w, float h, Color Tint);
AstroRectangle AstroCreateRectangleTextured(float x, float y, float w, float h, const char * TextureFile);
void AstroDrawRectangle(AstroRectangle * Rect);

#ifdef __cplusplus
	}
#endif
	
#endif

#ifdef ASTRO_IMPLEMENTATION
#undef ASTRO_IMPLEMENTATION

bool AstroRenderLoop = false;
unsigned int AstroTexturesCount = 0;
unsigned int AstroTexturesHash[ASTRO_MAX_TEXTURES] = { 0 };
Texture AstroTextures[ASTRO_MAX_TEXTURES] = { 0 };

void AstroInit(Vector2 WindowSize, const char * Title) {
	InitWindow(WindowSize.x, WindowSize.y, Title);

	#ifdef ASTRO_PHY
		InitPhysics();
	#endif

	SetExitKey(KEY_NULL);
}
bool AstroQuit() {

	#ifdef ASTRO_PHY
		ClosePhysics();
	#endif
	CloseWindow();
	return false; // EXIT_SUCCESS
}

unsigned int AstroHash(const char * String) {
    unsigned int hash = 5381;
    int c;
    while ((c = *String++) != '\0') hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

AstroRectangle AstroCreateRectangleColored(float x, float y, float w, float h, Color Tint) {
	#ifdef ASTRO_PHY
		PhysicsBody PhyBody = CreatePhysicsBodyRectangle((Vector2){ x + w / 2.0f, y + h / 2.0f }, w, h, 1.0f);
	#else
		PhysicsBody PhyBody;
	#endif

	return (AstroRectangle){
		.x = x, 
		.y = y, 
		.w = w,
		.h = h, 
		.Rotation = 0, 
		.TextureIndex = 4294967295, 
		.Tint = Tint, 
		.PhyBody = PhyBody
	};
}
AstroRectangle AstroCreateRectangleTextured(float x, float y, float w, float h, const char * TextureFile) {

	#ifdef ASTRO_PHY
		PhysicsBody PhyBody = CreatePhysicsBodyRectangle((Vector2){ x + w / 2.0f, y + h / 2.0f }, w, h, 1.0f);
	#else
		PhysicsBody PhyBody;
	#endif

	AstroRectangle Rect = AstroCreateRectangleColored(x, y, w, h, WHITE);
	Rect.PhyBody = PhyBody;

	bool Found = false;

	for(int i = 0; i < AstroTexturesCount; i++) 
		if(AstroHash(TextureFile) == AstroTexturesHash[i]) {
			Found = true;
			Rect.TextureIndex = i;
			break;
		}

	if(Found) return Rect;


	Image Image2D = LoadImage(TextureFile);
	Rect.TextureIndex = AstroTexturesCount;
	AstroTextures[AstroTexturesCount] = LoadTextureFromImage(Image2D);
	AstroTexturesHash[AstroTexturesCount] = AstroHash(TextureFile);
	AstroTexturesCount++;
	UnloadImage(Image2D);

	return Rect;
}
void AstroDrawRectangle(AstroRectangle * Rect) {
	#ifdef ASTRO_PHY
		Rect->x = Rect->PhyBody->position.x - Rect->w / 2.0f,
		Rect->y = Rect->PhyBody->position.y - Rect->h / 2.0f;
	#endif
	if(Rect->TextureIndex == 4294967295) DrawRectangle(Rect->x, Rect->y, Rect->w, Rect->h, Rect->Tint);
	else DrawTexturePro(
		AstroTextures[Rect->TextureIndex], 
		(Rectangle){ 0, 0, Rect->w, Rect->h }, 
		(Rectangle){ Rect->x + Rect->w / 2.0f, Rect->y + Rect->h / 2.0f, Rect->w, Rect->h }, 
		(Vector2){ Rect->w / 2.0f, Rect->h / 2.0f }, 
		Rect->Rotation, 
		Rect->Tint
	);
}

#endif // ASTRO_IMPLEMENTATION