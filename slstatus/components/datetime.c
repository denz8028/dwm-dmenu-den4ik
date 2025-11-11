/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <time.h>

#include "../slstatus.h"
#include "../util.h"

const char *
datetime(const char *fmt)
{
	time_t t;

	t = time(NULL);
	if (!strftime(buf, sizeof(buf), fmt, localtime(&t))) {
		warn("strftime: Result string exceeds buffer size");
		return NULL;
	}

	return buf;
}
int dayofweek(time_t now, int tz_offset) {
	// Calculate number of seconds since midnight 1 Jan 1970 local time
	time_t localtime = now + (tz_offset * 60 * 60);
	// Convert to number of days since 1 Jan 1970
	int days_since_epoch = localtime / 86400;
	// 1 Jan 1970 was a Thursday, so add 4 so Sunday is day 0, and mod 7
	int day_of_week = (days_since_epoch + 4) % 7;

	return day_of_week;
}
const char *
datetime_dayoftheweek(const char *unused)
{
	time_t t = time(NULL);
	int dotw = dayofweek(t, -7);
	switch (dotw) {
		case 0:
			return "SUNDAY";
		case 1:
			return "MONDAY";
		case 2:
			return "TUESDAY";
		case 3:
			return "WEDNESDAY";
		case 4:
			return "THURSDAY";
		case 5:
			return "FRIDAY";
		case 6:
			return "SATURDAY";
	}
	return "idk lol";
}
