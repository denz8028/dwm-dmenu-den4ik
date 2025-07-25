# my dotfiles

republished my own collection of dotfiles for dwm and dmenu in one repo.
## Mini-review

#### feh required! (for static wallpaper)
dmenu at bottom\
mod+o opens playerctl dmenu\
my own wallpaper\
catppuccin themed!!\
floating mode priority\
only 5 tags\
WAIT WHAT??? LIVE WALLPAPERS!!! (my own)

you can view a list of wallpapers in dwm/glsl/ and choose in config.h
### patches:
1. awesome taskbar
2. fullscreen fix
3. window focus fix
4. systray
5. powerline-dmenu
6. refreshrate fix
7. glx-glsl-glew-bg 

#### thanks to suckless patches!

# Depedencies
0. pkgconf and python ofc for waf buildsystem
1. dwm depedencies oviviously (libxinerama-dev libxft-dev for debian)
2. libglew and libglx

# Building:
1. clone the repo.
2. `./waf configure build`
3. `sudo ./waf install`
4. Thats it!
