# Fractal Generation Using Inline Assembly and C language
This code uses inline ARM assembly with C to generate images of the Mandelbrot set given specific parameters. It has no specific use apart of simply being pleasing to watch!

#### ***NOTE***
The code is incomplete, as the drivers are part of a school project. It will not be published publicly to avoid plagiarism by other students. It can be requested privately by [email here.](mailto:mathias@pachecolemina.com?subject=[GitHub]%20Source%20Han%20Sans)

## Goal
- Push the concepts learned in class (*ECSE 324*) a little bit further by reusing the drivers created in an other context.
- Learn about the mathematical aspects behind the generation of the Mandelbrot set.

## Technology Used
- C language
- Inline Assembly (*ARM*)
- CPUlator with ARMv7 DE1-SoC processor

## Useful Links
- Mathematical information: https://en.wikipedia.org/wiki/Mandelbrot_set
- Simplified version of math + pseudo-code: https://complex-analysis.com/content/mandelbrot_set.html and his author [Juan Carlos Ponce Campuzano](https://github.com/jcponce)
- DE1-Soc documentation: https://ftp.intel.com/Public/Pub/fpgaup/pub/Intel_Material/18.1/Computer_Systems/DE1-SoC/DE1-SoC_Computer_ARM.pdf

## Results
You can find here some images generated using this tool. Given the dimensions of the simulated VGA screen, the resolution is capped at 320 pixels width by 240 pixels height.

**Image 1 - Complete set**<br>
![alt text](https://github.com/mathias-pl/fractals-with-ARM/blob/main/full_mandelbrot_30iterations.png?raw=true)<br>

**Image 2 - Set zoomed in at 5x**<br>
![alt text](https://github.com/mathias-pl/fractals-with-ARM/blob/main/zoomed_mandelbrot_15iterations.png?raw=true)<br>

**Image 3 - Set zoomed in at 10x**<br>
![alt text](https://github.com/mathias-pl/fractals-with-ARM/blob/main/zoomed_mandelbrot_50iterations.png?raw=true)<br>
