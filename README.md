### corne_keymap

My personal keymap for the corne keyboard.

[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)


#### Install

Copy this repo in the folder :

    ~/qmk_firmware/keyboards/crkbd/

#### Compile and flash

Change the master in the config.h file :

    // #define MASTER_LEFT
    #define MASTER_RIGHT

then :

    qmk compile && qmk flash -bl dfu

Or outside the folder :

    qmk compile -kb crkbd/rev1 -km corne_keymap && qmk flash -kb crkbd/rev1 -km corne_keymap -bl dfu

#### Links

[qmk](https://docs.qmk.fm/#/)  
[foostan](https://github.com/foostan/crkbd)


#### Keymap

All french letters are print with unicode.
Use the standard us keymap :

    setxkbmap -layout us


#### Combos


|     French       |                        |
|------------------|------------------------|
|   g + r + a      |   à                    |
|   g + r + e      |   è                    |
|   g + r + u      |   ù                    |
|   é + c          |   ç                    |
|   é + a          |   æ                    |
|   é + o          |   œ                    |
|   c + r + a      |   â                    |
|   c + r + e      |   ê                    |
|   c + r + i      |   î                    |
|   c + r + o      |   ô                    |
|   t + r + e      |   ë                    |
|   t + r + i      |   ï                    |
|   t + r + u      |   ü                    |
|   t + r + y      |   ÿ                    |

|      Keys        |                        |
|------------------|------------------------|
|   mouse + arrows |   adjust               |
|   arrows + f     |   fn                   |
|   a + t          |   @                    |
|   c + r          |   ^                    |
|   g + r          |   \`                   |
|   d + '          |   "                    |
|   h + s          |   #                    |
|   a + p          |   &                    |
|   p + e          |   \|                   |
|   s + l          |   /                    |
|   d + r          |   \                    |
|   t + d          |   ~                    |
|   s + r          |   _                    |
|   t + r          |   -                    |
|   p + l          |   +                    |
|   e + q          |   =                    |
|   p + c          |   %                    |
|   s + t          |   *                    |
|   enter + s      |   shifted enter        |
|   d + l          |   $                    |
|   e + r          |   €                    |
|   p + d          |   £                    |

|     Special      |                        |
|------------------|------------------------|
|   d + g + r      |   °                    |
|   ^ + 1          |   ¹                    |
|   ^ + 2          |   ²                    |
|   ^ + 3          |   ³                    |


#### Layouts

![base](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/base.png "layout")  
![numeric](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/numeric.png "layout")  
![mouse](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/mouse.png "layout")  
![arrows](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/arrows.png "layout")  
![adjust](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/adjust.png "layout")  
![fn](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/fn.png "layout")  
