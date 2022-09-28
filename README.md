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

#### Combos

|      keys        |                        |
|------------------|------------------------|
|   tab + del      |   switch to us         |
|   lower + raise  |   adjust               |
|   arrows + f     |   fn (osl)             |
|   é + a          |   æ                    |
|   é + o          |   œ                    |
|   e + é          |   è                    |
|   e + a          |   à                    |
|   e + c          |   ç                    |
|   e + u          |   ù                    |
|   a + t          |   @                    |
|   c + r          |   ^                    |
|   d + '          |   "                    |
|   g + r          |   `                    |
|   h + s          |   #                    |
|   a + p          |   &                    |
|   p + e          |   pipe                 |
|   p + :          |   ;                    |
|   s + b          |   /                    |
|   d + r          |   \                    |
|   t + d          |   ~                    |
|   t + r          |   -                    |
|   s + r          |   _                    |
|   d + l          |   $                    |
|   e + r          |   €                    |
|   enter + s      |   shifted enter        |

#### Layouts

![base](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/base.png "layout")  
![lower](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/lower.png "layout")  
![raise](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/raise.png "layout")  
![mouse](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/mouse.png "layout")  
![arrows](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/arrows.png "layout")  
![adjust](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/adjust.png "layout")  
![fn](https://raw.githubusercontent.com/FLinguenheld/corne_keymap/main/images/fn.png "layout")  
