#include "mgos.h"

void net_handler(struct mg_connection *c, int ev, void *evd, void *cb_arg) {
  if (ev == MG_EV_CONNECT && (*(int *) evd == 0)) 
    LOG(LL_INFO, ("Connected!"));
}

enum mgos_app_init_result mgos_app_init(void) {
  const char *url = "http://wikipedia.org";
  mg_connect_http(mgos_get_mgr(), net_handler, NULL, url, NULL, NULL);
  return MGOS_APP_INIT_SUCCESS;
}