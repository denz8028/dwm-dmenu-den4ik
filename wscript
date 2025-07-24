#!/usr/bin/env python


top = '.'
out = 'build_directory'

def configure(ctx):
    ctx.load('compiler_c')
    ctx.load('gnu_dirs')
    ctx.check_cc(msg="Checking for C compiler", mandatory=True)
    ctx.check_cfg(package='x11', uselib_store='X11', args=['--cflags', '--libs'])
    ctx.check_cfg(package='xinerama', uselib_store='XINER', args=['--cflags', '--libs'])
    ctx.check_cfg(package='xft', uselib_store='XFT', args=['--cflags', '--libs'])
    ctx.check_cfg(package='fontconfig', uselib_store='FTCFG', args=['--cflags', '--libs'])
    ctx.recurse('dwm')
    ctx.recurse('dmenu')
    ctx.recurse('slstatus')
    ctx.recurse('fonts')
def options(opt):
    opt.load("compiler_c")
    # opt.check_cc()
def build(ctx):
    ctx.recurse('dwm')
    ctx.recurse('dmenu')
    ctx.recurse('slstatus')
    ctx.recurse('fonts')
