#pragma once
#include "Image.h"
#include "Ox.h"

class Converter {
private:
	Converter();
	static std::vector<std::vector<Constants::oxPixel>> createOxPixelsFromImage(Image* image);
	static std::vector<std::vector<SDL_Color>> createSdlPixelsFromOx(Ox* ox);
	static void biggest_color_range(std::vector<SDL_Color> &allPixels, int begin, int end);
	static void sort_by_color(std::vector<SDL_Color> &allPixels, int begin, int end, int which_sort);
public:
	static std::array<SDL_Color, Constants::PALETTE_SIZE> createDedicatedPalette(Image* img);

	static std::array<SDL_Color, Constants::PALETTE_SIZE> createImposedPalette();

	// with oxPixel we get 256 shades of grey
	static std::vector<std::vector<Constants::oxPixel>> createGreyScalePixels(Image *img);
	static Constants::oxPixel sdlColorToOxPixel(SDL_Color color);
	static SDL_Color oxPixelToSdlColor(Constants::oxPixel oxColor);
	static Ox convertImageToOxRawColors(Image* image);
	static Ox convertImageToOxDedicatedPalette(Image *image);
	static Ox convertImageToOxGreyScale(Image *image);
	static Image convertOxToImage(Ox* ox);
	~Converter();
};
