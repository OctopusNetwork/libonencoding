#ifndef __OCNET_JSON____H__
#define __OCNET_JSON____H__

#ifdef __cplusplus
extern "C" {
#endif

void    *ocnet_json_init(char *json);

int      ocnet_json_get_item_int(void *ocnet_json, char *key, int *value);
int      ocnet_json_get_item_bool(void *ocnet_json, char *key, char *value);
int      ocnet_json_get_item_string(void *ocnet_json, char *key, char *str, int max_len);

void     ocnet_json_final(void *ocnet_json);

#ifdef __cplusplus
}
#endif

#endif
