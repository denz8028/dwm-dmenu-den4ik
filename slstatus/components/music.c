#include <stdio.h>
#include <time.h>
#include <playerctl/playerctl.h>
#include <string.h>
#include "../slstatus.h"
#include "../util.h"
#include "glib.h"
char buff[4096];
char now[128];
const char* get_artist(const char *unused) {
    GError *error = NULL;
    PlayerctlPlayer* player = playerctl_player_new(NULL, &error);
    if (strcmp(now, playerctl_player_get_title(player, &error)) != 0)
    {
        strcpy(now, playerctl_player_get_title(player, &error));
        snprintf(buff, sizeof(buff), "Now playing: %s - %s", playerctl_player_get_artist(player, &error), playerctl_player_get_title(player, &error));
    }
    return buff;
}
