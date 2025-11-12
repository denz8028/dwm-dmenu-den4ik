/* See LICENSE file for copyright and license details. */

/* battery */
const char *battery_perc(const char *);
const char *battery_remaining(const char *);
const char *battery_state(const char *);

/* cat */
const char *cat(const char *path);

/* cpu */
const char *cpu_freq(const char *unused);
const char *cpu_perc(const char *unused);

/* datetime */
const char *datetime(const char *fmt);
const char *datetime_dayoftheweek(const char *unused);
/* disk */
const char *disk_free(const char *path);
const char *disk_perc(const char *path);
const char *disk_total(const char *path);
const char *disk_used(const char *path);

/* entropy */
const char *entropy(const char *unused);

/* hostname */
const char *hostname(const char *unused);

/* ip */
const char *ipv4(const char *interface);
const char *ipv6(const char *interface);
const char *up(const char *interface);

/* kernel_release */
const char *kernel_release(const char *unused);

/* keyboard_indicators */
const char *keyboard_indicators(const char *fmt);

/* keymap */
const char *keymap(const char *unused);

/* load_avg */
const char *load_avg(const char *unused);

/* netspeeds */
const char *netspeed_rx(const char *interface);
const char *netspeed_tx(const char *interface);

/* num_files */
const char *num_files(const char *path);

/* ram */
const char *ram_free(const char *unused);
const char *ram_perc(const char *unused);
const char *ram_total(const char *unused);
const char *ram_used(const char *unused);

/* run_command */
const char *run_command(const char *cmd);

/* swap */
const char *swap_free(const char *unused);
const char *swap_perc(const char *unused);
const char *swap_total(const char *unused);
const char *swap_used(const char *unused);

/* temperature */
const char *temp(const char *);

/* uptime */
const char *uptime(const char *unused);

/* user */
const char *gid(const char *unused);
const char *uid(const char *unused);
const char *username(const char *unused);

/* volume */
const char *vol_perc(const char *card);

/* wifi */
const char *wifi_essid(const char *interface);
const char *wifi_perc(const char *interface);
/* musuic */
const char *get_artist(const char *unused);
char buf[1024];

#define LEN(x) (sizeof(x) / sizeof((x)[0]))
void warn (const char *str, ...)
{

}
static int
evsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
    int ret;

    ret = vsnprintf(str, size, fmt, ap);

    if (ret < 0) {
        warn("vsnprintf:");
        return -1;
    } else if ((size_t)ret >= size) {
        warn("vsnprintf: Output truncated");
        return -1;
    }

    return ret;
}

int
esnprintf(char *str, size_t size, const char *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap, fmt);
    ret = evsnprintf(str, size, fmt, ap);
    va_end(ap);

    return ret;
}
const char *
bprintf(const char *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap, fmt);
    ret = evsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);

    return (ret < 0) ? NULL : buf;
}

const char *
fmt_human(uintmax_t num, int base)
{
    double scaled;
    size_t i, prefixlen;
    const char **prefix;
    const char *prefix_1000[] = { "", "k", "M", "G", "T", "P", "E", "Z",
        "Y" };
        const char *prefix_1024[] = { "", "Ki", "Mi", "Gi", "Ti", "Pi", "Ei",
            "Zi", "Yi" };

            switch (base) {
                case 1000:
                    prefix = prefix_1000;
                    prefixlen = LEN(prefix_1000);
                    break;
                case 1024:
                    prefix = prefix_1024;
                    prefixlen = LEN(prefix_1024);
                    break;
                default:
                    warn("fmt_human: Invalid base");
                    return NULL;
            }

            scaled = num;
            for (i = 0; i < prefixlen && scaled >= base; i++)
                scaled /= base;

    return bprintf("%.1f %s", scaled, prefix[i]);
}

int
pscanf(const char *path, const char *fmt, ...)
{
    FILE *fp;
    va_list ap;
    int n;

    if (!(fp = fopen(path, "r"))) {
        warn("fopen '%s':", path);
        return -1;
    }
    va_start(ap, fmt);
    n = vfscanf(fp, fmt, ap);
    va_end(ap);
    fclose(fp);

    return (n == EOF) ? -1 : n;
}
