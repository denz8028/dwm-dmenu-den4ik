/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=10"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#bbbbbb", "#222222" },
	[SchemeSel] = { "#eeeeee", "#005577" },
	[SchemeOut] = { "#000000", "#00ffff" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Powerline options, one of:
 *    PwrlNone, PwrlRightArrow, PwrlLeftArrow, PwrlForwardSlash or PwrlBackslash */
static int powerline = PwrlNone;
/* By default the powerline separator will take up the full space between dmenu items.
 * This option allows for the size to be reduced by a number of pixels, e.g. a value of 3
 * will shave off three pixels on each side of the separator. This can be used to adjust
 * the angle of a powerline slash or arrow. */
static int powerline_size_reduction_pixels = 0;
