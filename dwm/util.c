/* See LICENSE file for copyright and license details. */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include "util.h"
void
hexToVec3(const char* hex, float out_vec3[3]) {
	if (hex[0] == '#') {
		hex++;
	}

	uint rgb;
	sscanf(hex, "%06x", &rgb);

	out_vec3[0] = ((rgb >> 16) & 0xFF) / 255.0f;
	out_vec3[1] = ((rgb >> 8)  & 0xFF) / 255.0f;
	out_vec3[2] = (rgb         & 0xFF) / 255.0f;
}
double
get_time_in_seconds() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double)ts.tv_sec + (double)ts.tv_nsec / 1000000000.0;
}
void
die(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
		fputc(' ', stderr);
		perror(NULL);
	} else {
		fputc('\n', stderr);
	}

	exit(1);
}

void *
ecalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!(p = calloc(nmemb, size)))
		die("calloc:");
	return p;
}
