# so_long
42 so_long

A small 2D game developed in C using the MiniLibX graphics library. The objective is to guide a character through a maze, collecting items and reaching the exit while avoiding obstacles.

## Overview

`so_long` is a basic top-down 2D game where the player controls a main character on a map. The game engine handles window management, event handling (keyboard input), and texture rendering. The goal is to collect all collectibles on the map and escape through the exit in the minimum number of moves.

## Gameplay

* **Objective:** Collect all items (`C`) and reach the exit (`E`).
* **Controls:**
	* `W`, `A`, `S`, `D` (or Arrow Keys): Move the character (Up, Left, Down, Right).
	* `ESC`: Close the window and quit the game.
	* Clicking the red cross on the window frame also exits the game.
* **Map Elements:**
	* `1`: Wall (impassable).
	* `0`: Empty space (walkable).
	* `P`: Player starting position.
	* `C`: Collectible item.
	* `E`: Exit (opens only after collecting all items).
	* `M`: Enemy (kills the player on contact).

## Map Configuration

The game loads the map from a `.ber` file. The map must be rectangular and surrounded by walls.
Example of a valid map file (`map.ber`):

```text
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111