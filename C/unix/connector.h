#define ANET_OK 0
#define ANET_ERR -1
#define ANET_ERR_LEN 256

#define REDIS_CLI_KEEPALIVE_INTERVAL 15 /* seconds */

int createClientSocket(const char *host, int port);
int createServerSocket(const char *host, int port);
int anetKeepAlive(char *err, int fd, int interval);
static void anetSetError(char *err, const char *fmt, ...);
