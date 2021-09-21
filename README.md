# Fract-ol

## How to create the program?

This version is made for running only in `MACOS`. Several changes has to be done to run on Linux.
You can simply run `make` in order to create the executable `fractol`

## How to run the program?

You can run a list of fractals using the sintax `./fractol [name]`
The program accepts the following commands:

```
	./fractol mandelbrot
	./fractol julia
	./fractol burningship
	./fractol perpendicular_burningship
	./fractol mandelbar
	./fractol celtic_mandelbar
	./fractol celtic_perpendicular
	./fractol perpendicular_buffalo
```
Another input different of those should print this exact list in the terminal and quit appropriately

![alt text](images/wrong_parameters.png)

## Controls

After the fractal is displayed, you can use several keys to interact with it:

* `ARROWS / WASD: MOVE` Translate your image.
* `M: MENU` Toggle menu on/off
* `L: LOCK MOUSE` Lock/unlock mouse coordinates to control Julia Set Parameters
* `C: COLORS` Change color palettes
* `F: FRACTALS` Change fractal algorithm
* `R: RESET` Reset all parameters to default values
* `+/-: ITERATIONS` Increase/Descrease iteration limit of algorithm
* `MW: ZOOM` Mouse Wheel controls the zoom (following its position)
* `M1: JULIA PARAMS` Click with mouse left bottom to set Julia Set Parameters (when `LOCK MOUSE` is off)
* `P: PSYCHEDELIC` Toggle Psychedelic mode [maybe too much]
* `SHIFT: SHIFT COLOR` Shift colors forward
* `Z: MOUSE ITER` Zoom of mouse also increase/decrease iterations by 1. Perfect to give feeling of infinity zoom. Better if using `WINDOW_SIZE` less than 300.
* `ESC: QUIT` Quit program appropriately.

## Samples

### Mandelbrot
![alt text](images/mandelbrot.png)

### Julia
![alt text](images/julia.png)

### Burningship
![alt text](images/burningship.png)

### Perpendicular Burningship
![alt text](images/perpendicular_burningship.png)

### Mandelbar
![alt text](images/mandelbar.png)

### Celtic Mandelbar
![alt text](images/celtic_mandelbar.png)

### Celtic Perpendicular
![alt text](images/celtic_perpendicular.png)

### Perpendicular Buffalo
![alt text](images/perpendicular_buffalo.png)

### Mandelbrot with menu and psychedelics on
![alt text](images/mandelbrot_menu_psychedelic.png)

### Julia with other parameters and colors
![alt text](images/another_julia.png)

### Another burninship with psychedelic colors
![alt text](images/another_burningship.png)