#ifndef __OCNET_JSON____H__
#define __OCNET_JSON____H__

struct ocnet_json;
typedef struct ocnet_json   ocnet_json_t;

#ifdef __cplusplus
extern "C" {
#endif

ocnet_json_t *ocnet_json_init(char *json);

int     ocnet_json_get_item_int(ocnet_json_t *ocnet_json, char *key, int *value);
int     ocnet_json_get_item_bool(ocnet_json_t *ocnet_json, char *key, char *value);
int     ocnet_json_get_item_string(ocnet_json_t *ocnet_json, char *key, char *str, int max_len);

void    ocnet_json_final(ocnet_json_t *ocnet_json);

#ifdef __cplusplus
}
#endif

#endif
