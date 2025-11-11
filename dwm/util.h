/* See LICENSE file for copyright and license details. */

#define MAX(A, B)               ((A) > (B) ? (A) : (B))
#define MIN(A, B)               ((A) < (B) ? (A) : (B))
#define BETWEEN(X, A, B)        ((A) <= (X) && (X) <= (B))

void die(const char *fmt, ...);
void hexToVec3(const char* hex, float out_vec3[3]);
double get_time_in_seconds();
void *ecalloc(size_t nmemb, size_t size);
