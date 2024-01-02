#include <stdio.h>
#include <complex.h>

// GLOBAL VARIABLES
int max_iterations = 20;
int threshold = 2.0;
int screen_width = 320;
int screen_height = 240;
double off_x = 0.0;
double off_y = 0.0;
double zoom = 1.0;

// ----- START OF VGA DRIVERS -----

// --- INSERT YOUR DRIVERS HERE ---

// ------ END OF VGA DRIVERS ------

void white_bg() {
	//White color for every pixel
	for (int x = 0; x < screen_width; x++) {
		for (int y = 0; y < screen_height; y++) {
			VGA_draw_point_ASM(x, y, 65535);
		}
	}
}

// ------- MANDELBROT CODE --------
int mandelbrot_distance(double x, double y) {
	// Inspired from https://complex-analysis.com/content/mandelbrot_set.html
    int i;
    double complex c = x + y * I;
    double complex z = 0.0 + 0.0 * I;

    for (i = 0; i < max_iterations; i++) {
        z = z * z + c;

        if (cabs(z) > threshold) {
            // Divergence - Return the iteration number
            return i;
        }
    }

    // If no divergence, it's inside the set, return max iteration number
    return max_iterations;
}

void compute_mandelbrot() {
	// Have to parse through each pixel in the screen
	for (int x = 0; x < screen_width; x++) {
		for (int y = 0; y < screen_height; y++) {
			double x_double = ((x * 1.0)/ (screen_width / 4) - 1.0 + off_x) * 1/zoom;
			double y_double = ((y * 1.0) / (screen_height / 2) - 1.0 + off_y) * 1/zoom;
			
			// Searching for possible distance between pixel & set
			int distance = mandelbrot_distance(x_double - 1.0, y_double);
			
			// Edge case - Will be white with color calculation
			if (distance == 0) { // If zero, then it's totally outside
				VGA_draw_point_ASM(x, y, 64256);
			} else if (distance == max_iterations) { // In set - Draw in black
				VGA_draw_point_ASM(x, y, 0);
			} else { // Not in set but close
				// Color is distance over the number of iterations times the color space
				// Because of floor division, we swaped the order
				int color = distance * (65535 / max_iterations);
				VGA_draw_point_ASM(x, y, color);
			}
		}
	}
}

int main() {
	white_bg();
	
	/*
	IMPORTANT
	Don't forget to edit the global variables manually if you want custom generation of the Mandelbrot set :)
	*/
	
	// Everything is accessible from global variables
	compute_mandelbrot();

    return 0;
}